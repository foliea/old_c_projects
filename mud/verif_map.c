/*
** verif_map.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:11:33 2010 adrien folie
** Last update Thu Jul  8 04:48:53 2010 adrien folie
*/

#include <stdlib.h>
#include "tlist.h"
#include "room.h"
#include "utils.h"

void	verif_room(t_room *data, int size, int *rooms)
{
  if (data->id <= 0 || data->id > size)
    aff_error("map incorrect : a room have a bad id");
  if (data->nord == 0 && data->sud == 0 && data->est == 0 && data->ouest == 0)
    aff_error("map incorrect : a room have no link");
  if (data->nord < 0 || data->nord > size || data->nord == data->id)
    aff_error("map incorrect : a room have a incorrect link");
  if (data->sud < 0 || data->sud > size || data->sud == data->id)
    aff_error("map incorrect : a room have a incorrect link");
  if (data->est < 0 || data->est > size || data->est == data->id)
    aff_error("map incorrect : a room have a incorrect link");
  if (data->ouest < 0 || data->ouest > size || data->ouest == data->id)
    aff_error("map incorrect : a room have a incorrect link");
  rooms[data->id - 1] = OK;
}

void	verif_all(int *rooms, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      if (rooms[i] == NONE)
	aff_error("map incorrect : a room doesn't exist");
      ++i;
    }
}

void	set_rooms(int *rooms, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      rooms[i] = NONE;
      ++i;
    }
}

void		verif_map(t_tlist *map)
{
  t_telem	*tmp;
  int		*rooms;

  if (map->taille < 1)
    aff_error("map incorrect : empty");
  rooms = xmalloc(map->taille * sizeof(int));
  set_rooms(rooms, map->taille);
  tmp = map->begin;
  while (map->begin != NULL)
    {
      verif_room(map->begin->data, map->taille, rooms);
      map->begin = map->begin->next;
    }
  map->begin = tmp;
  verif_all(rooms, map->taille);
  free(rooms);
}
