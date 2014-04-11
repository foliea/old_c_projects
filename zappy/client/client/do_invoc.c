/*
** do_invoc.c for  in /u/all/bienve_e/public/zappy/2_antoine/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Jun 20 20:38:35 2010 antoine goueslard
** Last update Sun Jun 20 21:32:50 2010 antoine goueslard
*/

#include <stdlib.h>
#include <string.h>
#include "client.h"

extern t_play player;

char	**sendl1(int can, char **to_send, int *linv)
{
  if (10 - can >= 2)
    {
      if (player.map[player.pos].d == 0 && player.map[player.pos].s == 0 &&
	  player.map[player.pos].m == 0 && player.map[player.pos].p == 0 &&
	  player.map[player.pos].t == 0)
	{
	  if (player.map[player.pos].l == 1)
	    to_send[0] = strdup("inc\n");
	  else
	    {
	      to_send[0] = strdup("pose linemate\n");
	      to_send[1] = strdup("inc\n");
	    }
	}
      else
	{
	  to_send[0] = strdup("avance\n");
	  *linv -= 1;
	  player.pos = calc_avance(player.pos);
	}
    }
 return (to_send);
}

char	**sendl2(int can, char **to_send, int *linv)
{
  if (9 - can >= 4)
    {
      if (player.map[player.pos].joueurs == 2 && 
	  player.map[player.pos].d == 0 && player.map[player.pos].s == 0 &&
	  player.map[player.pos].m == 0 && player.map[player.pos].p == 0 &&
	  player.map[player.pos].t == 0 && player.map[player.pos].l == 0)
	{
	  to_send[0] = strdup("pose deraumere\n");
	  to_send[1] = strdup("pose linemate\n");
	  to_send[2] = strdup("pose sibur\n");
	  to_send[3] = strdup("inc\n");
	  *linv -= 4;
	}
      else if (player.map[player.pos].joueurs == 2 && 
	       player.map[player.pos].d == 1 && player.map[player.pos].s == 1 &&
	       player.map[player.pos].m == 0 && player.map[player.pos].p == 0 &&
	       player.map[player.pos].t == 0 && player.map[player.pos].l == 1)
	{
	  to_send[0] = strdup("inc\n");
	  *linv -= 1;
	}
      else
	{	
	  to_send[0] = strdup("bro\n");
	  *linv = 0;
	}
    }
  return (to_send);
}

char	**sendl3(int can, char **to_send, int *linv)
{
  if (9 - can >= 6)
    {
      if (player.map[player.pos].joueurs == 2 && 
	  player.map[player.pos].d == 0 && player.map[player.pos].s == 0 &&
	  player.map[player.pos].m == 0 && player.map[player.pos].p == 0 &&
	  player.map[player.pos].t == 0 && player.map[player.pos].l == 0)
	{
	  to_send[0] = strdup("pose linemate\n");
	  to_send[1] = strdup("pose linemate\n");
	  to_send[2] = strdup("pose sibur\n");
       	  to_send[3] = strdup("pose phiras\n");;
	  to_send[4] = strdup("pose phiras\n");
	  to_send[5] = strdup("inc\n");
	  *linv -= 6;
	}
      else if (player.map[player.pos].joueurs == 2 &&
	       player.map[player.pos].l == 2 && player.map[player.pos].d == 0 &&
	       player.map[player.pos].m == 0 && player.map[player.pos].p == 2 &&
	       player.map[player.pos].t == 0 && player.map[player.pos].s == 1)
	{
	  to_send[0] = strdup("inc\n");
	  *linv -= 1;
	}
      else
	{	
	  to_send[0] = strdup("bro\n");
	  *linv = 0;
	}
    }
  return (to_send);
}


char	**send_elev(int can, char **to_send, int *linv, t_act *commands)
{
  commands = commands;
  if (player.niveau == 1)
    return (sendl1(can, to_send, linv));
  if (player.niveau == 2)
    return (sendl2(can, to_send, linv));
  if (player.niveau == 3)
   return (sendl3(can, to_send, linv));
  return (NULL);
}

