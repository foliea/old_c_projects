/*
** get_food.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri Jun 18 04:47:53 2010 edern bienvenu
** Last update Sun Jun 20 18:14:06 2010 edern bienvenu
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include "planning.h"
#include "parsing.h"
#include "player.h"
#include "map.h"
#include "food.h"
#include "fd_puts.h"

#define NEW_FOOD 126

void	*xmalloc(int size);

extern t_tlist	*planning;
extern t_parse	parse;
extern t_map	**map;

int		remove_middle_death(t_tlist *planning, int fd)
{
  t_telem	*save;
  t_telem	*tmp;

  save = planning->begin;
  while (planning->begin != NULL)
    {
      if (planning->begin->next != NULL &&
	  planning->begin->next->fd == fd
	  && strcmp(planning->begin->next->cmd, "mort\n") == 0)
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

int		remove_death(t_tlist *planning, int fd)
{
  t_telem	*tmp;

  if (planning->taille > 0 &&
      planning->begin->fd == fd
      && strcmp(planning->begin->cmd, "mort\n") == 0)
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
    remove_middle_death(planning, fd);
  return (0);
}

void			add_food(int fd, int x, int y)
{
  struct timeval	*end;
  struct timeval	*res;
  float			add;

  if (map[x][y].spot[FOOD] == 0)
    {
      printf("\033[0;31mSending message to %d :\033[0;0m ko\n", fd);
      fd_puts(fd, "ko\n");
      return ;
    }
  if ((end = get_timeval_planning(fd)) == NULL)
    {
      printf("\033[0;31mSending message to %d :\033[0;0m ko\n", fd);
      fd_puts(fd, "ko\n");
      return ;
    }
  res = xmalloc(sizeof(struct timeval));
  add = ((float) NEW_FOOD / (float) parse.t) * 1000000.;
  res->tv_sec = end->tv_sec + (long) add / 1000000;
  res->tv_usec = end->tv_usec + (long) add % 1000000;
  remove_death(planning, fd);
  map[x][y].spot[FOOD]--;
  insert_tlist(planning, strdup("mort\n"), fd, res);
  printf("\033[0;31mSending message to %d :\033[0;0m ok\n", fd);
  fd_puts(fd, "ok\n");
}

void			ret_food(int fd, int x, int y)
{
  struct timeval	*end;
  struct timeval	*res;
  float			add;

  if ((end = get_timeval_planning(fd)) == NULL || get_food(fd, 1) == 0)
    {
      printf("\033[0;31mSending message to %d :\033[0;0m ko\n", fd);
      fd_puts(fd, "ko\n");
      return ;
    }
  res = xmalloc(sizeof(struct timeval));
  add = ((float) NEW_FOOD / (float) parse.t) * 1000000.;
  res->tv_sec = end->tv_sec - (long) add / 1000000;
  res->tv_usec = end->tv_usec - (long) add % 1000000;
  remove_death(planning, fd);
  map[x][y].spot[FOOD]++;
  insert_tlist(planning, strdup("mort\n"), fd, res);
  printf("\033[0;31mSending message to %d :\033[0;0m ok\n", fd);
  fd_puts(fd, "ok\n");
}
