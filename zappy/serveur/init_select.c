/*
** init.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 28 21:23:33 2010 adrien folie
** Last update Wed Jun 16 01:03:19 2010 edern bienvenu
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
#include "serveur.h"

void	clean_fd(t_fd *fd)
{
  fd->type = FD_FREE;
  fd->fct_read = NULL;
  fd->fct_write = NULL;
  fd->buf_read[0] = '\0';
  fd->buf_write[0] = '\0';
}

void	init_env(t_env *e)
{
  int	i;

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
