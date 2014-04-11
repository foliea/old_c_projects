/*
** tlist_utils.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:11:06 2010 adrien folie
** Last update Mon Jul  5 03:11:06 2010 adrien folie
*/

#include <stdlib.h>
#include "utils.h"
#include "tlist.h"

void	init_tlist(t_tlist *list)
{
  list->begin = NULL;
  list->end = NULL;
  list->taille = 0;
}

void		put_empty_tlist(t_tlist *list, void *data)
{
  t_telem	*new;

  new = xmalloc(sizeof(*new));
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  list->begin = new;
  list->end = new;
  list->taille++;
}

void		put_begin_tlist(t_tlist *list, void *data)
{
  t_telem	*new;

  new = xmalloc(sizeof(*new));
  new->data = data;
  new->next = list->begin;
  new->prev = NULL;
  list->begin->prev = new;
  list->begin = new;
  list->taille++;
}

void		put_end_tlist(t_tlist *list, void *data)
{
  t_telem	*new;

  new = xmalloc(sizeof(*new));
  new->data = data;
  new->next = NULL;
  new->prev = list->end;
  list->end->next = new;
  list->end = new;
  list->taille++;
}

void		put_in_tlist(t_tlist *list, void *data, int sort)
{
  if (list->taille == 0)
    put_empty_tlist(list, data);
  else if (sort == 1)
    put_end_tlist(list, data);
  else
    put_begin_tlist(list, data);
}
