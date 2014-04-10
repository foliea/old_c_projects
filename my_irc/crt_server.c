/*
** server.c for my irc in /u/all/bienve_e/rendu/c/my_irc/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 26 14:10:06 2010 edern bienvenu
** Last update Wed Apr 28 19:28:31 2010 edern bienvenu
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

void	server_read(t_env *e, int fd)
{
  add_client(e, fd);
}

void			add_server(t_env *e)
{
  int			s;
  struct sockaddr_in	sin;

  e->fds = xmalloc(sizeof(*e->fds) * e->maxfd);
  s = socket(PF_INET, SOCK_STREAM, 0);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  bind(s, (struct sockaddr*)&sin, sizeof(sin));
  listen(s, 42);
  e->fds[s].type = FD_SERVER;
  e->fds[s].fct_read = server_read;
  e->fds[s].fct_write = NULL;
}

void	create_srv(t_env *e, struct timeval *tv)
{
  add_server(e);
  tv->tv_sec = 5;
  tv->tv_usec = 0;
}
