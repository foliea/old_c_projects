/*
** aff_map.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 01:33:15 2010 adrien folie
** Last update Tue Jul 13 03:08:48 2010 adrien folie
*/

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include "cbuff.h"
#include "tlist.h"
#include "room.h"
#include "player.h"
#include "serveur.h"
#include "utils.h"
#include "things.h"

void		list_obj(t_tlist *obj,
			 t_cbuff *cwrite,
			 __attribute__((unused))int fd,
			 int mode)
{
  t_telem	*tmp;

  if (obj->taille == 0 && mode == 0)
    stack_write(cwrite, "Il n'y a aucun objet ici\n");
  else if (obj->taille == 0 && mode == 1)
    stack_write(cwrite, "Votre inventaire est vide\n");
  tmp = obj->begin;
  while (obj->begin != NULL)
    {
      stack_write(cwrite, obj->begin->data);
      if (obj->begin->next == NULL)
	stack_write(cwrite, "\n");
      else
	stack_write(cwrite, ", ");
      obj->begin = obj->begin->next;
    }
  obj->begin = tmp;
}

void		do_voir(__attribute__((unused))char *cmd, t_env *e, int fd)
{
  t_player	*player;
  t_room	*room;
  t_cbuff	*cwrite;

  if ((player = get_player(e->players, fd)) == NULL)
    return ;
  if ((room = get_room(e->map, player->pos)) == NULL)
    return ;
  if ((cwrite = choose_buffer(e->players, fd, CWRITE)) == NULL)
    return ;
  list_obj(room->obj, cwrite, fd, 0);
  FD_SET(fd, &e->fd_write);
  FD_CLR(fd, &e->fd_read);
}

void		do_inv(__attribute__((unused))char *cmd, t_env *e, int fd)
{
  t_player	*player;
  t_cbuff	*cwrite;

  if ((player = get_player(e->players, fd)) == NULL)
    return ;
  if ((cwrite = choose_buffer(e->players, fd, CWRITE)) == NULL)
    return ;
  list_obj(player->obj, cwrite, fd, 1);
  FD_SET(fd, &e->fd_write);
  FD_CLR(fd, &e->fd_read);
}

void		my_room(t_env *e, int fd)
{
  t_player	*player;
  t_room	*room;
  t_cbuff	*cwrite;

  if ((player = get_player(e->players, fd)) == NULL)
    return ;
  if ((room = get_room(e->map, player->pos)) == NULL)
    return ;
  if ((cwrite = choose_buffer(e->players, fd, CWRITE)) == NULL)
    return ;
  stack_write(cwrite, room->txt);
  stack_write(cwrite, "\n* Sorties :");
  if (room->nord != 0)
    stack_write(cwrite, " nord");
  if (room->sud != 0)
    stack_write(cwrite, " sud");
  if (room->est != 0)
    stack_write(cwrite, " est");
  if (room->ouest != 0)
    stack_write(cwrite, " ouest");
  stack_write(cwrite, "\n");
  FD_SET(fd, &e->fd_write);
  FD_CLR(fd, &e->fd_read);
}

void	do_room(__attribute__((unused))char *cmd, t_env *e, int fd)
{
  my_room(e, fd);
}
