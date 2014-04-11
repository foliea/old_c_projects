/*
** main_gen.c for main_gen in /u/all/folie_a/cu/rendu/rush/grimly/part2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Nov  8 15:10:13 2009 adrien folie
** Last update Sun Nov  8 22:48:47 2009 adrien folie
*/

#include <unistd.h>
#include <fcntl.h>
#include "gen.h"

void	option_init(t_option *opt)
{
  opt->w = 42;
  opt->h = 42;
  opt->wall = '*';
  opt->dd = 'x';
  opt->enter = '1';
  opt->exit = '2';
  opt->vide = ' ';
  opt->min_w = (opt->w + opt->h) * 2 - 4;
  opt->max_w = (opt->w * opt->h) - (3 * opt->min_w);
  opt->nb_exit = 1;
  opt->mcn = 0;
}

int		main(int ac, char **av)
{
  t_option	opt;
  int		fd;

  fd = open("map.map", O_CREAT | O_WRONLY | O_TRUNC);
  if (fd == -1)
    my_put_error("Can't open file\n");
  if (dup2(fd, 1) == -1)
    my_put_error("dup2 failed\n");
  option_init(&opt);
  if (ac != 1)
    do_options(&opt, ac, av);
  do_lab(&opt);
  close(fd);
  return (0);
}
