/*
** check_list.c for check_list in /u/all/folie_a/cu/rendu/c/minishell2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri Oct  2 05:14:25 2009 adrien folie
** Last update Sun Oct  4 23:10:08 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int		check_inhibitor(t_elem *p, t_dlist *list)
{
  if (my_strcmp(p->s, "<>") != -1
      || my_strcmp(p->s, "><") != -1
      || my_strcmp(p->s, "<|") != -1
      || my_strcmp(p->s, ">|") != -1
      || my_strcmp(p->s, "|>") != -1
      || my_strcmp(p->s, "|<") != -1
      || (p != list->end->prev
	  && p->s != NULL && p->s[0] == '>'))
    {
      my_putstr("Missing name for redirect.\n");
      return (-1);
    }
  return (0);
}

int		check_list(t_dlist *list)
{
  t_elem	*tmp;
  int		i;

  i = 0;
  tmp = list->begin;
  while (i < list->taille)
    {
      if (my_strcmp(list->begin->s, "||") != -1)
	{
	  my_putstr("Invalid null command.\n");
	  return (-1);
	}
      if (check_inhibitor(list->begin, list) == -1)
	return (-1);
      if (i != 0 && list->begin->s != NULL && list->begin->s[0] == '<')
	{
	  my_putstr("Ambiguous input redirect.\n");
	  return (-1);
	}
      ++i;
      list->begin = list->begin->next;
    }
  list->begin = tmp;
  return (0);
}
