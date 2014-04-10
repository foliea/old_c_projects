/*
** whois.c for myirc in /u/all/folie_a/public/dedern/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Apr 28 01:16:17 2010 edern bienvenu
** Last update Wed Apr 28 17:59:54 2010 edern bienvenu
*/

#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include "irc.h"

extern struct	s_serv	sdata;

char		*whois(int fd)
{
  t_client	*temp;
  t_dlist	*list;
  char		*login;

  list = &(sdata.user);
  temp = list->begin;
  while (list->begin)
    {
      if (fd == list->begin->fd)
	{
	  login = strdup(list->begin->login);
	  list->begin = temp;
	  return (login);
	}
      list->begin = list->begin->next;
    }
  list->begin = temp;
  return (NULL);
}
