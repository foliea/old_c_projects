/*
** recup_player_pos.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sat Jun 19 03:34:34 2010 edern bienvenu
** Last update Sun Jun 20 19:44:57 2010 adrien folie
*/

#include <stdlib.h>
#include <sys/select.h>
#include <stdio.h>
#include "serveur.h"
#include "player.h"
#include "parsing.h"
#include "map.h"
#include "value.h"
#include "fd_puts.h"

extern t_teams	*teams;
extern t_parse	parse;
extern t_map	**map;

int	calc_k(t_player *player, t_player *f_player)
{
  if (f_player->direct == UP)
    return (value_k_up(player));
  else if (f_player->direct == DOWN)
    return (value_k_down(player));
  else if (f_player->direct == LEFT)
    return (value_k_left(player));
  else if (f_player->direct == RIGHT)
    return (value_k_right(player));
  return (0);
}

void	avance_expulse_follow(t_player *player)
{
  if (player->posy == 0 && player->direct == LEFT)
    {
      player->posy = parse.width;
      map[player->posx][player->posy].nb_player++;
    }
  else if (player->posy == parse.width - 1 && player->direct == RIGHT)
    {
      player->posy = 0;
      map[player->posx][player->posy].nb_player++;
    }
  else
    {
      new_pos_expulse(player, player->direct);
      map[player->posx][player->posy].nb_player++;
    }
}

void		avance_expulse(__attribute__((unused)) int fd,
			       void *data, t_player *player)
{
  t_player	*f_player;
  int		k;

  player = data;
  if (f_player->posx != player->posx ||
      f_player->posy != player->posy)
    return ;
  map[player->posx][player->posy].nb_player--;
  if (player->posx == 0 && player->direct == UP)
    {
      player->posx = parse.height - 1;
      map[player->posx][player->posy].nb_player++;
    }
  else if (player->posx == parse.height - 1 && player->direct == DOWN)
    {
      player->posx = 0;
      map[player->posx][player->posy].nb_player++;
    }
  avance_expulse_follow(player);
  k = calc_k(player, f_player);
  printf("\033[0;31mSending message to %d :\033[0;0m deplacement %d\n", fd, k);
  fd_puts(player->fd, "deplacement ");
  fd_putnbr(player->fd, k);
  fd_puts(player->fd, "\n");
}

void		send_player(t_dteam *team, int fd, void *data, void (*f)())
{
  t_player	*tmp;

  tmp = team->begin;
  while (team->begin != NULL)
    {
      f(fd, data, team->begin);
      team->begin = team->begin->next;
    }
  team->begin = tmp;
}

void	set_func_to_player(int fd, void *data, void (*f)())
{
  int		i;

  i = 0;
  while (i < parse.nb_team)
    {
      send_player(teams[i].data, fd, data, f);
      ++i;
    }
}
