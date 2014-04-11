/*
** list_utils.c for list_utils in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon May 18 17:48:12 2009 adrien folie
** Last update Sat Nov  7 03:13:41 2009 adrien folie
*/

#include <stdlib.h>
#include "dlist.h"

void	my_init_dlist(t_dlist *list)
{
  list->begin = NULL;
  list->end = NULL;
  list->taille = 0;
}

int		my_put_empty_dlist(t_dlist *list, int x, int y)
{
  t_elem	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->x = x;
  new->y = y;
  new->next = NULL;
  new->prev = NULL;
  list->begin = new;
  list->end = new;
  list->taille++;
  return (0);
}

int		my_put_begin_dlist(t_dlist *list, int x, int y)
{
  t_elem	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->x = x;
  new->y = y;
  new->next = list->begin;
  new->prev = NULL;
  list->begin->prev = new;
  list->begin = new;
  list->taille++;
  return (0);
}

int		my_put_end_dlist(t_dlist *list, int x, int y)
{
  t_elem	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->x = x;
  new->y = y;
  new->next = NULL;
  new->prev = list->end;
  list->end->next = new;
  list->end = new;
  list->taille++;
  return (0);
}

void		my_put_in_dlist(t_dlist *list, int x, int y, int sort)
{
  if (list->taille == 0)
    my_put_empty_dlist(list, x, y);
  else if (sort == 1)
    my_put_end_dlist(list, x, y);
  else
    my_put_begin_dlist(list, x, y);
}
