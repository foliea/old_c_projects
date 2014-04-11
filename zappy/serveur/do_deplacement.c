/*
** do_deplacement.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun Jun 20 18:08:50 2010 edern bienvenu
** Last update Sun Jun 20 18:44:06 2010 edern bienvenu
*/

#include <stdio.h>
#include "map.h"
#include "parsing.h"
#include "player.h"
#include "fd_puts.h"
#include "voir.h"

void	do_droite(__attribute__((unused))char *cmd, t_player *player, int fd)
{
  if (player->direct == UP)
    player->direct = RIGHT;
  else if (player->direct == DOWN)
    player->direct = LEFT;
  else if (player->direct == LEFT)
    player->direct = UP;
  else if (player->direct == RIGHT)
    player->direct = DOWN;
  printf("\033[0;31mSending message to %d :\033[0;0m ok\n", fd);
  fd_puts(fd, "ok\n");
}

void	do_gauche(__attribute__((unused))char *cmd, t_player *player, int fd)
{
  if (player->direct == UP)
    player->direct = LEFT;
  else if (player->direct == DOWN)
    player->direct = RIGHT;
  else if (player->direct == LEFT)
    player->direct = DOWN;
  else if (player->direct == RIGHT)
    player->direct = UP;
  printf("\033[0;31mSending message to %d :\033[0;0m ok\n", fd);
  fd_puts(fd, "ok\n");
}

void	do_voir(__attribute__((unused))char *cmd, t_player *player, int fd)
{
  voir(player, fd);
}
