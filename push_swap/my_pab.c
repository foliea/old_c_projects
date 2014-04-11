/*
** my_pab.c for my_pab.c in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Jun 15 03:15:01 2009 adrien folie
** Last update Wed Jul  1 18:38:44 2009 thibaut ottemer
*/

#include <stdlib.h>
#include "dlist.h"
#include "push.h"

void		my_a_to_b(t_dlist *a, t_dlist *b)
{
  t_elem	*temp;

  temp = a->begin;
  if (a->taille > 1)
    {
      a->begin = a->begin->next;
      a->begin->prev = NULL;
      a->taille--;
    }
  else
    my_init_dlist(a);
  if (b->taille > 0)
    {
      b->begin->prev = temp;
      temp->prev = NULL;
      temp->next = b->begin;
      b->begin = temp;
    }
  else
    {
      b->begin = temp;
      b->end = temp;
      temp->next = NULL;
      temp->prev = NULL;
    }
  b->taille++;
}

void		my_pb(t_dlist *l_a, t_dlist *l_b)
{
  if (l_a->taille > 0)
    my_a_to_b(l_a, l_b);
}

void		my_pa(t_dlist *l_a, t_dlist *l_b)
{
  if (l_b->taille > 0)
    my_a_to_b(l_b, l_a);
}
