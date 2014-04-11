/*
** create_serveur.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 28 21:28:47 2010 adrien folie
** Last update Sun Jun 27 02:55:50 2010 adrien folie
*/

#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"
#include "parsing.h"
#include "player.h"

extern t_parse parse;
extern t_dteam *team;

void	server_read(t_env *e, int fd)
{
  add_client(e, fd);
}

void			add_server(t_env *e)
{
  struct sockaddr_in	sin;

  e->fds = xmalloc(sizeof(*e->fds) * e->maxfd);
  if ((parse.s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    aff_error("socket failed");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(parse.s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    aff_error("bind failed");
  printf("\033[0;33mListening on port %d...\033[0;0m\n", e->port);
  if (listen(parse.s, 42) == -1)
    aff_error("listen failed");
  e->fds[parse.s].type = FD_SERVER;
  e->fds[parse.s].fct_read = server_read;
  e->fds[parse.s].fct_write = NULL;
}

void	create_srv(t_env *e, struct timeval *tv)
{
  add_server(e);
  tv->tv_sec = 5;
  tv->tv_usec = 0;
}
