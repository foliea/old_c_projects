/*
** obj.c for con2pute in /u/all/bienve_e/public/zappy/2_antoine/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Tue Jun  1 02:43:28 2010 antoine goueslard
** Last update Sun Jun 20 21:14:51 2010 antoine goueslard
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

t_act	*do_prend(int s, char *to_send, int fnbr, t_act *commands)
{
  int	i;
  char	*line;

  i = can_do(s, commands);
  if (i != 10)
    {
      if ((line = calloc(1024, sizeof(*line))) == 0)
	exit(EXIT_FAILURE);
      line = strcat(line, "prend ");
      line = strcat(line, to_send);
      line = strcat(line, "\n");
      commands = add_commands(fnbr, to_send, 7, commands);
      my_puts(s, line);
      free(line);
    }
  return (commands);
}

t_act	*do_pose(int s, char *to_send, int fnbr, t_act *commands)
{
  int	i;
  char	*line;

  i = can_do(s, commands);
  if (i != 10)
    {
      if ((line = calloc(1024, sizeof(*line))) == 0)
	exit(EXIT_FAILURE);
      line = strcat(line, "pose ");
      line = strcat(line, to_send);
      line = strcat(line, "\n");
      commands = add_commands(fnbr, to_send, 7, commands);
      my_puts(s, line);
    }
  return (commands);
}

t_act	*do_inv(int s, char *to_send, int fnbr, t_act *commands)
{
  int	i;

  i = can_do(s, commands);
  to_send = 0;
  if (i != 10)
    {
      commands = add_commands(fnbr, NULL, 7, commands);
      my_puts(s, "inventaire\n");
    }
  return (commands);
}

t_act	*do_fork(int s, char *to_send, int fnbr, t_act *commands)
{
  int	i;

  i = can_do(s, commands);
  to_send = 0;
  if (i != 10)
    {
      commands = add_commands(fnbr, NULL, 7, commands);
      my_puts(s, "fork\n");
    }
  return (commands);
}

t_act	*do_inc(int s, char *to_send, int fnbr, t_act *commands)
{
  int	i;

  i = can_do(s, commands);
  to_send = 0;
  if (i != 10)
    {
      printf("*****\n******\n*****\n ELEVATION ***\n***\n");
      printf("*****\n******\n*****\n ELEVATION ***\n***\n");
      printf("*****\n******\n*****\n ELEVATION ***\n***\n");
      printf("*****\n******\n*****\n ELEVATION ***\n***\n");
      printf("*****\n******\n*****\n ELEVATION ***\n***\n");
      commands = add_commands(fnbr, NULL, 300, commands);
      my_puts(s, "incantation\n");
    }
  return (commands);
}
