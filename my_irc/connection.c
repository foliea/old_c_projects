/*
** connection.c for my irc in /u/all/bienve_e/rendu/c/my_irc/client
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 26 16:06:59 2010 edern bienvenu
** Last update Wed Apr 28 10:07:59 2010 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
#include <strings.h>
#include <gtk/gtk.h>
#include "window.h"
#include "client.h"
#include "get_next_line.h"

void	aff_onconnect(struct sockaddr_in sin, int port)
{
  my_putstr("Connected to ");
  my_putstr(inet_ntoa(sin.sin_addr));
  my_putstr(" ");
  my_putnbr(port);
  my_putstr("\n");
  return ;
}

char	**client_connect(char *cmd)
{
  char	**arg;

  arg = str_to_wordtab(cmd, ' ');
  if (strcmp(arg[0], "/quit") == 0)
    aff_error("Exit client");
  else if (tablen(arg) != 3)
    return (NULL);
  else if (strcmp(arg[0], "/connect") == 0)
    return (arg);
  return (NULL);
}
