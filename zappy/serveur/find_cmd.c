/*
** do_move.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri May 28 22:39:17 2010 edern bienvenu
** Last update Sun Jun 20 19:36:23 2010 edern bienvenu
*/

#include <string.h>
#include "player.h"
#include "fd_puts.h"

extern t_teams	*teams;

void		find_cmd(char *act, int fd)
{
  int		j;
  t_player	*player;

  j = 0;
  while (action[j].cmd != 0)
    {
      if ((strncmp(act, action[j].cmd, strlen(action[j].cmd))) == 0)
        {
	  player = get_player(teams, fd);
	  print_time();
          action[j].f(act, player, fd);
          return ;
        }
      j++;
    }
}
