/*
** main.c for main in /u/all/folie_a/cu/rendu/c/my_select
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Jun 17 00:36:51 2009 adrien folie
** Last update Wed Jul  8 17:32:52 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <term.h>
#include "clist.h"
#include "select.h"

void	my_check_term(char **env)
{
  char	bp[4096];
  char	*term;

  if ((term = my_getenv(env, "TERM=")) == NULL)
    {
      my_putstr("unknown terminal\n");
      exit(EXIT_FAILURE);
    }
  if (tgetent(bp, term) != 1)
    {
      my_putstr("tgetent error\n");
      exit(EXIT_FAILURE);
    }
  free(term);
}

void		my_params_in_clist(int ac, char **av, char **env)
{
  int		i;
  t_clist	list;
  t_caps	caps;

  i = 1;
  my_init_clist(&list);
  while (i < ac)
    {
      my_put_in_clist(&list, av[i], 1);
      ++i;
    }
  my_check_term(env);
  my_caps_def(&caps);
  my_ioctl_mod();
  my_while(&caps, &list);
}

int	main(int ac, char **av, char **env)
{
  if (ac > 1)
    my_params_in_clist(ac, av, env);
  else
    my_putstr("Please enter more arguments.\n");
  return (0);
}
