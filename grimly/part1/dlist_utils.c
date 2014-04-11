/*
** dlist_utils.c for dlist_utils.c in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Jun 14 18:55:54 2009 adrien folie
** Last update Sat Nov  7 03:25:42 2009 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"
#include "librush.h"

void		my_show_begin_dlist(t_dlist *list)
{
  t_elem	*temp;

  temp = list->begin;
  while (list->begin != NULL)
    {
      printf("x : %d\ty : %d\n", list->begin->x, list->begin->y);
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
      printf("x : %d\ty : %d\n", list->begin->x, list->begin->y);
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
      free(temp);
    }
}
