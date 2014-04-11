/*
** astar.c for algo_utils in /u/all/folie_a/cu/rendu/rush/grimly/part1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sat Nov  7 16:09:04 2009 adrien folie
** Last update Sun Nov  8 00:14:59 2009 adrien folie
*/

#include <math.h>
#include <stdlib.h>
#include "grimly.h"

void	hiden_malloc(t_lab *lab)
{
  int	i;

  i = 0;
  lab->hiden = malloc(lab->h * sizeof(t_case *));
  while (i < lab->h)
    {
      lab->hiden[i] = malloc(lab->w * sizeof(t_case *));
      ++i;
    }
}

int	do_end(t_lab *lab, int pos, int x, int y)
{
  int	i;

  i = 0;
  while (i < 4)
    {
      if (i == pos)
	lab->hiden[y][x].cout[i] = 0.0;
      else
	lab->hiden[y][x].cout[i] = -1.0;
      ++i;
    }
  return (0);
}

float	calc_cout(int x2, int y2, int x1, int y1)
{
  return (sqrtf((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
}

int	check_case(t_lab *lab, int x, int y, char **map)
{
  if ((y - 1) >= 0 && (y - 1) < lab->h)
    {
      if (map[y - 1][x] == '2')
	return (do_end(lab, UP, x, y));
      if (map[y - 1][x] == '*' || map[y - 1][x] == '0')
	lab->hiden[y][x].cout[UP] = -1.0;
      else
	lab->hiden[y][x].cout[UP] = calc_cout(x, y - 1, lab->exit.begin->x, lab->exit.begin->y);
    }
  else
    lab->hiden[y][x].cout[UP] = -1.0;
  if ((y + 1) >= 0 && (y + 1) < lab->h)
    {
      if (map[y + 1][x] == '2')
	return (do_end(lab, DOWN, x, y));
      if (map[y + 1][x] == '*' || map[y + 1][x] == '0')
	lab->hiden[y][x].cout[DOWN] = -1.0;
      else
	lab->hiden[y][x].cout[DOWN] = calc_cout(x, y + 1, lab->exit.begin->x, lab->exit.begin->y);
    }
  else
    lab->hiden[y][x].cout[DOWN] = -1.0;
  if ((x - 1) >= 0 && (x - 1) < lab->w)
    {
      if (map[y][x - 1] == '2')
	return (do_end(lab, LEFT, x, y));
          if (map[y][x - 1] == '*' || map[y][x - 1] == '0')
	lab->hiden[y][x].cout[LEFT] = -1.0;
      else
	lab->hiden[y][x].cout[LEFT] = calc_cout(x - 1, y, lab->exit.begin->x, lab->exit.begin->y);
    }
  else
    lab->hiden[y][x].cout[LEFT] = -1.0;
  if ((x + 1) >= 0 && (x + 1) < lab->w)
    {
      if (map[y][x + 1] == '2')
	return (do_end(lab, RIGHT, x, y));
      if (map[y][x + 1] == '*' || map[y][x + 1] == '0')
	lab->hiden[y][x].cout[RIGHT] = -1.0;
      else
	lab->hiden[y][x].cout[RIGHT] = calc_cout(x + 1, y, lab->exit.begin->x, lab->exit.begin->y);
    }
  else
    lab->hiden[y][x].cout[RIGHT] = -1.0;
  return (0);
}
