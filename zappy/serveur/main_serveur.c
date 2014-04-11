/*
** main_serveur.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 28 21:30:41 2010 adrien folie
** Last update Sat Jun 19 05:00:25 2010 edern bienvenu
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
#include "serveur.h"
#include "parsing.h"
#include "map.h"

t_parse	parse;
t_map	**map;

void	create_srv(t_env *e, struct timeval *tv);

int			main(__attribute__((unused))int ac,
			     char **av)
{
  t_env			e;
  struct timeval	tv;

  init_option(&e);
  parse_opt(av, &e);
  alloc_map(parse.width, parse.height);
  init_map(parse.width, parse.height);
  init_env(&e);
  create_srv(&e, &tv);
  aff_parsing(&e);
  loop_select(&e);
  return (0);
}
