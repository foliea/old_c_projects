/*
** dlist_utils.c for dlist_utils.c in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Jun 14 18:55:54 2009 adrien folie
** Last update Sat Jul  4 19:09:58 2009 adrien folie
*/

#include <stdlib.h>
#include "dlist.h"
#include "push.h"

void		my_show_begin_dlist(t_dlist *list)
{
  t_elem	*temp;

  temp = list->begin;
  while (list->begin != NULL)
    {
      my_putstr(list->begin->data);
      my_putchar(' ');
      list->begin = list->begin->next;
    }
  list->begin = temp;
}

void		my_show_end_dlist(t_dlist *list)
{
  t_elem	*temp;

  temp = list->end;
  while (list->end != NULL)
    {
      my_putstr(list->end->data);
      my_putchar(' ');
      list->end = list->end->prev;
    }
  list->end = temp;
}

void		my_show_dlist(t_dlist *list, int sort)
{
  if (sort == 1)
    my_show_begin_dlist(list);
  else
    my_show_end_dlist(list);
}

void		my_free_dlist(t_dlist *list)
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
