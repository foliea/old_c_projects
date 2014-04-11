/*
** random_points.c for random_points in /u/all/folie_a/cu/rendu/rush/grimly/part2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Nov  8 18:01:28 2009 adrien folie
** Last update Sun Nov  8 21:25:52 2009 adrien folie
*/

#include <stdlib.h>
#include <time.h>
#include "gen.h"

void	finish_map(t_option *opt, char **map)
{
  int	i;
  int	j;

  j = 0;
  while (map[j] != NULL)
    {
      i = 0;
      while (map[j][i] != '\0')
	{
	  if (map[j][i] == '0')
	    map[j][i] = opt->vide;
	  ++i;
	}
      ++j;
    }
}

void	place_random(t_option *opt, char **map)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  srand(time(NULL));
/*  printf("min_w : %d\nmax_w : %d\n", opt->min_w, opt->max_w);*/
  while (opt->min_w > 0)
    {
      y = rand()%(opt->h);
      x = rand()%(opt->w);
      /*    printf("x : %d\ty : %d\n", x, y);*/
      if (map[y][x] == opt->vide)
	{
	  map[y][x] = opt->wall;
	  opt->min_w--;
	}
    }
  while (i < opt->max_w / 2)
    {
      y = rand()%(opt->h);
      x = rand()%(opt->w);
/*      printf("x : %d\ty : %d\n", x, y);*/
      if (map[y][x] == opt->vide)
        {
          map[y][x] = opt->wall;
	  ++i;
        }
    }
}
