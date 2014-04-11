/*
** do_broadcast.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 01:57:30 2010 adrien folie
** Last update Mon Jul 12 23:29:54 2010 adrien folie
*/

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tlist.h"
#include "cbuff.h"
#include "player.h"
#include "room.h"
#include "serveur.h"
#include "things.h"

void		do_broadcast(t_env *e, t_tlist *players, int nb_room, char *msg)
{
  t_telem	*tmp;
  t_player	*player;

  if (strlen(msg) == 0 || strcmp("\n", msg) == 0)
    return ;
  tmp = players->begin;
  while (players->begin != NULL)
    {
      player = players->begin->data;
      if (nb_room == -1 || player->pos == nb_room)
	{
	  FD_SET(player->fd, &e->fd_write);
	  FD_CLR(player->fd, &e->fd_read);
	  stack_write(player->cwrite, msg);
	}
      players->begin = players->begin->next;
    }
  players->begin = tmp;
}

void	do_shout(char *cmd, t_env *e, __attribute__((unused))int fd)
{
  do_broadcast(e, e->players, -1, cmd + 6);
}

void		do_speak(char *cmd, t_env *e, int fd)
{
  t_player	*player;

  player = get_player(e->players, fd);
  if (player == NULL)
    return ;
  do_broadcast(e, e->players, player->pos, cmd + 6);
}
