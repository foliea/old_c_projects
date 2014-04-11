/*
** get_things.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 01:24:08 2010 adrien folie
** Last update Mon Jul  5 01:34:00 2010 adrien folie
*/

#include <stdlib.h>
#include "tlist.h"
#include "cbuff.h"
#include "player.h"
#include "room.h"

t_player	*get_player(t_tlist *players, int fd)
{
  t_telem	*tmp;
  t_player	*player;

  tmp = players->begin;
  while (players->begin != NULL)
    {
      player = players->begin->data;
      if (player->fd == fd)
	{
	  players->begin = tmp;
	  return (player);
	}
      players->begin = players->begin->next;
    }
  players->begin = tmp;
  return (NULL);
}

t_room		*get_room(t_tlist *map, int id)
{
  t_telem	*tmp;
  t_room	*room;

  tmp = map->begin;
  while (map->begin != NULL)
    {
      room = map->begin->data;
      if (room->id == id)
	{
	  map->begin = tmp;
	  return (room);
	}
      map->begin = map->begin->next;
    }
  map->begin = tmp;
  return (NULL);
}
