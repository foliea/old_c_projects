/*
** option.c for my irc in /u/all/bienve_e/rendu/c/my_irc/client
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 26 15:28:32 2010 edern bienvenu
** Last update Wed Apr 28 10:25:42 2010 adrien folie
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
#include "window.h"

extern t_Window	Wdata;

int	join_chan(int s, char *cmd)
{
  char	**arg;

  arg = str_to_wordtab(cmd, ' ');
  if (tablen(arg) == 2)
    {
      if (channel_exist(Wdata.begin, arg[1]) == 0)
	{
	  Wdata.begin = place_objects(Wdata.pNotebook, Wdata.begin, arg[1]);
	  gtk_widget_show_all(Wdata.pWindow);
	  write(s, cmd, strlen(cmd));
	}
    }
  else
    write_on_screen(Wdata.begin, "Main", "usage : /join _channel", 1);
  return (0);
}

int			connection(int s, char *cmd)
{
  char			**arg;
  int			port;
  struct hostent	*h;
  struct in_addr	addr;
  struct sockaddr_in	sin;

  arg = client_connect(cmd);
  if (arg == NULL)
    return (-1);
  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return (aff_error("Function socket failed"));
  if ((port = atoi(arg[2])) == -1)
    return (aff_error("port invalid"));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if (!(h = gethostbyname(arg[1])))
    return (aff_error("host not found"));
  bcopy(h->h_addr, &addr, sizeof(addr));
  sin.sin_addr = addr;
  if (connect(s, (struct sockaddr *) &sin, sizeof(sin)) == -1)
    return (aff_error("Function connect failed"));
  return (s);
}

int	receive_msg(__attribute__((unused)) int s, char *cmd)
{
  char	**arg;
  int	i;
  int	j;

  arg = str_to_wordtab(cmd, ' ');
  if ((j = tablen(arg)) > 2)
    {
      i = 2;
      while (i < j)
	{
	  if ((i + 1) != j)
	    {
	      write_on_screen(Wdata.begin, arg[1], arg[i], 0);
	      write_on_screen(Wdata.begin, arg[1], " ", 0);
	    }
	  else
	    write_on_screen(Wdata.begin, arg[1], arg[i], 1);
	  ++i;
	}
    }
  return (0);
}

void	send_msg(int s, char *line, char *channel)
{
  char	*msg;

  msg = my_strcat(channel, " ");
  msg = my_strcat(msg, line);
  write(s, msg, strlen(msg));
  return ;
}
