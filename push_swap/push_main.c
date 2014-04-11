/*
** push_main.c for push_main in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Jun 14 17:36:44 2009 adrien folie
** Last update Sat Jul  4 19:33:31 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include "dlist.h"
#include "push.h"

int	my_isnum(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '-')
    ++i;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      ++i;
    }
  return (1);
}

int	params_pos(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (my_isnum(av[i]) == 0)
	return (-1);
      ++i;
    }
  return (0);
}

void		aff_lists(t_dlist *l_a, t_dlist *l_b)
{
  my_putstr("l_a : ");
  if (l_a->taille > 0)
    my_show_dlist(l_a, 1);
  my_putstr("\nl_b : ");
  if (l_b->taille > 0)
    my_show_dlist(l_b, 1);
  my_putchar('\n');
}

void		push_main(int ac, char **av)
{
  t_dlist	l_a;
  t_dlist	l_b;
  int		i;

  i = 1;
  my_init_dlist(&l_a);
  my_init_dlist(&l_b);
  while (i++ < ac)
    my_put_in_dlist(&l_a, av[i - 1], 1);
  my_push_swap(&l_a, &l_b);
  my_free_dlist(&l_a);
  my_free_dlist(&l_b);
}

int	main(int ac, char **av)
{
  int	pos;

  if (ac == 1)
    my_putstr("Please enter more arguments.\n");
  else
    {
      pos = params_pos(ac, av);
      if (pos == -1)
	{
	  my_putstr("Please enter numbers.\n");
	  exit(EXIT_FAILURE);
	}
      push_main(ac, av);
    }
  return (0);
}
