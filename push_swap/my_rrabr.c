/*
** my_rrabr.c for ne my_rrabr.c in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Jun 15 03:03:58 2009 adrien folie
** Last update Fri Jul  3 15:32:56 2009 adrien folie
*/

#include <stdlib.h>
#include "dlist.h"
#include "push.h"

void		my_rotate_end(t_dlist *list)
{
  t_elem	*temp;

  if (list->taille == 2)
    my_swap_first(list);
  else if (list->taille > 2)
    {
      temp = list->end;
      list->end = list->end->prev;
      list->end->next = NULL;
      temp->next = list->begin;
      list->begin->prev = temp;
      temp->prev = NULL;
      list->begin = temp;
    }
}

void	my_rrr(t_dlist *l_a, t_dlist *l_b)
{
  my_rotate_end(l_a);
  my_rotate_end(l_b);
}

void	my_rrb(__attribute__((unused)) t_dlist *l_a, t_dlist *l_b)
{
  my_rotate_end(l_b);
}

void	my_rra(t_dlist *l_a, __attribute__((unused)) t_dlist *l_b)
{
  my_rotate_end(l_a);
}
