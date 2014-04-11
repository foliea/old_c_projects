/*
** get_player.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Jun 17 02:38:21 2010 adrien folie
** Last update Sun Jun 20 18:34:19 2010 adrien folie
*/

#include <stdlib.h>
#include <sys/select.h>
#include "serveur.h"
#include "player.h"
#include "parsing.h"

extern t_parse parse;

t_player	*find_player(t_dteam *team, int fd)
{
  t_player	*tmp;
  t_player	*player;

  tmp = team->begin;
  while (team->begin != NULL)
    {
      if (team->begin->fd == fd)
	{
	  player = team->begin;
	  team->begin = tmp;
	  return (player);
	}
      team->begin = team->begin->next;
    }
  team->begin = tmp;
  return (NULL);
}

t_player	*get_player(t_teams *teams, int fd)
{
  int		i;
  t_player	*player;

  i = 0;
  while (i < parse.nb_team)
    {
      if ((player = find_player(teams[i].data, fd)) != NULL)
        return (player);
      ++i;
    }
  return (NULL);
}

int		get_nb_clients(t_teams *teams, int fd)
{
  int		i;
  t_player	*player;

  i = 0;
  while (i < parse.nb_team)
    {
      if ((player = find_player(teams[i].data, fd)) != NULL)
        return (teams[i].nb_clients);
      ++i;
    }
  return (0);
}

void		increase_nb_clients(t_teams *teams, int fd)
{
  int		i;
  t_player	*player;

  i = 0;
  while (i < parse.nb_team)
    {
      if ((player = find_player(teams[i].data, fd)) != NULL)
	{
	  teams[i].nb_clients++;
	  return ;
	}
      ++i;
    }
}
