/*
** do_elevation.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Sun Jun 20 05:06:40 2010 adrien folie
** Last update Sun Jun 20 18:24:34 2010 edern bienvenu
*/

#include "player.h"
#include "fd_puts.h"
#include "elevation.h"

void	do_elevation(__attribute__((unused))char *cmd,
		     t_player *player, int fd)
{
  t_lvlup	data;

  data.x = player->posx;
  data.y = player->posy;
  data.lvl = player->lvl;
  data.nb = 0;
  data.ftype = DO_ELEVATION;
  if (check_elevation(fd) == -1)
    fd_puts(fd, "ko\n");
  else
    set_func_to_player(fd, &data, find_same_lvl);
}
