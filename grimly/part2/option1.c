/*
** option1.c for option1 in /u/all/folie_a/cu/rendu/rush/grimly/part2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Nov  8 21:08:06 2009 adrien folie
** Last update Sun Nov  8 23:17:59 2009 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
#include "librush.h"
#include "gen.h"

void	opt_marie(t_option *opt, int *i, __attribute__((unused)) int ac, char **av)
{
  if (my_strlen(av[*i]) != my_strlen("-marie"))
    my_put_error("Invalid Option\n");
  if (opt->mcn == 1)
    my_put_error("-marie, -Celine and -noelie work alone only\n");
  else
    opt->mcn = 1;
  opt->wall = 'm';
  opt->enter = 'a';
  opt->exit = 'r';
  opt->vide = 'i';
  opt->dd = 'e';
}

void	opt_celine(t_option *opt, int *i, __attribute__((unused)) int ac, char **av)
{
  if (my_strlen(av[*i]) != my_strlen("-celine"))
    my_put_error("Invalid Option\n");
  if (opt->mcn == 1)
    my_put_error("-marie, -Celine and -noelie work alone only\n");
  else
    opt->mcn = 1;
  opt->wall = 'c';
  opt->enter = 'e';
  opt->exit = 'l';
  opt->vide = 'i';
  opt->dd = 'n';
}

void	opt_noelie(t_option *opt, int *i, __attribute__((unused)) int ac, char **av)
{
  if (my_strlen(av[*i]) != my_strlen("-noelie"))
    my_put_error("Invalid Option\n");
  if (opt->mcn == 1)
    my_put_error("-marie, -Celine and -noelie work alone only\n");
  else
    opt->mcn = 1;
  opt->wall = 'n';
  opt->enter = 'o';
  opt->exit = 'e';
  opt->vide = 'l';
  opt->dd = 'i';
}

void	opt_gate(t_option *opt, int *i, __attribute__((unused)) int ac, char **av)
{
  char	**tmp;

  tmp = str_to_wordtab(av[*i], '=');
  if (*i != ac - 1)
    my_put_error("-gate=XXX XXXX must be at the end of the command line\n");
  if (my_tablen(tmp) != 2)
    my_put_error("-gate=XXXX XXXX Invalid\n");
  opt->nb_exit = my_getnbr(tmp[1]);
  if (opt->nb_exit < 1 ||
      opt->nb_exit >= (((opt->w -1) + (opt->h - 1)) * 2 - 3))
    my_put_error("-gate : value incorrect\n");
  my_freetab(tmp);
}

void	opt_wall(t_option *opt, int *i, __attribute__((unused)) int ac, char **av)
{
  char	**tmp;

  tmp = str_to_wordtab(av[*i], '=');
  if (my_tablen(tmp) != 2)
    my_put_error("-wall=XXXX XXXX Invalid\n");
  opt->min_w = my_getnbr(tmp[1]);
  if ((opt->min_w < (opt->w + opt->h) * 2 - 4) ||
      opt->min_w > ((opt->w * opt->h) - 16 * (opt->w + opt->h)))
    {
      fprintf(stderr, "-wall : value must be > %d and < %d\n",
	      ((opt->w + opt->h) * 2 - 4),
	      ((opt->w * opt->h) - 16 * (opt->w + opt->h)));
      exit(EXIT_FAILURE);
    }
  opt->max_w = (opt->w * opt->h) - (3 * opt->min_w);
  my_freetab(tmp);
}
