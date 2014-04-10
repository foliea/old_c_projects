/*
** modif_nick.c for my irc in /u/all/folie_a/public/dedern/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Apr 28 21:25:34 2010 edern bienvenu
** Last update Wed Apr 28 21:34:44 2010 edern bienvenu
*/

#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include "irc.h"

extern	struct s_serv	sdata;

void		modif_nick(int fd, t_dlist *list, char *login)
{
  t_client	*tmp;

  tmp = list->begin;
  while (list->begin)
    {
      if (fd == list->begin->fd)
	{
	  list->begin->login = strdup(login);
	  list->begin = tmp;
	  return ;
	}
      list->begin = list->begin->next;
    }
  list->begin = tmp;
  return ;
}

void		modif_nick_chan(int fd, char *login)
{
  t_channel	*tmp;
  t_dchan	*dchan;

  dchan = &(sdata.chan);
  tmp = dchan->begin;
  while (tmp)
    {
      modif_nick(fd, &(tmp->users), login);
      tmp = tmp->next;
    }
  tmp = dchan->begin; 
}
