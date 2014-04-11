/*
** init_map.c for zappy in /u/epitech_2013/bienve_e/cu/rendu/c/zappy
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri Jun 11 18:44:54 2010 edern bienvenu
** Last update Tue Jul  5 16:25:35 2011 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "player.h"
#include "map.h"

extern t_map	**map;

void	add_element(int x, int y)
{
  map[x][y].nb_player = 0;
  map[x][y].spot[FOOD] = rand() % 5;
  map[x][y].spot[LINEMATE] = rand() % 2;
  map[x][y].spot[DERAUMERE] = rand() % 2;
  map[x][y].spot[SIBUR] = rand() % 2;
  map[x][y].spot[MENDIANE] = rand() % 2;
  map[x][y].spot[PHIRAS] = rand() % 2;
  map[x][y].spot[THYSTAME] = rand() % 2;
  return ;
}

void	init_map(int x, int y)
{
  int	i;
  int	j;

  i = 0;
  srand(time(NULL));
  while (i < x)
    {
      j = 0;
      while (j < y)
	{
          add_element(j, i);
          j++;
	}
      i++;
    }
  return ;
}

void	alloc_map(int x, int y)
{
  int		i;

  i = 0;
  map = xmalloc(sizeof(t_map *) * x);
  while (i < x)
    {
      map[i] = xmalloc(sizeof(t_map) * y);
      i++;
    }
}
