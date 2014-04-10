/*
** my_aff_sub.c for my_aff_sub.c in /u/all/folie_a/cu/rendu/c/my_select
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Tue Jun 23 00:54:14 2009 adrien folie
** Last update Tue Jul  7 16:47:59 2009 adrien folie
*/

#include "clist.h"
#include "select.h"

void		my_aff_sub(t_clist *list)
{
  t_elem	*begin;
  int		i;

  begin = list->begin;
  i = 0;
  while (i < list->taille)
    {
      if (list->begin->s == 1)
	{
	  my_putstr(list->begin->data);
	  my_putchar(' ');
	}
      ++i;
      list->begin = list->begin->prev;
    }
  list->begin = begin;
}
