/*
** client_main.c for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Apr  2 02:12:33 2010 adrien folie
** Last update Sun Apr 18 19:48:58 2010 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include "client.h"
#include "get_next_line.h"

void	client_loop(int s)
{
  char	*line;
  int	ok;

  my_putstr("\nmy_ftp> ");
  ok = 1;
  while (ok)
    {
      line = get_next_line(0);
      if (line == NULL || strcmp(line, "quit") == 0)
	ok = 0;
      else
	{
	  if (strlen(line) > 0)
	    {
	      client_cmd(line, s);
	      free(line);
	    }
	  my_putstr("my_ftp> ");
	}
    }
  puts("Client quit");
}

void	launch_client(int s)
{
  char	*res;

  res = get_next_line(s);
  if (res == NULL)
    {
      fprintf(stderr, "Serveur is not connected\n");
      close(s);
      exit(EXIT_FAILURE);
    }
  xwrite(1, res, strlen(res));
  free(res);
  client_loop(s);
}

int			main(int ac, char **av)
{
  int			s;
  struct sockaddr_in	sin;
  struct hostent	*h;
  struct in_addr	addr;
  int			port;

  if (ac != 3)
    aff_error("usage ./client [-name][-port]");
  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    aff_error("Function socket failed");
  if ((port = atoi(av[2])) == -1)
    aff_error("port invalid");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if (!(h = gethostbyname(av[1])))
    aff_error("host not found");
  bcopy(h->h_addr, &addr, sizeof(addr));
  sin.sin_addr = addr;
  if (connect(s, (struct sockaddr *) &sin, sizeof(struct sockaddr_in)) == -1)
    aff_error("Function connect failed");
  launch_client(s);
  close(s);
  return (0);
}
