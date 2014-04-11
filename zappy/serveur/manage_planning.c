/*
** manage_planning.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon May 31 00:45:15 2010 adrien folie
** Last update Sun Jun 20 19:38:36 2010 adrien folie
*/

#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "planning.h"
#include "cbuff.h"
#include "serveur.h"

struct timeval		*manage_planning(t_tlist *planning)
{
  struct timeval	tmp;
  struct timeval	*res;

  if (planning->taille == 0)
    return (NULL);
  gettimeofday(&tmp, NULL);
  res = xmalloc(sizeof(struct timeval));
  timersub(planning->begin->end, &tmp, res);
  return (res);
}

void		exec_planning(t_tlist *planning, int t)
{
  t_cbuff	*cbuff;

  if (planning->taille == 0)
    return ;
  cbuff = choose_buffer(planning->begin->fd);
  if (cbuff != NULL && cbuff->type != DEAD)
    find_cmd(planning->begin->cmd, planning->begin->fd);
  if (cbuff == NULL || cbuff->type == DEAD ||
      (cbuff->type != DEAD && strcmp(planning->begin->cmd, "mort\n") != 0))
    {
      free(planning->begin->end);
      planning->begin = planning->begin->next;
      planning->taille--;
    }
  if (cbuff != NULL && planning->taille > 0 && cbuff->type != DEAD)
    move_queue(cbuff, t, planning->begin->cmd, planning->begin->fd);
}

int		remove_middle_planning(t_tlist *planning, int fd)
{
  t_telem	*save;
  t_telem	*tmp;

  save = planning->begin;
  while (planning->begin != NULL)
    {
      if (planning->begin->next != NULL && planning->begin->next->fd == fd)
	{
	  tmp = planning->begin->next;
	  planning->begin->next = planning->begin->next->next;
	  planning->taille--;
	  free(tmp->cmd);
	  free(tmp->end);
	  free(tmp);
	  planning->begin = save;
	  return (-1);
	}
      planning->begin = planning->begin->next;
    }
  planning->begin = save;
  return (0);
}

int		remove_in_planning(t_tlist *planning, int fd)
{
  t_telem	*tmp;

  if (planning->taille > 0 && planning->begin->fd == fd)
    {
      tmp = planning->begin;
      planning->begin = planning->begin->next;
      planning->taille--;
      free(tmp->cmd);
      free(tmp->end);
      free(tmp);
      return (-1);
    }
  else
    return (remove_middle_planning(planning, fd));
}

void	ret_planning(t_tlist *planning, int fd)
{
  while (remove_in_planning(planning, fd) == -1)
    {
      if (planning->taille == 0)
	init_tlist(planning);
    }
}
