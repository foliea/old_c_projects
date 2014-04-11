/*
** checks_map.c for checks_maps in /u/all/folie_a/cu/rendu/rush/grimly/part1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sat Nov  7 02:29:45 2009 adrien folie
** Last update Sat Nov  7 22:04:21 2009 adrien folie
*/

#include <stdlib.h>
#include "grimly.h"

void	find_enter(char **map, t_point *enter)
{
  int	i;
  int	j;
  int	error;

  j = 0;
  error = 0;
  while (map[j] != NULL)
    {
      i = 0;
      while (map[j][i] != '\0')
	{
	  if (map[j][i] == '1')
	    {
	      enter->x = i;
	      enter->y = j;
	      error++;
	    }
	  i++;
	}
      j++;
    }
  if (error == 0 || error > 1)
    my_put_error("MAP ERROR\n");
}

void	check_vert(char **map, int w)
{
  int	i;

  i = 0;
  while (map[i] != NULL)
    {
      if (map[i][0] != '*' && map[i][0] != '1' && map[i][0] != '2')
	my_put_error("MAP ERROR\n");
      ++i;
    }
  i = 0;
  while (map[i] != NULL)
    {
      if (map[i][w - 1] != '*' && map[i][w - 1] != '1' && map[i][w -1] != '2')
	my_put_error("MAP ERROR\n");
      ++i;
    }
}

void	check_hor(char **map, int h)
{
  int	i;

  i = 0;
  while (map[0][i] != '\0')
    {
      if (map[0][i] != '*' && map[0][i] != '1' && map[0][i] != '2')
	my_put_error("MAP ERROR\n");
      ++i;
    }
  i = 0;
  while (map[h - 1][i] != '\0')
    {
      if (map[h - 1][i] != '*' && map[h - 1][i] != '1' && map[h - 1][i] != '2')
	my_put_error("MAP ERROR\n");
      ++i;
    }
}

void	check_exit(char **map, t_dlist *exit)
{
  int	i;
  int	j;

  j = 0;
  while (map[j] != NULL)
    {
      i = 0;
      while (map[j][i] != '\0')
	{
	  if (map[j][i] == '2')
	    my_put_in_dlist(exit, i, j, 1);
	  ++i;
	}
      ++j;
    }
}

void	check_map(t_lab *lab, char **map)
{
  find_enter(map, &lab->enter);
  check_hor(map, lab->h);
  check_vert(map, lab->w);
  my_init_dlist(&lab->exit);
  check_exit(map, &lab->exit);
  if (lab->exit.taille == 0)
    my_put_error("MAP ERROR\n");
}
