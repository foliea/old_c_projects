/*
** my_aff_list.c for my_aff_list.c in /u/all/folie_a/cu/rendu/c/my_select
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Jul  6 16:31:41 2009 adrien folie
** Last update Tue Jul  7 16:48:26 2009 adrien folie
*/

#include <stdlib.h>
#include <curses.h>
#include <ncurses.h>
#include <term.h>
#include <termcap.h>
#include "select.h"

void	my_aff_col(t_clist *list, t_caps *caps, int c, int l)
{
  int	i;
  int	temp;
  static int	j = 0;

  i = 0;
  temp = 0;
  while (i < caps->li && j < list->taille)
    {
      tputs(tgoto(caps->cmstr, c, i), 1, my_printt);
      my_putstr(list->begin->data);
      temp = my_strlen(list->begin->data);
      if (caps->mlen[l] < temp)
	caps->mlen[l] = temp + 3;
      list->begin = list->begin->next;
      j++;
      ++i;
    }
}

int	*col_len_init(t_caps *caps)
{
  int	*len;
  int	i;

  i = 0;
  len = malloc((caps->co + 1) * sizeof(*len));
  while (i < caps->co)
    {
      len[i] = 0;
      ++i;
    }
  len[i] = -1;
  return (len);
}

void		my_aff_list(t_clist *list, t_caps *caps)
{
  int		j;
  int		c;
  t_elem	*deb;

  c = 0;
  deb = list->begin;
  caps->mlen = col_len_init(caps);
  j = 0;
  while (j < caps->co)
    {
      my_aff_col(list, caps, c, j);
      c += caps->mlen[j];
      ++j;
    }
  list->begin = deb;
}
