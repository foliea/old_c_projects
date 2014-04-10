/*
** serveur_main.c for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Apr  2 01:55:41 2010 adrien folie
** Last update Sun Apr 18 19:48:03 2010 adrien folie
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"
#include "get_next_line.h"

void	read_client_cmd(int cs, char *path)
{
  char	*line;
  int	nb_read;

  if (dup2(cs, 1) == -1)
    aff_error("Function dup2 failed");
  line = xmalloc(sizeof(char) * 1024);
  while (42)
    {
      memset(line, 0, 1024);
      nb_read = xread(cs, line, 1024);
      if (nb_read > 0)
	serveur_cmd(line, cs, path);
    }
  free(line);
}

int	fork_new_client(int cs, char *path)
{
  pid_t	child;


  if ((child = fork()) == -1)
    aff_error("Function fork failed");
  if (child == 0)
    {
      xwrite(cs, "Welcome to my_ftp\n", 18);
      read_client_cmd(cs, path);
    }
  return (0);
}

void			connect_to_client(int s, char *path)
{
  int			cs;
  struct sockaddr_in	client_sin;
  int			client_sin_len;

  client_sin_len = sizeof(client_sin);
  cs = accept(s, (struct sockaddr *) &client_sin,
	      (socklen_t *) &client_sin_len);
  if (cs == -1)
    return ;
  printf("connection from %s %d\n",
	 inet_ntoa(client_sin.sin_addr),
	 ntohs(client_sin.sin_port));
  fork_new_client(cs, path);
  close(cs);
}

void	loop_server(int s, char *path)
{
   while (42)
    {
      if (listen(s, 42) == 0)
	connect_to_client(s, path);
    }
  close(s);
}

int			main(int ac, char **av)
{
  int			s;
  struct protoent	*pe;
  struct sockaddr_in	sin;
  int			port;
  char			*path;

  if (ac != 2)
    aff_error("usage ./serveur [port]");
  pe = getprotobyname("tcp");
  if ((s = socket(PF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    aff_error("Function socket failed");
  if ((port = atoi(av[1])) <= 0)
    aff_error("port invalid");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (struct sockaddr *) &sin, sizeof(sin)) == -1)
    aff_error("Function bind failed");
  path = xmalloc(4096 * sizeof(char));
  memset(path, 0, 4096);
  if (getcwd(path, 4096) == NULL)
    aff_error("Security Exit, impossible to get first repertory");
  loop_server(s, path);
  return (0);
}
