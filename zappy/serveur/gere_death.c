/*
** gere_death.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jun 14 04:37:48 2010 adrien folie
** Last update Sun Jun 20 15:07:41 2010 adrien folie
*/

#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include "planning.h"
#include "serveur.h"

extern t_tlist	*planning;

int			add_death(int t, int fd)
{
  struct timeval	now;
  struct timeval	*end;
  float			add;
  int			diff;
  char			*cmd;

  diff = 1260;
  cmd = strdup("mort\n");
  if (cmd == NULL)
    aff_error("strdup failed");
  if (gettimeofday(&now, NULL) == -1)
    aff_error("gettimeofday failed");
  end = xmalloc(sizeof(struct timeval));
  add = ((float) diff / (float) t) * 1000000.;
  end->tv_sec = now.tv_sec + (long) add / 1000000;
  end->tv_usec = now.tv_usec + (long) add % 1000000;
  insert_tlist(planning, cmd, fd, end);
  return (0);
}
