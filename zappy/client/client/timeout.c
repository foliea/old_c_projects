/*
** timeout.c for  in /u/all/bienve_e/public/zappy/2_antoine/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Mon May 31 03:21:53 2010 antoine goueslard
** Last update Sat Jun 19 11:40:03 2010 antoine goueslard
*/

#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include "client.h"


void	xtimeofday(struct timeval *tp, struct timezone *tzp)
{
  if (gettimeofday(tp, tzp) == -1)
    {
      put_error(" Errod in get time of day , your system is a shit\n");
    }
}

void	check_timeout(int s, struct timeval timeout)
{
  struct timeval newtime;
 
 if (timeout.tv_sec != -1)
    {
      xtimeofday(&newtime, NULL);
      if (newtime.tv_sec > (timeout.tv_sec + 300))
	{
	  close(s);
	  put_error("LINK DOWN\n");
	}
    }
}

struct timeval		uptimeout(int sec, struct timeval timeout)
{
  struct timeval	newtime;

  xtimeofday(&newtime,NULL);
  if (timeout.tv_sec == -1 || newtime.tv_sec > timeout.tv_sec)
    xtimeofday(&timeout, NULL);
   timeout.tv_sec += sec;
   return (timeout);
}

int	can_do(int s, t_act *commands)
{
  int	i;
  t_act	*begin;

  i = 0;
  begin = commands;
  while (begin != NULL)
    {
      check_timeout(s, begin->timeout);
      begin = begin->next;
      i++;
    }
  return (i);
}

t_act			*add_commands(int fnbr,
				      char *paramc,
				      int cooldown,
				      t_act *commands)
{
  struct timeval	timeout;
  t_act			*begin;
  t_act			*new;

  if ((new = malloc(sizeof(*new))) == 0)
    exit(EXIT_FAILURE);
  xtimeofday(&timeout, NULL);
  new->fnbr = fnbr;
  new->paramc = paramc;
  begin = commands;
  while (begin != NULL && begin->next != NULL)
    {
      if (begin->timeout.tv_sec > timeout.tv_sec)
	timeout = begin->timeout;
      begin = begin->next;
    }
  new->timeout = uptimeout(cooldown, timeout);
  new->next = NULL;
  if (begin != NULL)
    begin->next = new;
  else
    commands = new;
  return (commands);
}
