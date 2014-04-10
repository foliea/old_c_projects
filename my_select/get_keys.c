/*
** get_keys.c for get_keys in /u/all/folie_a/cu/rendu/c/my_select
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Jul  8 18:18:25 2009 adrien folie
** Last update Tue Nov 10 18:48:45 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include <term.h>
#include <termcap.h>
#include <stdio.h>
#include "select.h"
#include "clist.h"

int	my_int_len(int *t)
{
  int	i;

  i = 1;
  while (t[i] != 0)
    ++i;
  return (i);
}

void	compare_arrow(t_clist *list, t_caps *caps, char k)
{
  if (k == caps->kdstr[2])
    my_scroll_list(list, caps, 1);
  else if (k == caps->kustr[2])
    my_scroll_list(list, caps, 0);
  else if (k == caps->krstr[2])
    my_scroll_side(list, caps, 1);
  else if (k == caps->klstr[2])
    my_scroll_side(list, caps, 0);
}

void	my_get_keys(t_clist *list, t_caps *caps)
{
  char	*buffer;
  int	nb_read;
  int	ok;

  ok = 0;
  tputs(tgoto(caps->cmstr, 0, 0), 1, my_printt);
  while (ok != 1)
    {
      buffer = malloc(512 * sizeof(*buffer));
      nb_read = read(0, buffer, 512);
      if (nb_read == 3)
	compare_arrow(list, caps, buffer[2]);
      else if (nb_read == 1)
	{
	  if (buffer[0] == 32)
	    my_subline(list, caps);
	  else if (buffer[0] == 10)
	    ok = 1;
	  else if (buffer[0] == 27)
	    {
	      tputs(caps->clstr, 1, my_printt);
	      tputs(tgoto(caps->cmstr, 0, 0), 1, my_printt);
	      tputs(caps->vestr, 1, my_printt);
	      exit(EXIT_SUCCESS);
	    }
	}
      free(buffer);
    }
  tputs(caps->clstr, 1, my_printt);
}
