/*
** do_lab.c for do_lab.c in /u/all/folie_a/cu/rendu/rush/grimly/part2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Nov  8 15:23:57 2009 adrien folie
** Last update Sun Nov  8 22:43:41 2009 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
#include "librush.h"
#include "gen.h"
void	*xmalloc(int size);

char	**map_alloc(t_option *opt)
{
  char	**map;
  int	i;

  i = 0;
  map = xmalloc((opt->h + 1) * sizeof(*map));
  while (i < opt->h)
    {
      map[i] = xmalloc((opt->w + 1)* sizeof(**map));
      ++i;
    }
  map[i] = NULL;
  return (map);
}

void	map_middle(t_option *opt, char **map)
{
  int	i;
  int	j;

  j = 1;
  while (j < opt->h - 1)
    {
      i = 1;
      map[j][0] = opt->wall;
      map[j][opt->w - 1] = opt->wall;
      map[j][opt->w] = '\0';
      while (i < opt->w - 1)
	{
	  map[j][i] = opt->vide;
	  ++i;
	}
      ++j;
    }
}

void	map_ext(t_option *opt, char **map)
{
  int	i;

  i = 0;
  while (i < opt->w)
    {
      map[0][i] = opt->wall;;
      map[opt->h - 1][i] = opt->wall;
      ++i;
    }
  map[0][i] = '\0';
  map[opt->h - 1][i] = '\0';
  map_middle(opt, map);
  opt->min_w -= (opt->w + opt->h) * 2 - 4;
}

void	do_lab(t_option *opt)
{
  char	**map;

  map = map_alloc(opt);
  map_ext(opt, map);
  way_ext(opt, map);
  my_putstr("AUTEUR : folie_a\n");
  my_put_nbr(opt->w);
  my_putchar(opt->dd);
  my_put_nbr(opt->h);
  my_putchar('\n');
  my_showtab(map);
}
