/*
** get_food.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri Jun 18 04:47:53 2010 edern bienvenu
** Last update Sun Jun 20 17:49:19 2010 edern bienvenu
*/

#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include "planning.h"
#include "parsing.h"
#include "fd_puts.h"

int	xgettimeofday(struct timeval *tv, struct timezone *tz);

extern t_tlist	*planning;
extern t_parse	parse;

struct timeval		*get_timeval_planning(int fd)
{
  t_telem		*tmp;
  struct timeval	*end;

  tmp = planning->begin;
  while (planning->begin)
    {
      if (planning->begin->fd == fd &&
	  strcmp(planning->begin->cmd, "mort\n") == 0)
	{
	  end = planning->begin->end;
	  planning->begin = tmp;
	  return (end);
	}
      planning->begin = planning->begin->next;
    }
  planning->begin = tmp;
  return (NULL);
}

int			get_food(int fd, int type)
{
  struct timeval	now;
  struct timeval	*end;
  struct timeval	res;
  float			add;
  int			diff;

  if ((end = get_timeval_planning(fd)) == NULL)
    return (-1);
  xgettimeofday(&now, NULL);
  timersub(end, &now, &res);
  add = res.tv_sec * 1000000 + res.tv_usec;
  diff = (add * parse.t) / 1000000;
  diff = diff / 126;
  if (type == 0)
    fd_putnbr(fd, diff);
  return (diff);
}
