/*
** place_points.c for place_points in /u/all/folie_a/cu/rendu/rush/grimly/part2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Nov  8 17:18:41 2009 adrien folie
** Last update Sun Nov  8 21:26:24 2009 adrien folie
*/

#include "gen.h"

void    way_middle(t_option *opt, char **map)
{
  int   j;

  j = 3;
  while (j < opt->h - 3)
    {
      map[j][2] = '0';
      map[j][opt->w - 3] = '0';
      ++j;
    }
}



void	join_ext(t_option *opt, char **map)
{
  int	i;

  i = opt->w /2 + 1;
  while (i < opt->w - 2)
    {
      map[opt->h / 2][i] = '0';
      ++i;
    }
}

void    exit_middle(t_option *opt, char **map)
{
  int   j;

  j = 2;
  while (opt->nb_exit > 0 && j < opt->h - 2)
    {
      map[j][1] = opt->exit;
      opt->nb_exit--;
      if (opt->nb_exit > 0)
        {
	  map[j][opt->w - 2] = opt->exit;
	  opt->nb_exit--;
	}
      ++j;
    }
}

void	exit_ext(t_option *opt, char **map)
{
  int	i;

  i = 2;
  while (opt->nb_exit > 0 && i < opt->w - 2)
    {
      map[1][i] = opt->exit;
      opt->nb_exit--;
      if (opt->nb_exit > 0)
	{
	  map[opt->h - 2][i] = opt->exit;
	  opt->nb_exit--;
	}
      ++i;
    }
  exit_middle(opt, map);
}

void    way_ext(t_option *opt, char **map)
{
  int   i;

  i = 2;
  while (i < opt->w - 2)
    {
      map[2][i] = '0';
      map[opt->h - 3][i] = '0';
      ++i;
    }
  way_middle(opt, map);
  map[opt->h / 2][opt->w /2] = opt->enter;
  join_ext(opt, map);
  exit_ext(opt, map);
  place_random(opt, map);
  finish_map(opt, map);
}
