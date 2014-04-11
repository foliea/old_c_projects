/*
** do_eclosion.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Jun 18 03:52:49 2010 adrien folie
** Last update Sat Jun 19 02:48:21 2010 adrien folie
*/

#include "player.h"

extern t_teams	*teams;

void	do_eclosion(char *cmd, t_player *player, int fd)
{
  increase_nb_clients(teams, fd);
  /* APPEL DE PUT_EGG avec eggx, eggy */
}
