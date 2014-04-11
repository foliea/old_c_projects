/*
** termcaps.c for lemipc in /u/all/folie_a/cu/public/dedern/lemipc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 21 17:14:05 2010 adrien folie
** Last update Sun May 23 21:58:51 2010 edern bienvenu
*/

#include <termcap.h>
#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "caps.h"
#include "lemipc.h"

int	my_outc(int i)
{
  if (write(1, &i, 1) == -1)
    exit(EXIT_FAILURE);
  return (i);
}

void	verif_term(void)
{
  char	bp[1024];
  char	*term;

  if ((term = getenv("TERM")) == NULL)
    aff_error("can't determine terminal");
  if (tgetent(bp, term) != 1)
    aff_error("problem with tgetent");
}

void	init_caps(t_caps *caps)
{
  char	t[4096];
  char	*area;

  area = t;
  verif_term();
  if ((caps->clstr = tgetstr("cl", &area)) == NULL)
    aff_error("tgetstr failed to load clstr");
  if ((caps->cmstr = tgetstr("cm", &area)) == NULL)
    aff_error("tgetstr failed to load cmdstr");
  caps->li = tgetnum("li");
  caps->co = tgetnum("co");
  if (caps->co < WIDTH + 1 || caps->li < HEIGHT + 1)
    aff_error("terminal too small");
  tputs(caps->clstr, 1, my_outc);
}

void			start_terminal(t_caps *caps)
{
  struct termios	init;

  if (ioctl(0, TIOCGETA, &init) == -1)
    aff_error("ioctl failed");
  if (ioctl(0, TIOCGETA, &(caps->save)) == -1)
    aff_error("ioctl failed");
  init.c_lflag &= ~(ECHO | ICANON);
  init.c_cc[VMIN] = 0;
  init.c_cc[VTIME] = 0;
  if (ioctl(0, TIOCSETA, &init) == -1)
    aff_error("ioctl failed");
}

void	end_terminal(t_caps *caps)
{
  if (ioctl(0, TIOCSETA, &(caps->save)) == -1)
    aff_error("ioctl failed");
  tputs(caps->clstr, 1, my_outc);
  exit(EXIT_SUCCESS);
}

