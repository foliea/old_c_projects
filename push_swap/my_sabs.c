/*
** my_sabs.c for my_sabs.c in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Jun 15 02:31:30 2009 adrien folie
** Last update Sat Jul  4 19:30:04 2009 adrien folie
*/

#include <stdlib.h>
#include "dlist.h"
#include "push.h"

void		my_swap_first(t_dlist *list)
{
  t_elem	*temp;

  if (list->taille > 1)
    {
      temp = list->begin->next;
      if (list->taille > 2)
	{
	  list->begin->next = list->begin->next->next;
	  list->begin->next->prev = list->begin;
	}
	else
	  list->begin->next = NULL;
      temp->prev = NULL;
      temp->next = list->begin;
      list->begin = temp;
      list->begin->next->prev = list->begin;
/*      if (list->taille == 2)
	list->end = list->begin->next;*/
    }
}

void		my_ss(t_dlist *l_a, t_dlist *l_b)
{
  my_swap_first(l_a);
  my_swap_first(l_b);
}

void		my_sb(__attribute__((unused)) t_dlist *l_a, t_dlist *l_b)
{
  my_swap_first(l_b);
}

void		my_sa(t_dlist *l_a, __attribute__((unused)) t_dlist *l_b)
{
  my_swap_first(l_a);
}
