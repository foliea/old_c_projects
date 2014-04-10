/*
** my_scroll_list.c for my_scroll_list in /u/all/folie_a/cu/rendu/c/my_select
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri Jun 19 01:16:46 2009 adrien folie
** Last update Wed Jul  8 18:09:41 2009 adrien folie
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

void    my_aff_curs(t_caps *caps, char *data)
{
  tputs(tgoto(caps->cmstr, caps->x, caps->y), 1, my_printt);
  tputs(caps->usstr, 1, my_printt);
  my_putstr(data);
  tputs(caps->uestr, 1, my_printt);
  tputs(tgoto(caps->cmstr, caps->x, caps->y), 1, my_printt);
}

void	my_re_aff(t_clist *list, t_caps *caps)
{
  if (list->begin->s == 0)
    my_putstr(list->begin->data);
  else
    {
      tputs(tgoto(caps->sostr, caps->x, caps->y), 1, my_printt);
      my_putstr(list->begin->data);
      tputs(tgoto(caps->sestr, caps->x, caps->y), 1, my_printt);
    }
}

void	my_subline(t_clist *list, t_caps *caps)
{
  if (list->begin->s == 0)
    list->begin->s = 1;
  else
    list->begin->s = 0;
  my_scroll_list(list, caps, 1);
}

void		my_scroll_list(t_clist *list, t_caps *caps, int sens)
{
  my_re_aff(list, caps);
  if (sens == 1 && caps->y < list->taille - 1 && caps->y < caps->li - 1 &&
      list->begin != list->end)
    {
      list->begin = list->begin->next;
      caps->y += 1;
    }
  else if (sens == 0 && caps->y != 0)
    {
      list->begin = list->begin->prev;
      caps->y -= 1;
    }
  my_aff_curs(caps, list->begin->data);
}

void		my_scroll_side(t_clist *list, t_caps *caps, int sens)
{
  static int	c = 0;
  int		i;

  i = 0;
  my_re_aff(list, caps);
  if (sens == 1 && caps->y < list->taille - 1 && caps->y < caps->li - 1
      && c < (my_int_len(caps->mlen) - 1) &&
      (caps->y + caps->li + c * caps->li) < list->taille)
    {
      while (i++ < caps->li)
	list->begin = list->begin->next;
      caps->x += caps->mlen[c];
      ++c;
    }
  else if (sens == 0 && caps->x > 0)
    {
      while (i++ < caps->li)
	list->begin = list->begin->prev;
      caps->x -= caps->mlen[c - 1];
      c--;
      }
  my_aff_curs(caps, list->begin->data);
}
