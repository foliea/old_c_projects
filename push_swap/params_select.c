/*
** params_select.c for push_swap in /u/all/otteme_t/cu/rendu/c/push_swap
**
** Made by thibaut ottemer
** Login   <otteme_t@epitech.net>
**
** Started on  Thu Jul  2 17:39:34 2009 thibaut ottemer
** Last update Sat Jul  4 18:46:54 2009 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "dlist.h"
#include "push.h"

typedef	struct	s_params
{
    char	*par;
    void	(*f)();
}		t_params;

static	const	t_params index[] =
  {
    {"sa", my_sa},
    {"sb", my_sb},
    {"ss", my_ss},
    {"pa", my_pa},
    {"pb", my_pb},
    {"ra", my_ra},
    {"rb", my_rb},
    {"rr", my_rr},
    {"rra", my_rra},
    {"rrb", my_rrb},
    {"rrr", my_rrr},
    {NULL, NULL}
  };

int	my_param_select(char *param, t_dlist *l_a, t_dlist *l_b)
{
  int	i;

  i = 0;
  if (param == NULL)
    return (0);
  while (index[i].par != NULL)
    {
      if (my_strcmp(index[i].par,param) == 0)
	{
	  index[i].f(l_a, l_b);
	  my_putstr(param);
	  my_putchar(' ');
	  return (0);
	}
      i++;
    }
  return (1);
}
