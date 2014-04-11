/*
** do_move.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri May 28 23:28:49 2010 edern bienvenu
** Last update Sun Jun 20 20:06:46 2010 adrien folie
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
#include "parsing.h"
#include "map.h"
#include "broad.h"
#include "food.h"

extern	t_teams	*teams;
extern	t_map	**map;
extern	t_parse	parse;

char	*inttostr(int nb);

void	new_pos(t_player *player)
{
  if (player->direct == UP)
    player->posx -= 1;
  else if (player->direct == DOWN)
    player->posx += 1;
  else if (player->direct == LEFT)
    player->posy -= 1;
  else if (player->direct == RIGHT)
    player->posy += 1;
  map[player->posx][player->posy].nb_player++;
}

void	do_avance(__attribute__((unused))char *cmd, t_player *player, int fd)
{
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
  else if (player->posy == 0 && player->direct == LEFT)
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
    new_pos(player);
  printf("\033[0;31mSending message to %d :\033[0;0m ok\n", fd);
  fd_puts(fd, "ok\n");
}

void	do_inventaire(__attribute__((unused))char *cmd, t_player *player, int fd)
{
  int	food;

  printf("\033[0;31mSending message to %d :\033[0;0m\n", fd);
  fd_puts(fd, "{nourriture ");
  food = get_food(fd, 0);
  fd_puts(fd, ",linemate ");
  fd_putnbr(fd, player->inv[LINEMATE]);
  fd_puts(fd ,",deraumere ");
  fd_putnbr(fd, player->inv[DERAUMERE]);
  fd_puts(fd, ",sibur ");
  fd_putnbr(fd, player->inv[SIBUR]);
  fd_puts(fd, ",mendiane ");
  fd_putnbr(fd, player->inv[MENDIANE]);
  fd_puts(fd, ",phiras ");
  fd_putnbr(fd, player->inv[PHIRAS]);
  fd_puts(fd, ",thystame ");
  fd_putnbr(fd, player->inv[THYSTAME]);
  fd_puts(fd, "}\n");
  printf("{nourriture %d,linemate %d,deraumere %d,sibur %d, \
mendiane %d,phiras %d,thystame %d}\n\n", food, player->inv[LINEMATE],
	 player->inv[DERAUMERE], player->inv[SIBUR], player->inv[MENDIANE],
	 player->inv[PHIRAS], player->inv[THYSTAME]);
}

void	do_expulse(__attribute__((unused))char *cmd,
		   __attribute__((unused))t_player *player, int fd)
{
  send_ko(fd);
}

void		do_mort(__attribute__((unused))char *cmd,
			__attribute__((unused))t_player *player, int fd)
{
  t_cbuff	*cbuff;

  cbuff = choose_buffer(fd);
  if (cbuff != NULL)
    cbuff->type = DEAD;
  printf("\033[0;31mSending message to %d : \033[0;0mmort\n\n", fd);
  fd_puts(fd, "mort\n");
}
