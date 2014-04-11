/*
** iamath.c for  in /u/all/bienve_e/public/zappy/2_antoine/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Jun 20 21:23:59 2010 antoine goueslard
** Last update Sun Jun 20 21:23:59 2010 antoine goueslard
*/
/*
** iamath.c for  in /u/all/bienve_e/public/zappy/2_antoine/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Jun 20 21:17:50 2010 antoine goueslard
** Last update Sun Jun 20 21:17:50 2010 antoine goueslard
*/
/*
** iamath.c for  in /u/all/bienve_e/public/zappy/2_antoine/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Jun 20 20:41:47 2010 antoine goueslard
** Last update Sun Jun 20 21:11:54 2010 antoine goueslard
*/

#include <stdlib.h>
#include <string.h>
#include "client.h"

extern t_play player;

int	is_enough(void)
{
  if (player.niveau == 1 && player.inv.l > 0)
    return (0);
  if (player.niveau == 2 && player.inv.l > 0 &&
      player.inv.d > 0 && player.inv.s > 0)
    return (0);
  if (player.niveau == 3 && player.inv.l > 1 &&
      player.inv.s > 0 && player.inv.p > 1)
    return (0);
  return (-1);
}

char	**new_tab(t_act *commands)
{
  t_act	*begin;
  char	**to_send;

  begin = commands;
  while (begin != 0)
    {
      if (begin->fnbr == 7 || begin->fnbr == 8
	  || begin->fnbr == 9)
	return (NULL);
      begin = begin->next;
    }
  to_send = calloc(11, sizeof(char *));
  if (to_send == 0)
    exit(EXIT_FAILURE);
  return (to_send);
}

char	**docan(int can, char **to_send, char **tab_do)
{
  int	i;

  i = 0;
  while (i < 10 - can)
    {
      to_send[i] = tab_do[i];
      tab_do[i] = tab_do[10 - can + i];
      i++;
    }
  return (to_send);
}

int	calc_avance(int pos)
{
  if (pos == 0)
    return (2);
  else if (pos <= 3)
    return (pos + 4);
  else if (pos <= 8)
    return (pos + 6);
  else if (pos <= 15)
    return (pos + 8);
  else if (pos <= 24)
    return (pos + 10);
  return (0);
}

char	**new_see(int can, int *linv, t_act *commands)
{
  char	**ns;

  if (10 - can >= 2)
    {
      ns = new_tab(commands);
      if (ns == 0)
	return (NULL);
      ns[0] = strdup("voir\n");
      ns[1] = strdup("inv\n");
      *linv = 20;
      player.pos = 0;
      player.dir = -1;
      return (ns);
    }
  return (NULL);
}
