/*
** loop.c for loop in /u/all/bienve_e/rendu/c/my_irc/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 26 14:08:33 2010 edern bienvenu
** Last update Wed Apr 28 05:49:42 2010 edern bienvenu
*/

#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "irc.h"

void	set_fd(t_env *e)
{
  int	i;

  i = 0;
  e->max = 0;
  FD_ZERO(&e->fd_read);
  FD_ZERO(&e->fd_write);
  while (i < e->maxfd)
    {
      if (e->fds[i].type != FD_FREE)
        {
          FD_SET(i, &e->fd_read);
          if (my_strlen(e->fds[i].buf_write) > 0)
	    FD_SET(i, &e->fd_write);
          e->max = MAX(e->max, i);
        }
      i++;
    }
}

void	verif_fd(t_env *e)
{
  int	i;

  i = 0;
  while ((i < e->maxfd) && (e->r > 0))
    {
      if (FD_ISSET(i, &e->fd_read))
        e->fds[i].fct_read(e, i);
      if (FD_ISSET(i, &e->fd_write))
        e->fds[i].fct_write(e, i);
      if (FD_ISSET(i, &e->fd_read) ||
          FD_ISSET(i, &e->fd_write))
        e->r--;
      i++;
    }
  return ;
}

void	loop(t_env *e)
{
  while (42)
    {
      set_fd(e);
      e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, NULL);
      verif_fd(e);
    }
}
