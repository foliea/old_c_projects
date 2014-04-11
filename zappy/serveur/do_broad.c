/*
** do_broad.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun Jun 20 18:18:42 2010 edern bienvenu
** Last update Sun Jun 20 18:46:34 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <sys/select.h>
#include "serveur.h"
#include "fd_puts.h"
#include "cbuff.h"
#include "player.h"
#include "planning.h"
#include "parsing.h"
#include "map.h"
#include "broad.h"
#include "food.h"

extern	t_parse	parse;

float	calc_vector(int sx, int sy, int dx, int dy)
{
  float	norme;
  int	vx;
  int	vy;

  vx = sx - dx;
  vy = sy - dy;
  norme = sqrtf((vx * vx) + (vy * vy));
  return (norme);
}

int	calc_coef(int x1, int y1, int x2, int y2)
{
  float	res[8];
  int	i;
  float	check;

  res[0] = calc_vector(x1 - 1, y1, x2, y2);
  res[1] = calc_vector(x1 - 1, y1 - 1, x2, y2);
  res[2] = calc_vector(x1 + 1, y1 - 1, x2, y2);
  res[3] = calc_vector(x1 + 1, y1 - 1, x2, y2);
  res[4] = calc_vector(x1 + 1, y1, x2, y2);
  res[5] = calc_vector(x1 + 1, y1 + 1, x2, y2);
  res[6] = calc_vector(x1 + 1, y1 + 1, x2, y2);
  res[7] = calc_vector(x1 + 1, y1 + 1, x2, y2);
  i = 0;
  check = res[0];
  while (i < 8)
    {
      if (res[i] < check)
	check = res[i];
      ++i;
    }
  i = 0;
  while (res[i] != check)
    ++i;
  return (i + 1);
}

void		send_broadcast(int fd, void *data, t_player *player)
{
  int		k;
  t_broad	*broad;

  broad = data;
  if (broad->x == player->posx && broad->y == player->posy
      && fd == player->fd)
    return ;
  k = calc_coef(player->posx, player->posy, broad->x, broad->y);
  printf("\033[0;31mSending message to %d :\033[0;0m Message %d,%s\n",
	 fd, k, broad->msg);
  fd_puts(fd, "Message ");
  fd_putnbr(fd, k);
  fd_puts(fd, ",");
  fd_puts(fd, broad->msg);
}

void		do_broadcast(char *cmd, t_player *player, int fd)
{
  int		i;
  int		j;
  t_broad	broad;

  i = 0;
  j = 0;
  while (cmd[j] != ' ')
    j++;
  broad.x = player->posx;
  broad.y = player->posy;
  broad.msg = &cmd[j + 1];
  set_func_to_player(fd, &broad, send_broadcast);
}

void	do_fork(__attribute__((unused))char *cmd, t_player *player, int fd)
{
  printf("\033[0;31mSending message to %d :\033[0;0m ok\n", fd);
  fd_puts(fd, "ok\n");
  player->eggx = player->posx;
  player->eggy = player->posy;
  add_planning(parse.t, "\neclosion\n", fd);
}

