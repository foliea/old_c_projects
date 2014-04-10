/*
** my_caps.c for my_caps in /u/all/folie_a/cu/rendu/c/my_select
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Jul  8 18:17:33 2009 adrien folie
** Last update Wed Jul  8 18:42:20 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include <term.h>
#include <termcap.h>
#include <stdio.h>
#include <signal.h>
#include "select.h"
#include "clist.h"

char	*xtgetstr(char *cap, char **area)
{
  char	*capstr;

  if ((capstr = tgetstr(cap, area)) == NULL)
    {
      my_putstr("problem to get ");
      my_putstr(cap);
      my_putchar('\n');
      exit(EXIT_FAILURE);
    }
  return (capstr);
}

int	my_printt(int c)
{
  my_putchar(c);
  return (1);
}

void		winsize(__attribute__((unused)) int sig)
{
  struct winsize	w;

  if (ioctl(0, TIOCGWINSZ, &w) < 0)
    exit(EXIT_FAILURE);
}

void		my_caps_def(t_caps *caps)
{
  char		t[4096];
  char		*area;

  area = t;
  signal(SIGWINCH, winsize);
  caps->clstr = xtgetstr("cl", &area);
  caps->sostr = xtgetstr("so", &area);
  caps->sestr = xtgetstr("se", &area);
  caps->cmstr = xtgetstr("cm", &area);
  caps->kustr = xtgetstr("ku", &area);
  caps->kdstr = xtgetstr("kd", &area);
  caps->klstr = xtgetstr("kl", &area);
  caps->krstr = xtgetstr("kr", &area);
  caps->usstr = xtgetstr("us", &area);
  caps->uestr = xtgetstr("ue", &area);
  caps->vistr = xtgetstr("vi", &area);
  caps->vestr = xtgetstr("ve", &area);
  caps->li = tgetnum("li");
  caps->co = tgetnum("co");
  caps->x = 0;
  caps->y = 0;
}

void		my_while(t_caps *caps, t_clist *list)
{
  t_clist	save;

  save.begin = list->begin;
  save.end = list->end;
  save.taille = list->taille;
  tputs(caps->clstr, 1, my_printt);
  my_aff_list(&save, caps);
  my_ioctl_mod();
  tputs(caps->vistr, 1, my_printt);
  my_get_keys(&save, caps);
  tputs(caps->vestr, 1, my_printt);
  my_aff_sub(&save);
}
