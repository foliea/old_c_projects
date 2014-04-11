/*
** my_push_swap.c for push_swap in /u/all/otteme_t/cu/rendu/c/push_swap
**
** Made by thibaut ottemer
** Login   <otteme_t@epitech.net>
**
** Started on  Wed Jul  1 18:23:31 2009 thibaut ottemer
** Last update Mon Jul  6 15:23:01 2009 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
#include "dlist.h"
#include "push.h"

int		my_is_end(t_dlist *l_a, int sens)
{
  t_elem	*temp;
  int		a;
  int		b;

  if (l_a->taille == 1)
    return (0);
  temp = l_a->begin;
  while (l_a->begin->next != NULL)
    {
      a = my_getnbr(l_a->begin->data);
      b = my_getnbr(l_a->begin->next->data);
      l_a->begin = l_a->begin->next;
      if ((a > b && sens == 0) || (a < b && sens == 1))
	{
	  l_a->begin = temp;
	  return (1);
	}
    }
  l_a->begin = temp;
  return (0);
}

char	*my_cmd(t_dlist *list, int sens)
{
  char	*cmd;

  cmd = NULL;
  if (list->begin != NULL && list->begin->next != NULL &&
      my_is_end(list, sens) == 1)
    {
      if ((my_getnbr(list->begin->data) > my_getnbr(list->begin->next->data) &&
	   sens == 0) ||
	  (my_getnbr(list->begin->data) < my_getnbr(list->begin->next->data) &&
	   sens == 1))
	cmd = my_strdup("sa");
/*      else if (list->taille != 2)
	cmd = my_strdup("rra");*/
      else
	cmd = my_strdup("sa");
    }
  return (cmd);
}

void	my_tri(t_dlist *l_a, t_dlist *l_b)
{
  char	*cmd_1;
  char	*cmd_2;

  if (my_is_end(l_a, 0) == 1 || my_is_end(l_b, 1) == 1)
    {
      cmd_1 = my_cmd(l_a, 0);
      cmd_2 = my_cmd(l_b, 1);
      if (cmd_1 != NULL && cmd_2 != NULL && my_strcmp(cmd_1, cmd_2) == 0)
	{
	  if (cmd_1[0] == 's')
	    my_param_select("ss", l_a, l_b);
/*	  else if (cmd_1[2] != '\0')
	  my_param_select("rrr", l_a, l_b);*/
	  else
	    my_param_select("rr", l_a, l_b);
	}
      else
	{
	  if (cmd_1 != NULL)
	    my_param_select(cmd_1, l_a, l_b);
	  if (cmd_2 != NULL)
	    my_param_select(cmd_2, l_b, l_a);
	}
    }
}

void	my_push_swap(t_dlist *l_a, t_dlist *l_b)
{
  int	len;

  len = l_a->taille / 2;
  if (l_a->taille == 2 && my_is_end(l_a, 0) == 1)
    my_param_select("sa", l_a, l_b);
  while (my_is_end(l_a, 0) == 1)
    {
      len = l_a->taille / 2;
      while (l_a->taille > len + (len % 2))
	my_param_select("pb", l_a, l_b);
      my_tri(l_a, l_b);
      while (l_b->taille != 0)
	my_param_select("pa", l_a, l_b);
      if (my_is_end(l_a, 0) == 1)
	my_param_select("rra", l_a, l_b);
    }
}
