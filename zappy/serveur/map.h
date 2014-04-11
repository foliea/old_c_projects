/*
** map.h for zappy in /u/all/bienve_e/cu/rendu/c/zappy
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri Jun 11 18:59:17 2010 edern bienvenu
** Last update Sun Jun 20 01:37:47 2010 edern bienvenu
*/

#ifndef MAP_H_
#define MAP_H_

typedef	struct	s_map
{
  int		nb_player;
  int		spot[7];
}		t_map;

typedef	struct	s_voir
{
  int		posx;
  int		posy;
  int		tmpx;
  int		tmpy;
}		t_voir;

void	init_map(int x, int y);
void	alloc_map(int x, int y);

#endif
