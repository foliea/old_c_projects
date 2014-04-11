/*
** check_elevation.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Sun Jun 20 01:54:30 2010 adrien folie
** Last update Sun Jun 20 18:37:18 2010 adrien folie
*/

#include <stdio.h>
#include "player.h"
#include "map.h"
#include "fd_puts.h"
#include "elevation.h"

extern t_teams	*teams;
extern t_map	**map;

void		find_same_lvl(__attribute__((unused)) int fd,
			      void *data,
			      t_player *player)
{
  t_lvlup	*check;

  check = data;
  if (player->posx == check->x && player->posy == check->y &&
      player->lvl == check->lvl)
    {
      if (check->ftype == CHECK_ELEVATION)
	  check->nb++;
      else if (check->ftype == DO_ELEVATION)
	{
	  player->lvl++;
	  printf("\033[0;36mSending to %d :\033[0;0m niveau actuel : %d\n",
		 fd, player->lvl);
	  fd_puts(fd, "niveau actuel : ");
	  fd_putnbr(fd, player->lvl);
	  fd_puts(fd, "\n");
	}
    }
}

int	check_elevation_suite(int x, int y, int lvl, int nb)
{
  if (lvl == 4 && map[x][y].spot[LINEMATE] == 1 &&
      map[x][y].spot[DERAUMERE] == 1 && map[x][y].spot[SIBUR] == 2
      && map[x][y].spot[MENDIANE] == 0 && map[x][y].spot[PHIRAS] == 1
      && map[x][y].spot[THYSTAME] == 0 && nb == 4 && map[x][y].nb_player == 4)
    return (0);
  if (lvl == 5 && map[x][y].spot[LINEMATE] == 1 &&
      map[x][y].spot[DERAUMERE] == 2 && map[x][y].spot[SIBUR] == 1
      && map[x][y].spot[MENDIANE] == 3 && map[x][y].spot[PHIRAS] == 0
      && map[x][y].spot[THYSTAME] == 0 && nb == 4 && map[x][y].nb_player == 4)
    return (0);
  if (lvl == 6 && map[x][y].spot[LINEMATE] == 1 &&
      map[x][y].spot[DERAUMERE] == 2 && map[x][y].spot[SIBUR] == 3
      && map[x][y].spot[MENDIANE] == 0 && map[x][y].spot[PHIRAS] == 1
      && map[x][y].spot[THYSTAME] == 0 && nb == 6 && map[x][y].nb_player == 6)
    return (0);
  if (lvl == 7 && map[x][y].spot[LINEMATE] == 2 &&
      map[x][y].spot[DERAUMERE] == 2 && map[x][y].spot[SIBUR] == 2
      && map[x][y].spot[MENDIANE] == 2 && map[x][y].spot[PHIRAS] == 2
      && map[x][y].spot[THYSTAME] == 1 && nb == 6 && map[x][y].nb_player == 6)
    return (0);
  return (-1);
}

int	check_elevation_begin(int x, int y, int lvl, int nb)
{
  if (lvl == 1 && map[x][y].spot[LINEMATE] == 1 &&
      map[x][y].spot[DERAUMERE] == 0 && map[x][y].spot[SIBUR] == 0
      && map[x][y].spot[MENDIANE] == 0 && map[x][y].spot[PHIRAS] == 0
      && map[x][y].spot[THYSTAME] == 0 && nb == 1 && map[x][y].nb_player == 1)
    return (0);
  if (lvl == 2 && map[x][y].spot[LINEMATE] == 1 &&
      map[x][y].spot[DERAUMERE] == 1 && map[x][y].spot[SIBUR] == 1
      && map[x][y].spot[MENDIANE] == 0 && map[x][y].spot[PHIRAS] == 0
      && map[x][y].spot[THYSTAME] == 0 && nb == 2 && map[x][y].nb_player == 2)
    return (0);
  if (lvl == 3 && map[x][y].spot[LINEMATE] == 2 &&
      map[x][y].spot[DERAUMERE] == 0 && map[x][y].spot[SIBUR] == 1
      && map[x][y].spot[MENDIANE] == 0 && map[x][y].spot[PHIRAS] == 2
      && map[x][y].spot [THYSTAME] == 0 && nb == 2 && map[x][y].nb_player == 2)
    return (0);
  return (check_elevation_suite(x, y, lvl, nb));
}

int		check_elevation(int fd)
{
  t_player	*player;
  t_lvlup	data;
  int		check;

  player = get_player(teams, fd);
  data.x = player->posx;
  data.y = player->posy;
  data.lvl = player->lvl;
  data.nb = 0;
  data.ftype = CHECK_ELEVATION;
  set_func_to_player(fd, &data, find_same_lvl);
  check = check_elevation_begin(player->posx, player->posy,
				player->lvl, data.nb);
  return (check);
}
