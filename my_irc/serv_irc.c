/*
** my_irc.c for irc in /u/epitech_2013/bienve_e/cu/rendu/c/my_irc
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 19 16:17:22 2010 edern bienvenu
** Last update Wed Apr 28 17:59:21 2010 edern bienvenu
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
#include "irc.h"

void	create_srv(t_env *e, struct timeval *tv);
void	parser(t_env *e, int ac, char **av);
struct s_serv		sdata;

int			main(int ac, char **av)
{
  t_env			e;
  struct timeval	tv;

  my_init_dlist(&(sdata.user));
  my_init_dchan(&(sdata.chan));
  init_env(&e);
  parser(&e, ac, av);
  create_srv(&e, &tv);
  loop(&e);
  return (0);
}
