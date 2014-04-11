/*
** list_player.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Tue Jun  1 16:40:50 2010 edern bienvenu
** Last update Wed Jun 16 02:46:34 2010 edern bienvenu
*/

#include <stdlib.h>
#include "cbuff.h"

void	*xmalloc(int size);

void	init_cbuff(t_cbuff *cbuff)
{
  cbuff->begin = NULL;
  cbuff->end = NULL;
  cbuff->taille = 0;
  cbuff->type = WAITING_STATE;
  init_queue(cbuff);
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
