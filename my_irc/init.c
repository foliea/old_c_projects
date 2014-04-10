/*
** init.c for my irc in /u/all/bienve_e/rendu/c/my_irc/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 26 14:09:39 2010 edern bienvenu
** Last update Wed Apr 28 19:24:03 2010 edern bienvenu
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

void	clean_fd(t_fd *fd)
{
  fd->type = FD_FREE;
  fd->fct_read = NULL;
  fd->fct_write = NULL;
  fd->buf_read[0] = '\0';
  fd->buf_write[0] = '\0';
}

void		init_env(t_env *e)
{
  int		i;

  e->maxfd = OPEN_MAX;
  e->fds = xmalloc(sizeof(*e->fds) * e->maxfd);
  i = 0;
  while (i < e->maxfd)
    {
      clean_fd(&e->fds[i]);
      i++;
    }
  return ;
}
