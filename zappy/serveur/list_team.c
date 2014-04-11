/*
** list_player.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Tue Jun  1 16:40:50 2010 edern bienvenu
** Last update Sun Jun 20 17:41:39 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/select.h>
#include "serveur.h"
#include "parsing.h"
#include "death.h"
#include "player.h"
#include "map.h"
#include "fd_puts.h"

extern t_parse	parse;
extern t_map	**map;

void	my_init_dteam(t_dteam *team)
{
  team->begin = NULL;
  team->end = NULL;
  team->taille = 0;
}

void	init_inventory(t_player *new)
{
  new->inv[FOOD] = 10;
  new->inv[LINEMATE] = 0;
  new->inv[DERAUMERE] = 0;
  new->inv[SIBUR] = 0;
  new->inv[MENDIANE] = 0;
  new->inv[PHIRAS] = 0;
  new->inv[THYSTAME] = 0;
}

void		my_put_empty_dteam(t_dteam *team, int fd)
{
  t_player	*new;

  new = xmalloc(sizeof(*new));
  new->fd = fd;
  new->direct = 0;
  new->lvl = 1;
  new->posx = rand() % (parse.height - 1);
  new->posy = rand() % (parse.width - 1);
  map[new->posx][new->posy].nb_player++;
  fd_putnbr(fd, parse.height);
  fd_puts(fd, " ");
  fd_putnbr(fd, parse.width);
  fd_puts(fd, "\n");
  printf("\033[0;31mSending message to %d : \033[0;0m%d %d\n\n",
	 fd, parse.height, parse.width);
  init_inventory(new);
  add_death(parse.t, fd);
  new->next = NULL;
  new->prev = NULL;
  team->begin = new;
  team->end = new;
  team->taille++;
}

void		my_put_begin_dteam(t_dteam *team, int fd)
{
  t_player	*new;

  new = xmalloc(sizeof(*new));
  new->fd = fd;
  new->lvl = 1;
  new->direct = 0;
  new->posx = rand() % (parse.height - 1);
  new->posy = rand() % (parse.width - 1);
  map[new->posx][new->posy].nb_player++;
  fd_putnbr(fd, parse.height);
  fd_puts(fd, " ");
  fd_putnbr(fd, parse.width);
  fd_puts(fd, "\n");
  printf("\033[0;31mSending message to %d : \033[0;0m%d %d\n\n",
	 fd, parse.height, parse.width);
  add_death(parse.t, fd);
  init_inventory(new);
  new->next = team->begin;
  new->prev = NULL;
  team->begin->prev = new;
  team->begin = new;
  team->taille++;
}

void		my_put_end_dteam(t_dteam *team, int fd)
{
  t_player	*new;

  new = xmalloc(sizeof(*new));
  new->fd = fd;
  new->lvl = 1;
  new->direct = 0;
  new->posx = rand() % (parse.height - 1);
  new->posy = rand() % (parse.width - 1);
  map[new->posx][new->posy].nb_player++;
  fd_putnbr(fd, parse.height);
  fd_puts(fd, " ");
  fd_putnbr(fd, parse.width);
  fd_puts(fd, "\n");
  printf("\033[0;31mSending message to %d : \033[0;0m%d %d\n\n",
	 fd, parse.height, parse.width);
  add_death(parse.t, fd);
  init_inventory(new);
  new->next = NULL;
  new->prev = team->end;
  team->end->next = new;
  team->end = new;
  team->taille++;
}

void		my_put_in_dteam(t_dteam *team, int fd, int sort)
{
  if (team->taille == 0)
    my_put_empty_dteam(team, fd);
  else if (sort == 1)
    my_put_end_dteam(team, fd);
  else
    my_put_begin_dteam(team, fd);
}
