/*
** main_mud.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:08:15 2010 adrien folie
** Last update Thu Jul 15 01:46:23 2010 adrien folie
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "utils.h"
#include "tlist.h"
#include "serveur.h"
#include "mud.h"

int		main(int ac, char **av)
{
  t_env		*e;

  if (ac != 3)
    aff_error("usage : ./serveur -port -map");
  e = xmalloc(sizeof(struct s_env));
  e->map = xmalloc(sizeof(struct s_tlist));
  e->players = xmalloc(sizeof(struct s_tlist));
  init_tlist(e->map);
  init_tlist(e->players);
  parse_map(e->map, av[2]);
  verif_map(e->map);
  init_env(e);
  create_server(e, atoi(av[1]));
  loop_select(e);
  free_list_players(e->players);
  free(e->players);
  free_list_rooms(e->map);
  free(e->map);
  free(e->fds);
  close(e->s);
  free(e);
  return (0);
}
