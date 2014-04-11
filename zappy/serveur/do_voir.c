/*
** do_voir.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sat Jun 19 20:35:01 2010 edern bienvenu
** Last update Sun Jun 20 19:12:03 2010 edern bienvenu
*/

#include "map.h"
#include "parsing.h"
#include "player.h"
#include "fd_puts.h"
#include "voir.h"

extern t_map	**map;
extern t_parse	parse;

void	verif_pos_voir(t_voir *voir, int z)
{
  if (voir->posx + z >= parse.height)
    voir->tmpx = voir->posx + z - parse.height;
  else if (voir->posx + z < 0)
    voir->tmpx += voir->posx + z + parse.height;
  if (voir->posy + z >= parse.width)
    voir->tmpy = voir->posy + z - parse.width;
  else if (voir->posy + z < 0)
    voir->tmpy = voir->posy + z + parse.width;
}

void	upgrade_follow(t_voir *voir, int dir)
{
  if (dir == LEFT)
    {
      voir->tmpx++;
      if (voir->tmpx >= parse.height)
	voir->tmpx = voir->tmpx - parse.height;
      else if (voir->tmpx < 0)
	voir->tmpx += voir->tmpx + parse.height;
    }
  else if (dir == RIGHT)
    {
      voir->tmpx--;
      if (voir->tmpx >= parse.height)
	voir->tmpx = voir->tmpx - parse.height;
      else if (voir->tmpx < 0)
	voir->tmpx += voir->tmpx + parse.height;
    }
}

int	upgrade_value(t_voir *voir, int dir)
{
  if (dir == UP)
    {
      voir->tmpy++;
      if (voir->tmpy >= parse.width)
	voir->tmpy = voir->tmpy - parse.width;
      else if (voir->tmpy < 0)
	voir->tmpy = voir->posy + parse.width;
      return (1);
    }
  else if (dir == DOWN)
    {
      voir->tmpy--;
      if (voir->tmpy >= parse.width)
	voir->tmpy = voir->tmpy - parse.width;
      else if (voir->tmpy < 0)
	voir->tmpy = voir->posy + parse.width;
      return (1);
    }
  return (0);
}


void	voir(t_player *player, int fd)
{
  if (player->lvl == 1)
    voir_by_lvl(player, 3, fd);
  else if (player->lvl == 2)
    voir_by_lvl(player, 5, fd);
  else if (player->lvl == 3)
    voir_by_lvl(player, 7, fd);
  else if (player->lvl == 4)
    voir_by_lvl(player, 11, fd);
  else if (player->lvl == 5)
    voir_by_lvl(player, 13, fd);
  else if (player->lvl == 6)
    voir_by_lvl(player, 15, fd);
  else if (player->lvl == 7)
    voir_by_lvl(player, 17, fd);
  else if (player->lvl == 8)
    voir_by_lvl(player, 19, fd);
  else
    send_ko(fd);
}
