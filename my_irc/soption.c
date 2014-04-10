/*
** option.c for ;y irc in /u/all/bienve_e/rendu/c/my_irc/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 26 15:51:46 2010 edern bienvenu
** Last update Wed Apr 28 21:34:55 2010 edern bienvenu
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
#include "irc.h"

extern	struct s_serv	sdata;

void	r_who(char **arg, t_dlist *list);
void	modif_nick(int fd, t_dlist *list, char *login);
void	modif_nick_chan(int fd, char *login);

int	send_msg(int fd, char *cmd)
{
  char	*res;
  char	**arg;
  int	i;
  int	j;

  arg = str_to_wordtab(cmd, ' ');
  j = 1;
  i = tablen(arg);
  if (i >= 2)
    {
      res = my_strcat("/msg ", arg[0]);
      res = my_strcat(res, " ");
      res = my_strcat(res, strdup(whois(fd)));
      res = my_strcat(res, " > ");
      while (j < i)
	{
	  res = my_strcat(res, arg[j]);
	  res = my_strcat(res, " ");
	  j++;
	}
      send_msg_all(res, arg[0]);
    }
  return (0);
}

int	join_chan(int fd, char *cmd)
{
  char	**arg;

  arg = str_to_wordtab(cmd, ' ');
  if (tablen(arg) == 2)
    {
      if (verif_chan(arg[1], fd) == 0)
	my_put_in_dchan(&(sdata.chan), strdup(arg[1]), fd, 1);
    }
  return (0);
}

int		who_chan(__attribute__((unused))int fd, char *cmd)
{
  char		**arg;
  t_channel	*temp;
  t_dchan	*list;

  list = &(sdata.chan);
  temp = list->begin;
  arg = str_to_wordtab(cmd, ' ');
  while (list->begin)
    {
      if (strcmp(arg[1], list->begin->name) == 0)
	{
	  r_who(arg, &(list->begin->users));
	  list->begin = temp;
	  return (0);
	}
      list->begin = list->begin->next;
    }
  list->begin = temp;
  return (0);
}

int	nick(int fd, char *cmd)
{
  char	**arg;

  arg = str_to_wordtab(cmd, ' ');
  if (tablen(arg) != 2)
    return (-1);
  modif_nick(fd, &(sdata.user), arg[1]);
  modif_nick_chan(fd, arg[1]);
  return (0);
}
