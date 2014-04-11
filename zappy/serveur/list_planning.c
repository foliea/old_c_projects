/*
** list_planning.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Sat May 29 00:58:22 2010 adrien folie
** Last update Sun Jun 20 17:12:41 2010 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include "planning.h"
#include "serveur.h"

void	init_tlist(t_tlist *list)
{
  list->begin = NULL;
  list->taille = 0;
}

void	insert_tlist(t_tlist *list, char *cmd, int fd, struct timeval *end)
{
  t_telem	*new;
  t_telem	*save;
  t_telem	*temp;
  int		i;

  i = 0;
  new = xmalloc(sizeof(struct s_telem));
  new->end = end;
  new->cmd = cmd;
  new->fd = fd;
  save = list->begin;
  while (list->begin != NULL && timercmp(end, list->begin->end, > ) != 0)
    {
      temp = list->begin;
      list->begin = list->begin->next;
      ++i;
    }
  new->next = list->begin;
  if (i == 0)
    list->begin = new;
  else
    {
      temp->next = new;
      list->begin = save;
    }
  list->taille++;
}
