/*
** ret_team_an.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun Jun 20 16:29:32 2010 edern bienvenu
** Last update Sun Jun 20 17:30:08 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include "player.h"

void	remove_mid_end(t_dteam *recup, t_player *save)
{
  recup->begin->prev->next = NULL;
  recup->end = recup->begin->prev;
  recup->begin = save;
}

void	remove_mid_mid(t_dteam *recup, t_player *save)
{
  recup->begin->prev->next = recup->begin->next;
  recup->begin->next->prev = recup->begin->prev;
  recup->begin = save;
}

void	remove_mid_beg(t_dteam *team)
{
  team->begin = team->begin->next;
  team->begin->prev = NULL;
}

