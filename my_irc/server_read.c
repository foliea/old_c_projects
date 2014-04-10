/*
** server_read.c for my_irc in /u/all/folie_a/cu/test/gtk
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Apr 28 09:59:07 2010 adrien folie
** Last update Wed Apr 28 09:59:09 2010 adrien folie
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
#include <gtk/gtk.h>
#include "window.h"

extern int	serveur_socket;

void	server_read(void)
{
  char	buff[4096];
  int	nb_read;

  memset(buff, '\0', 4096);
  nb_read = recv(serveur_socket, buff, 4096, MSG_DONTWAIT);
  if (nb_read > 0)
    check_option(buff, NULL);
  write(1, "\0", 1);
}
