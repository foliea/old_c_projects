/*
** recup_k_value.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun Jun 20 17:18:34 2010 edern bienvenu
** Last update Sun Jun 20 17:23:27 2010 edern bienvenu
*/

#include "player.h"

void	new_pos_expulse(t_player *player, int dir)
{
  if (dir == UP)
    player->posx -= 1;
  else if (dir == DOWN)
    player->posx += 1;
  else if (dir == LEFT)
    player->posy -= 1;
  else if (dir == RIGHT)
    player->posy += 1;
}

int	value_k_up(t_player *player)
{
   if (player->direct == UP)
    return (5);
  else if (player->direct == DOWN)
    return (1);
  else if (player->direct == LEFT)
    return (3);
  else if (player->direct == RIGHT)
    return (7);
  return (0);
}

int	value_k_down(t_player *player)
{
     if (player->direct == UP)
    return (1);
  else if (player->direct == DOWN)
    return (5);
  else if (player->direct == LEFT)
    return (7);
  else if (player->direct == RIGHT)
    return (3);
  return (0);
}

int	value_k_left(t_player *player)
{
  if (player->direct == UP)
    return (7);
  else if (player->direct == DOWN)
    return (3);
  else if (player->direct == LEFT)
    return (1);
  else if (player->direct == RIGHT)
    return (5);
  return (0);
}

int	value_k_right(t_player *player)
{
  if (player->direct == UP)
    return (3);
  else if (player->direct == DOWN)
    return (7);
  else if (player->direct == LEFT)
    return (1);
  else if (player->direct == RIGHT)
    return (5);
  return (0);
}
