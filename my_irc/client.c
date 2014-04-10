/*
** client.c for client in /u/all/bienve_e/cu/rendu/c/my_ftp/client
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Mar 31 00:03:29 2010 edern bienvenu
** Last update Wed Apr 28 21:20:55 2010 edern bienvenu
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
#include "client.h"
#include "get_next_line.h"
#include "window.h"

extern t_Window	Wdata;
extern int	serveur_socket;

void	do_options(int s, char *line, char *channel)
{
  char	**cmd;
  int	i;

  cmd = str_to_wordtab(line, ' ');
  i = 0;
  while (ind[i].flags != 0)
    {
      if (strcmp(cmd[0], ind[i].flags) == 0)
	{
	  ind[i].f(s, line);
	  return ;
	}
      i++;
    }
  send_msg(s, line, channel);
}

char	*verif_line(char *str)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = malloc(4096);
  while (str[i])
    {
      if (str[i] > 31 && str[i] < 127)
        {
          res[j] = str[i];
          j++;
        }
      i++;
    }
  res[j] = '\0';
  return (res);
}

void		check_option(char *line, char *channel)
{
  static int	is_connected = -1;
  int		s;

  if (strncmp("/rwho", line, 4) != 0)
    line = verif_line(line);
  if (is_connected == -1)
    {
      is_connected = connection(is_connected, line);
      if (is_connected == -1)
	write_on_screen(Wdata.begin, "Main",
			"Connection Failed : /connect _server _port", 1);
      else
	write_on_screen(Wdata.begin, "Main", "Connection Success", 1);
    }
  else
    {
      s = is_connected;
      serveur_socket = s;
      do_options(s, line, channel);
    }
  return ;
}
