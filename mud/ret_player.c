/*
** ret_obj.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:27:40 2010 adrien folie
** Last update Thu Jul 15 03:10:03 2010 adrien folie
*/

#include <stdlib.h>
#include "tlist.h"
#include "cbuff.h"
#include "player.h"
#include "remove.h"

void	free_player(t_player *player)
{
  free_objs(player->obj);
  free(player->obj);
  free_cbuff(player->cread);
  free(player->cread);
  free_cbuff(player->cwrite);
  free(player->cwrite);
  free(player);
}

void		remove_middle_player(t_tlist *players, int fd)
{
  t_telem	*save;
  t_telem	*tmp;
  int		i;

  i = 0;
  save = players->begin;
  while (players->begin != NULL)
    {
      if (((t_player *) players->begin->data)->fd == fd)
	{
	  tmp = players->begin;
	  if (i == 0)
	    remove_mid_beg(players);
	  else if (i > 0 && i < players->taille - 1)
	    remove_mid_mid(players, save);
	  else
	    remove_mid_end(players, save);
	  players->taille--;
	  free_player(tmp->data);
	  free(tmp);
	  return ;
	}
      players->begin = players->begin->next;
      ++i;
    }
}

void		ret_player(t_tlist *players, int fd)
{
  t_telem	*tmp;

  if (players->taille == 1 &&
      ((t_player *) players->begin->data)->fd == fd)
    {
      tmp = players->begin;
      init_tlist(players);
      free_player(tmp->data);
      free(tmp);
    }
  if (players->taille > 1)
    remove_middle_player(players, fd);
}

void		free_list_players(t_tlist *players)
{
  t_telem	*tmp;

  while (players->begin != NULL)
    {
      tmp = players->begin;
      players->begin = players->begin->next;
      free_player(tmp->data);
      free(tmp);
    }
}
