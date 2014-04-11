/*
** put_in_cbuff.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:10:20 2010 adrien folie
** Last update Mon Jul  5 03:10:21 2010 adrien folie
*/

#include <stdlib.h>
#include "cbuff.h"
#include "utils.h"

void	init_cbuff(t_cbuff *cbuff)
{
  cbuff->begin = NULL;
  cbuff->end = NULL;
  cbuff->taille = 0;
}

int		put_empty_cbuff(t_cbuff *cbuff, char c)
{
  t_ebuff	*new;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->character = c;
  new->next = NULL;
  new->prev = NULL;
  cbuff->begin = new;
  cbuff->end = new;
  cbuff->taille++;
  return (0);
}

int		put_begin_cbuff(t_cbuff *cbuff, char c)
{
  t_ebuff	*new;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->character = c;
  new->next = cbuff->begin;
  new->prev = NULL;
  cbuff->begin->prev = new;
  cbuff->begin = new;
  cbuff->taille++;
  return (0);
}

int		put_end_cbuff(t_cbuff *cbuff, char c)
{
  t_ebuff	*new;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->character = c;
  new->next = NULL;
  new->prev = cbuff->end;
  cbuff->end->next = new;
  cbuff->end = new;
  cbuff->taille++;
  return (0);
}

int		put_in_cbuff(t_cbuff *cbuff, char c, int sort)
{
  int		back;

  back = 1;
  if (cbuff->taille == 0)
    back = put_empty_cbuff(cbuff, c);
  else if (sort == 1)
    back = put_end_cbuff(cbuff, c);
  else
    back = put_begin_cbuff(cbuff, c);
  return (back);
}
