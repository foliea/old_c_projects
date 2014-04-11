/*
** do_options.c for do_options in /u/all/folie_a/cu/rendu/rush/grimly/part2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Nov  8 18:56:09 2009 adrien folie
** Last update Sun Nov  8 23:23:35 2009 adrien folie
*/

#include <stdlib.h>
#include <string.h>
#include "librush.h"
#include "gen.h"

typedef struct	s_flags
{
    char	*option;
    void	(*f)();
}		t_flags;

static const t_flags	tab[]=
{
  {"-width=", opt_width},
  {"-height=", opt_height},
  {"-noelie", opt_noelie},
  {"-celine", opt_celine},
  {"-marie", opt_marie},
  {"-gate=", opt_gate},
  {"-wall=", opt_wall},
  {NULL, NULL}
};

void	opt_height(t_option *opt, int *i, __attribute__((unused)) int ac, char **av)
{
  char	**tmp;

  tmp = str_to_wordtab(av[*i], '=');
  if (my_tablen(tmp) != 2)
    my_put_error("-height=XXXX XXXX Invalid\n");
  opt->h = my_getnbr(tmp[1]);
  if (opt->h < 5 || opt->h > 4096)
    {
      my_put_error("-height : must be >= 5 and <= 4096\n");
      exit(EXIT_FAILURE);
    }
  opt->min_w = (opt->w + opt->h) * 2 - 4;
  opt->max_w = (opt->w * opt->h) - (3 * opt->min_w);
  my_freetab(tmp);
}

void	opt_width(t_option *opt, int *i, __attribute__((unused)) int ac, char **av)
{
  char	**tmp;

  tmp = str_to_wordtab(av[*i], '=');
  if (my_tablen(tmp) != 2)
    my_put_error("-width=XXXX XXXX Invalid\n");
  opt->w = my_getnbr(tmp[1]);
  if (opt->w < 5 || opt->w > 4096)
    {
      my_put_error("-width : must be >= 5 and <= 4096\n");
      exit(EXIT_FAILURE);
    }
  opt->min_w = (opt->w + opt->h) * 2 - 4;
  opt->max_w = (opt->w * opt->h) - (3 * opt->min_w);
  my_freetab(tmp);
}

int	choose_option(t_option *opt, int *i, __attribute__((unused)) int ac, char **av)
{
  int	j;
  int	size;

  j = 0;
  while (tab[j].option != NULL)
    {
      size = my_strlen(av[*i]);
      if (size > 6)
	size = 6;
      if (size > 4 && strncmp(av[*i], tab[j].option, size) == 0)
	{
	  tab[j].f(opt, i, ac, av);
	  return (0);
	}
      ++j;
    }
  my_put_error("Invalid Option\n");
  exit(EXIT_FAILURE);
  return (-1);
}

void	do_options(t_option *opt, int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      choose_option(opt, &i, ac, av);
      ++i;
    }
}
