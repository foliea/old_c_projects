/*
** init_env.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:07:59 2010 adrien folie
** Last update Mon Jul 12 23:05:25 2010 adrien folie
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
#include "utils.h"
#include "tlist.h"
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
