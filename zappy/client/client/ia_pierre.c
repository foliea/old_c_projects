/*
** ia_pierre.c for  in /u/all/bienve_e/public/zappy/2_antoine/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Jun 20 20:55:30 2010 antoine goueslard
** Last update Sun Jun 20 21:26:09 2010 antoine goueslard
*/

#include <stdlib.h>
#include <string.h>
#include "client.h"

extern t_play player;

char	**caline(char **to_send, int can, int *linv)
{
  int	i;

  i = 0;
  if (player.inv.l < 2)
    {   
      if (10 - can >= 2)
	if (player.map[player.pos].l > 0)
	  while ((i + 1) < 9 - can)
	    {
	      to_send[i] = strdup("prend linemate\n");
	      *linv -= 1;
	      i++;
	    }
      to_send[i] = strdup("avance\n");
      *linv -= 1;
      player.pos = calc_avance(player.pos);
    }
  return (to_send);
}

char	**cadera(char **to_send, int can, int *linv)
{
  int	i;

  i = 0;
  if (player.inv.d < 2)
    {   
      if (10 - can >= 2)
	if (player.map[player.pos].d > 0)
	  while ((i + 1) < 9 - can)
	    {
	      to_send[i] = strdup("prend deraumere\n");
	      *linv -= 1;
	      i++;
	    }
      to_send[i] = strdup("avance\n");
      *linv -= 1;
      player.pos = calc_avance(player.pos);
    }
  return (to_send);
}

char	**casibu(char **to_send, int can, int *linv)
{
  int	i;

  i = 0;
  if (player.inv.s < 3)
    {   
      if (10 - can >= 2)
	if (player.map[player.pos].s > 0)
	  while ((i + 1) < 9 - can)
	    {
	      to_send[i] = strdup("prend sibur\n");
	      *linv -= 1;
	      i++;
	    }
      to_send[i] = strdup("avance\n");
      *linv -= 1;
      player.pos = calc_avance(player.pos);
    }
  return (to_send);
}


char	**caphir(char **to_send, int can, int *linv)
{
  int	i;

  i = 0;
  if (player.inv.p < 2)
    {   
      if (10 - can >= 2)
	if (player.map[player.pos].p > 0)
	  while ((i + 1) < 9 - can)
	    {
	      to_send[i] = strdup("prend phiras\n");
	      *linv -= 1;
	      i++;
	    }
      to_send[i] = strdup("avance\n");
      *linv -= 1;
      player.pos = calc_avance(player.pos);
    }
  return (to_send);
}


char	**catch_pierre(char **to_send, int can, int *linv)
{
  if (player.inv.l < 2)
    return (caline(to_send, can, linv));
  if (player.niveau >= 2 && player.inv.d < 2)
    return (cadera(to_send, can, linv));
  if (player.niveau >= 2 && player.inv.s < 3)
    return (casibu(to_send, can, linv));
  if (player.niveau >= 3 && player.inv.p < 3)
    return (caphir(to_send, can, linv));
  return (NULL);
}

