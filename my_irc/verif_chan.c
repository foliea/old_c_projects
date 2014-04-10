/*
** verif_chan.c for verif chan in /u/all/folie_a/public/dedern/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Apr 28 04:33:45 2010 edern bienvenu
** Last update Wed Apr 28 21:24:34 2010 edern bienvenu
*/

#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include "irc.h"

extern struct s_serv	sdata;

int		verif_chan(char *name, int fd)
{
  t_channel	*temp;
  t_dchan	*list;

  list = &(sdata.chan);
  temp = list->begin;
  while (list->begin)
    {
      if (strcmp(name, list->begin->name) == 0)
	{
	  my_put_in_dlist(&(list->begin->users), whois(fd), fd, 1);
	  list->begin = temp;
	  return (1);
	}
      list->begin = list->begin->next;
    }
  list->begin = temp;
  return (0);
}

void		r_who(char **arg, t_dlist *list)
{
  int		i;
  int		j;
  char		*res;
  t_client	*temp;

  j = 1;
  i = tablen(arg);
  temp = list->begin;
  if (i == 2)
    {
      res = my_strcat("/rwho ", arg[1]);
      res = my_strcat(res, " ");
      while (list->begin)
	{
	  res = my_strcat(res, list->begin->login);
	  res = my_strcat(res, "\n");
	  list->begin = list->begin->next;
	}
      list->begin = temp;
      send_msg_all(res, arg[1]);
    }
  list->begin = temp;
}
