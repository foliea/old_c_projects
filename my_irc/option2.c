/*
** option2.c for my_irc in /u/all/folie_a/cu/test/gtk
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Apr 28 10:23:11 2010 adrien folie
** Last update Wed Apr 28 20:03:47 2010 adrien folie
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

int	res_who(__attribute__((unused)) int s, char *cmd)
{
  char	**arg;

  arg = str_to_wordtab(cmd, ' ');
  if (tablen(arg) == 3)
    write_on_contacts(Wdata.begin, arg[1], arg[2]);
  return (0);
}

int	who_chan(int s, char *cmd)
{
  write(s, cmd, strlen(cmd));
  return (0);
}

int	nick(int s, char *cmd)
{
  write(s, cmd, strlen(cmd));
  return (0);
}

int	aconnec(__attribute__((unused)) int s,
                __attribute__((unused)) char *cmd)
{
  write_on_screen(Wdata.begin, "Main", "Already Connected", 1);
  return (0);
}
