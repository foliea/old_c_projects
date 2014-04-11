/*
** ret_cbuff.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Jun 15 03:39:59 2010 adrien folie
** Last update Sun Jun 20 17:37:20 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>
#include "serveur.h"
#include "parsing.h"
#include "player.h"
#include "ret_team.h"

extern t_teams	*teams;
extern t_parse	parse;

int		remove_middle_teams(t_dteam *team, int fd)
{
  t_player	*save;
  t_player	*tmp;
  int		i;

  i = 0;
  save = team->begin;
  while (team->begin != NULL)
    {
      if (team->begin->fd == fd)
	{
	  tmp = team->begin;
	  if (i == 0)
	    remove_mid_beg(team);
	  else if (i > 0 && i < team->taille - 1)
	    remove_mid_mid(team, save);
	  else
	    remove_mid_end(team, save);
	  team->taille--;
	  free(tmp);
	  return (0);
	}
      team->begin = team->begin->next;
      ++i;
    }
  return (1);
}

int		ret_teams(t_dteam *team, int fd)
{
  t_player	*tmp;
  int		back;

  back = 0;
  if (team->taille == 1 && team->begin->fd == fd)
    {
      tmp = team->begin;
      my_init_dteam(team);
      free(tmp);
    }
  if (team->taille > 1)
    back = remove_middle_teams(team, fd);
  return (back);
}

void		search_in_teams(int fd)
{
  int		i;

  i = 0;
  while (i < parse.nb_client)
    {
      if (ret_teams(teams[i].data, fd) == 0)
	return ;
      ++i;
    }
}
