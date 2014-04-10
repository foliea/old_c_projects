/*
** dlist_utils.c for dlist_utils.c in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Jun 14 18:55:54 2009 adrien folie
** Last update Tue Jul  7 16:49:01 2009 adrien folie
*/

#include <stdlib.h>
#include "clist.h"
#include "select.h"

void		my_show_begin_clist(t_clist *list)
{
  t_elem	*temp;
  t_elem	*deb;

  temp = NULL;
  deb = list->begin;
  while (temp != list->end)
    {
      temp = list->begin;
      my_putstr(list->begin->data);
      my_putchar('\n');
      list->begin = list->begin->next;
    }
  list->begin = deb;
}

void		my_show_end_clist(t_clist *list)
{
  t_elem	*temp;
  t_elem	*fin;

  temp = NULL;
  fin = list->end;
  while (temp != list->begin)
    {
      temp = list->end;
      my_putstr(list->end->data);
      my_putchar('\n');
      list->end = list->end->prev;
    }
  list->end = fin;
}

void		my_show_clist(t_clist *list, int sort)
{
  if (sort == 1)
    my_show_begin_clist(list);
  else
    my_show_end_clist(list);
}

void		my_free_clist(t_clist *list)
{
  t_elem	*temp;

  while (list->begin != NULL)
    {
      temp = list->begin;
      list->begin = list->begin->next;
      free(temp->data);
      free(temp);
    }
}
