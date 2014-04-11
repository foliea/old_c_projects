/*
** ia.c for ia in /u/all/bienve_e/public/zappy/2_antoine
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sat Jun 19 06:15:59 2010 antoine goueslard
** Last update Sun Jun 20 21:29:03 2010 antoine goueslard
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

extern t_play player;

char	**greed(char **to_send, int can, int *linv)
{
  int	i;
  int	l;
  
  i = 0;
  if (player.inv.life >= 20
      && is_enough() == -1)
    return (catch_pierre(to_send, can, linv));
  if (10 - can >= 2)
    if ((l = player.map[player.pos].life) > 0)
      while ((i + 1) < 9 - can && i < l)
	{
	  to_send[i] = strdup("prend nourriture\n");
	  *linv -= 1;
	  i++;
	}
  to_send[i] = strdup("avance\n");
  *linv -= 1;
  player.pos = calc_avance(player.pos);
  if (player.inv.life <= 5)
    {
      to_send[i] = strdup("avance\n");
      to_send[i + 1] = strdup("droite\n");
      to_send[i + 2] = strdup("avance\n");
      *linv -= 20;
    }
  return (to_send);
}

char	**find_buddy(int can, char **to_send, int *linv, t_act *commands)
{
  int	i;

  i = 0;
  commands = commands;
  if (player.mess.from == 0)
    {
      to_send[0] = "voir\n";
      to_send[1] = "inc\n";
      player.mess.from = -1;
      return (to_send);
    }
  while ((i + 1) < 9 - can && abs(player.mess.from - player.mess.dir > 1))
    {
      to_send[i] = strdup("gauche\n");
      player.mess.dir = (player.mess.dir + 2) % 8;
      *linv -= 1;
      i++;
    }
  to_send[i] = strdup("avance\n");
  *linv = 0;
  player.mess.from = -1;
  player.pos = calc_avance(player.pos);
  return (to_send);
}

char	**find_bdir(int can, char **to_send, int *linv, t_act *commands)
{
  if (player.mess.from >= 0 && player.inv.life >= 10)
    {
      return (find_buddy(can, to_send, linv, commands));
    }
  else if (is_enough() == 0 && player.inv.life >= 30)
    {
      return (send_elev(can, to_send, linv, commands));
    }
  return (greed(to_send, can, linv));
}

char	**new_dir(int can, t_act *commands, int *linv)
{
  char	**to_send;

  if ((to_send = new_tab(commands)) == 0)
    return (NULL);
  to_send = find_bdir(can, to_send, linv, commands);
  return (to_send);
}

char	**to_do(int can, t_act *commands)
{
  static int	linv = -1;
  
  if (linv <= 0 || player.pos > (player.niveau + 1) * (player.niveau + 1) - 1)
    return (new_see(can, &linv, commands));
  else if (player.dir == -1)
    return (new_dir(can, commands, &linv));
  linv = -1;
  return (NULL);
}
