/*
** do_move.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 01:20:21 2010 adrien folie
** Last update Mon Jul 12 23:29:22 2010 adrien folie
*/

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "tlist.h"
#include "cbuff.h"
#include "player.h"
#include "room.h"
#include "serveur.h"
#include "things.h"

void		do_nord(__attribute__((unused))char *cmd, t_env *e, int fd)
{
  t_player	*player;
  t_room	*room;

  if ((player = get_player(e->players, fd)) != NULL)
    if ((room = get_room(e->map, player->pos)) == NULL)
      return ;
  if (room->nord != 0)
    {
      if (get_room(e->map, room->nord) != NULL)
	{
	  player->pos = room->nord;
	  my_room(e, fd);
	}
    }
  else
    {
      stack_write(player->cwrite, "Impossible d'aller au nord\n");
      FD_SET(fd, &e->fd_write);
      FD_CLR(fd, &e->fd_read);
    }
}

void		do_sud(__attribute__((unused))char *cmd, t_env *e, int fd)
{
  t_player	*player;
  t_room	*room;

  if ((player = get_player(e->players, fd)) != NULL)
    if ((room = get_room(e->map, player->pos)) == NULL)
      return ;
  if (room->sud != 0)
    {
      if (get_room(e->map, room->sud) != NULL)
	{
	  player->pos = room->sud;
	  my_room(e, fd);
	}
    }
  else
    {
      stack_write(player->cwrite, "Impossible d'aller au sud\n");
      FD_SET(fd, &e->fd_write);
      FD_CLR(fd, &e->fd_read);
    }
}

void		do_est(__attribute__((unused))char *cmd, t_env *e, int fd)
{
  t_player	*player;
  t_room	*room;

  if ((player = get_player(e->players, fd)) != NULL)
    if ((room = get_room(e->map, player->pos)) == NULL)
      return ;
  if (room->est != 0)
    {
      if (get_room(e->map, room->est) != NULL)
	{
	  player->pos = room->est;
	  my_room(e, fd);
	}
    }
  else
    {
      stack_write(player->cwrite, "Impossible d'aller a l'est\n");
      FD_SET(fd, &e->fd_write);
      FD_CLR(fd, &e->fd_read);
    }
}

void		do_ouest(__attribute__((unused))char *cmd, t_env *e, int fd)
{
  t_player	*player;
  t_room	*room;

  if ((player = get_player(e->players, fd)) != NULL)
    if ((room = get_room(e->map, player->pos)) == NULL)
      return ;
  if (room->ouest != 0)
    {
      if (get_room(e->map, room->ouest) != NULL)
	{
	  player->pos = room->ouest;
	  my_room(e, fd);
	}
    }
  else
    {
      stack_write(player->cwrite, "Impossible d'aller a l'ouest\n");
      FD_SET(fd, &e->fd_write);
      FD_CLR(fd, &e->fd_read);
    }
}
