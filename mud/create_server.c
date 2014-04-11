/*
** create_server.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:06:54 2010 adrien folie
** Last update Thu Jul 15 02:46:50 2010 adrien folie
*/

#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tlist.h"
#include "serveur.h"
#include "utils.h"

void	server_read(t_env *e, int fd)
{
  add_client(e, fd);
}

void			create_server(t_env *e, int port)
{
  struct sockaddr_in	sin;

  if (port < 1 || port > 65000)
    port = 4242;
  if ((e->s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    aff_error("socket failed");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(e->s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
    aff_error("bind failed");
  printf("\033[0;33mListening on port %d...\033[0;0m\n", port);
  if (listen(e->s, SOMAXCONN) == -1)
    aff_error("listen failed");
  e->fds[e->s].type = FD_SERVER;
  e->fds[e->s].fct_read = server_read;
  e->fds[e->s].fct_write = NULL;
}
