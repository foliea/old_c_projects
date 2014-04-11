/*
** parse_mud.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 01:32:38 2010 adrien folie
** Last update Thu Jul 15 03:03:40 2010 adrien folie
*/

#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "utils.h"
#include "tlist.h"
#include "room.h"
#include "cbuff.h"
#include "remove.h"

void	free_room(t_room *room)
{
  free(room->txt);
  free_objs(room->obj);
  free(room->obj);
}

void		free_list_rooms(t_tlist *rooms)
{
  t_telem	*tmp;

  while (rooms->begin != NULL)
    {
      tmp = rooms->begin;
      rooms->begin = rooms->begin->next;
      free_room(tmp->data);
      free(tmp->data);
      free(tmp);
    }
}
