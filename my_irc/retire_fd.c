/*
** retire_fd.c for my irc in /u/all/folie_a/public/dedern/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Apr 28 09:42:18 2010 edern bienvenu
** Last update Mon Jul  5 02:15:54 2010 adrien folie
*/

#include <stdlib.h>
#include <sys/select.h>
#include "irc.h"

extern	struct s_serv	sdata;

void		getoff_fd(int fd, t_dlist *list)
{
  t_client	*tmp;

  tmp = list->begin;
  while (list->begin)
    {
      if (fd == list->begin->fd)
	{
	  if (list->begin->next != NULL)
	    {
	      list->begin->next = list->begin->next->next;
	      list->begin = list->begin->next->next->prev;
	      list->begin = tmp;
	      list->taille--;
	    }
	  else
	    my_init_dlist(list);
	  return ;
	}
      list->begin = list->begin->next;
    }
  list->begin = tmp;
  return ;
}

void		getoff_fd_chan(int fd)
{
  t_channel	*tmp;
  t_dchan	*dchan;

  dchan = &(sdata.chan);
  tmp = dchan->begin;
  while (tmp)
    {
      getoff_fd(fd, &(tmp->users));
      tmp = tmp->next;
    }
  tmp = dchan->begin;
}
