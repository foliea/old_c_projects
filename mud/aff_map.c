/*
** aff_map.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 01:33:15 2010 adrien folie
** Last update Mon Jul  5 18:36:02 2010 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
#include "tlist.h"
#include "room.h"

void		aff_obj(t_tlist *obj)
{
  t_telem	*tmp;

  printf("obj size : %d\n", obj->taille);
  tmp = obj->begin;
  while (obj->begin != NULL)
    {
      puts(obj->begin->data);
      obj->begin = obj->begin->next;
    }
  obj->begin = tmp;
}
void	aff_room(t_room *data)
{
  printf("id : %d\t\"%s\"\n", data->id, data->txt);
  printf("nord : %d\tsud : %d\test : %d\touest : %d\n",
	 data->nord,
	 data->sud,
	 data->est,
	 data->ouest);
  puts("obj :");
  aff_obj(data->obj);
}

void	aff_map(t_tlist *map)
{
  t_telem	*tmp;

  printf("map size : %d\n", map->taille);
  tmp = map->begin;
  while (map->begin != NULL)
    {
      puts("-- ROOM --");
      aff_room(map->begin->data);
      map->begin = map->begin->next;
      puts("----------");
    }
  map->begin = tmp;
}
