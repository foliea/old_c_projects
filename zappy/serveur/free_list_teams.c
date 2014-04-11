/*
** free_list_teams.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Jun 17 03:02:04 2010 adrien folie
** Last update Sun Jun 20 19:22:56 2010 adrien folie
*/

#include <stdlib.h>
#include "player.h"
#include "parsing.h"

extern t_teams	*teams;
extern t_parse	parse;

void		free_team(t_dteam *team)
{
  t_player	*tmp;

  while (team->begin != NULL)
    {
      tmp = team->begin;
      team->begin = team->begin->next;
      free(tmp);
    }
}

void	free_list_teams(void)
{
  int	i;

  i = 0;
  while (i < parse.nb_team)
    {
      free_team(teams[i].data);
      ++i;
    }
  free(teams);
}
