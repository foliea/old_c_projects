/*
** elevation.h for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Sun Jun 20 05:07:14 2010 adrien folie
** Last update Sun Jun 20 18:05:24 2010 edern bienvenu
*/

#ifndef ELEVATION_H
#define ELEVATION_H

#define CHECK_ELEVATION 0
#define DO_ELEVATION 1

typedef struct	s_lvlup
{
  int		x;
  int		y;
  int		lvl;
  int		nb;
  int		ftype;
}		t_lvlup;

void	find_same_lvl(__attribute__((unused)) int fd, void *data, t_player *player);
int	check_elevation(int fd);
int	get_nb_clients(t_teams *teams, int fd);
#endif
