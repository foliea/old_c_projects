/*
** quit_client.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jun 14 05:34:45 2010 adrien folie
** Last update Sun Jun 20 17:38:04 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include "planning.h"
#include "cbuff.h"
#include "player.h"
#include "ret_team.h"

extern t_tlist	*planning;

void		quit_client(int fd)
{
  t_cbuff	*cbuff;

  cbuff = choose_buffer(fd);
  if (cbuff == NULL)
    return ;
  ret_cbuffer(fd);
  ret_planning(planning, fd);
  search_in_teams(fd);
}
