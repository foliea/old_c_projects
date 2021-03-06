/*
** list_utils.c for list_utils in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon May 18 17:48:12 2009 adrien folie
** Last update Mon Sep 28 13:53:04 2009 adrien folie
*/

#include <stdlib.h>
#include "dlist.h"

void	my_init_dlist(t_dlist *list)
{
  list->begin = NULL;
  list->end = NULL;
  list->taille = 0;
}

void		my_put_empty_dlist(t_dlist *list, char **data, char *s)
{
  t_elem	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    exit(EXIT_FAILURE);
  new->data = data;
  new->s = s;
  new->next = NULL;
  new->prev = NULL;
  list->begin = new;
  list->end = new;
  list->taille++;
}

void		my_put_begin_dlist(t_dlist *list, char **data, char *s)
{
  t_elem	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    exit(EXIT_FAILURE);
  new->data = data;
  new->s = s;
  new->next = list->begin;
  new->prev = NULL;
  list->begin->prev = new;
  list->begin = new;
  list->taille++;
}

void		my_put_end_dlist(t_dlist *list, char **data, char *s)
{
  t_elem	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    exit(EXIT_FAILURE);
  new->data = data;
  new->s = s;
  new->next = NULL;
  new->prev = list->end;
  list->end->next = new;
  list->end = new;
  list->taille++;
}

void		my_put_in_dlist(t_dlist *list, char **data, char *s, int sort)
{
  if (list->taille == 0)
    my_put_empty_dlist(list, data, s);
  else if (sort == 1)
    my_put_end_dlist(list, data, s);
  else
    my_put_begin_dlist(list, data, s);
}
