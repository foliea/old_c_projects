/*
** cmd_queue.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Jun 16 00:36:55 2010 edern bienvenu
** Last update Sun Jun 20 18:47:44 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include "cbuff.h"
#include "planning.h"

void	aff_queue(t_cbuff *cbuff)
{
  int	i;

  i = 0;
  while (i < cbuff->empty)
    {
      puts(cbuff->queue[i]);
      ++i;
    }
}

void	cmd_queue(t_cbuff *cbuff, int t, char *cmd, int fd)
{
  int	check;

  check = 0;
  if (cbuff->empty == 10)
    {
      printf("\033[0;33mWarning : too many request for $%d, \
ignore :\033[0;0m  %s\n",
	     fd, cmd);
      return ;
    }
  if (cbuff->empty == 0)
    check = add_planning(t, cmd, fd);
  if (check == 0)
    {
      cbuff->queue[cbuff->empty] = cmd;
      cbuff->empty++;
    }
}

void	move_queue(t_cbuff *cbuff, int t,
		   __attribute__((unused))char *cmd, int fd)
{
  int	i;

  if (cbuff->empty == 0)
    return ;
  i = 0;
  cbuff->empty--;
  free(cbuff->queue[0]);
  while (i < cbuff->empty)
    {
      cbuff->queue[i] = cbuff->queue[i + 1];
      ++i;
    }
  cbuff->queue[cbuff->empty] = NULL;
  if (cbuff->empty != 0)
    add_planning(t, cbuff->queue[0], fd);
}

void	init_queue(t_cbuff *cbuff)
{
  int	i;

  i = 0;
  while (i < MAX_QUEUE)
    {
      cbuff->queue[i] = NULL;
      ++i;
    }
  cbuff->empty = 0;
}
