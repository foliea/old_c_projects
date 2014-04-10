/*
** send_msg_all.c for my irc in /u/all/folie_a/public/dedern/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Apr 28 05:32:59 2010 edern bienvenu
** Last update Wed Apr 28 21:23:56 2010 edern bienvenu
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include "irc.h"

extern struct	s_serv	sdata;

void		sending(t_dlist *list, char *msg)
{
  t_client	*temp;

  temp = list->begin;
  while (list->begin != NULL)
    {
      write(list->begin->fd, msg, strlen(msg));
      list->begin = list->begin->next;
    }
  list->begin = temp;
}

void		send_msg_all(char *msg, char *chan)
{
  t_channel	*temp;
  t_dchan	*list;

  list = &(sdata.chan);
  temp = list->begin;
  while (list->begin)
    {
      if (strcmp(chan, list->begin->name) == 0)
	{
	  sending(&(list->begin->users), msg);
	  list->begin = temp;
	  return ;
	}
      list->begin = list->begin->next;
    }
  list->begin = temp;
  return ;
}
