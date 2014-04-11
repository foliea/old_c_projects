/*
** take_drop.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 02:53:55 2010 adrien folie
** Last update Mon Jul 12 23:28:02 2010 adrien folie
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
#include "remove.h"

int		check_in_room(t_tlist *room_obj, char *obj)
{
  t_telem	*tmp;

  if (strlen(obj) == 0)
    return (-1);
  tmp = room_obj->begin;
  while (room_obj->begin != NULL)
    {
      if (strcmp(room_obj->begin->data, obj) == 0)
	{
	  room_obj->begin = tmp;
	  return (0);
	}
      room_obj->begin = room_obj->begin->next;
    }
  room_obj->begin = tmp;
  return (-1);
}

void		do_take(char *cmd, t_env *e, int fd)
{
  t_player	*player;
  t_room	*room;

  if ((player = get_player(e->players, fd)) == NULL)
    return ;
  if ((room = get_room(e->map, player->pos)) == NULL)
    return ;
  cmd[strlen(cmd) -1] = '\0';
  if (check_in_room(room->obj, cmd + 5) == -1)
    {
      stack_write(player->cwrite, "Cet objet n'existe pas\n");
      FD_SET(fd, &e->fd_write);
      FD_CLR(fd, &e->fd_read);
    }
  else
    {
      put_in_tlist(player->obj, strdup(cmd + 5), 1);
      ret_obj(room->obj, cmd + 5);
    }
}

int		check_in_inv(t_tlist *inv_obj, char *obj)
{
  t_telem	*tmp;

  if (strlen(obj) == 0)
    return (-1);
  tmp = inv_obj->begin;
  while (inv_obj->begin != NULL)
    {
      if (strcmp(inv_obj->begin->data, obj) == 0)
	{
	  inv_obj->begin = tmp;
	  return (0);
	}
      inv_obj->begin = inv_obj->begin->next;
    }
  inv_obj->begin = tmp;
  return (-1);
}

void		do_drop(char *cmd, t_env *e, int fd)
{
  t_player	*player;
  t_room	*room;

  if ((player = get_player(e->players, fd)) == NULL)
    return ;
  if ((room = get_room(e->map, player->pos)) == NULL)
    return ;
  cmd[strlen(cmd) -1] = '\0';
  if (check_in_inv(player->obj, cmd + 5) == -1)
    {
      stack_write(player->cwrite, "Cet objet n'existe pas\n");
      FD_SET(fd, &e->fd_write);
      FD_CLR(fd, &e->fd_read);
    }
  else
    {
      put_in_tlist(room->obj, strdup(cmd + 5), 1);
      ret_obj(player->obj, cmd + 5);
    }
}

void		do_food(__attribute__((unused))char *cmd, t_env *e, int fd)
{
  t_player	*player;
  t_room	*room;

  if ((player = get_player(e->players, fd)) == NULL)
    return ;
  if ((room = get_room(e->map, player->pos)) == NULL)
    return ;
  if (check_in_room(room->obj, "food") != -1)
    {
      player->life += FOOD;
      ret_obj(room->obj, "food");
    }
  else
    {
      stack_write(player->cwrite, "Cet objet n'existe pas\n");
      FD_SET(fd, &e->fd_write);
      FD_CLR(fd, &e->fd_read);
    }
}
