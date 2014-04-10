/*
** parser.c for my irc in /u/all/bienve_e/rendu/c/my_irc/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 26 14:09:18 2010 edern bienvenu
** Last update Wed Apr 28 17:59:06 2010 edern bienvenu
*/

#include <math.h>
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

void	aff_err(char *str);

void	parser(t_env *e, int ac, char **av)
{
  if (ac != 2)
    aff_err("usage : ./my_irc port");
  e->port = atoi(av[1]);
  return ;
}
