/*
** my_rabr.c for my_rabr.c in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Jun 15 02:48:41 2009 adrien folie
** Last update Fri Jul  3 15:33:39 2009 adrien folie
*/

#include <stdlib.h>
#include "dlist.h"
#include "push.h"

void		my_rotate_begin(t_dlist *list)
{
  t_elem	*temp;

  if (list->taille == 2)
    my_swap_first(list);
  else if (list->taille > 2)
    {
      temp = list->begin;
      list->begin = list->begin->next;
      list->begin->prev = list->begin;
      list->begin->prev = NULL;
      temp->prev = list->end;
      temp->next = NULL;
      list->end = temp;
      temp->prev->next = temp;
    }
}

void	my_rr(t_dlist *l_a, t_dlist *l_b)
{
  my_rotate_begin(l_a);
  my_rotate_begin(l_b);
}

void	my_rb(__attribute__((unused)) t_dlist *l_a, t_dlist *l_b)
{
  my_rotate_begin(l_b);
}

void	my_ra(t_dlist *l_a, __attribute__((unused)) t_dlist *l_b)
{
  my_rotate_begin(l_a);
}
