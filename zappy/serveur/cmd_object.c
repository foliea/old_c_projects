/*
** cmd_object.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun Jun 20 18:16:38 2010 edern bienvenu
** Last update Sun Jun 20 18:18:01 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <sys/select.h>
#include "serveur.h"
#include "fd_puts.h"
#include "cbuff.h"
#include "player.h"
#include "parsing.h"
#include "map.h"
#include "broad.h"
#include "food.h"

extern t_map	**map;

char	*get_name(char *cmd)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  res = xmalloc(strlen(cmd) * sizeof(*res));
  while (cmd[i] != ' ')
    i++;
  i++;
  while (cmd[i])
    {
      res[j] = cmd[i];
      i++;
      j++;
    }
  res[j] = '\0';
  if (res)
    return (res);
  else
    return (NULL);
}

void	get_object(t_player *player, int type, int fd)
{
  int	i;
  int	x;
  int	y;

  x = player->posx;
  y = player->posy;
  i = 0;
  while (i <= 6)
    {
      if (i == type && map[player->posx][player->posy].spot[i] > 0)
	{
	  player->inv[i]++;
	  map[player->posx][player->posy].spot[i]--;
	  printf("\033[0;31mSending message to %d :\033[0;0m ok\n", fd);
	  fd_puts(fd, "ok\n");
	  return ;
	}
      else if (i == type)
	{
	  printf("\033[0;31mSending message to %d :\033[0;0m ko\n", fd);
	  fd_puts(fd, "ko\n");
	  return ;
	}
      i++;
    }
}

void	do_get(char *cmd, t_player *player, int fd)
{
  char	*obj;

  if ((obj = get_name(cmd)) == NULL)
    send_ko(fd);
  if (strcmp(obj, "nourriture\n") == 0)
    add_food(fd, player->posx, player->posy);
  else if (strcmp(obj, "linemate\n") == 0)
    get_object(player, 1, fd);
  else if (strcmp(obj, "deraumere\n") == 0)
    get_object(player, 2, fd);
  else if (strcmp(obj, "sibur\n") == 0)
    get_object(player, 3, fd);
  else if (strcmp(obj, "mendiane\n") == 0)
    get_object(player, 4, fd);
  else if (strcmp(obj, "phiras\n") == 0)
    get_object(player, 5, fd);
  else if (strcmp(obj, "thystame\n") == 0)
    get_object(player, 6, fd);
  else
    send_ko(fd);
}

void	set_object(t_player *player, int type, int fd)
{
  int	i;

  i = 0;
  while (i <= 6)
    {
      if (i == type)
	{
	  if (player->inv[i] > 0)
	    {
	      player->inv[i]--;
	      map[player->posx][player->posy].spot[i]++;
	      printf("\033[0;31mSending message to %d :\033[0;0m ok\n", fd);
	      fd_puts(fd, "ok\n");
	    }
	  else
	    send_ko(fd);
	  return ;
	}
      i++;
    }
}

void	do_set(char *cmd, t_player *player, int fd)
{
  char	*obj;

  if ((obj = get_name(cmd)) == NULL)
    send_ko(fd);
  if (strcmp(obj, "nourriture\n") == 0)
    ret_food(fd, player->posx, player->posy);
  else if (strcmp(obj, "linemate\n") == 0)
    set_object(player, 1, fd);
  else if (strcmp(obj, "deraumere\n") == 0)
    set_object(player, 2, fd);
  else if (strcmp(obj, "sibur\n") == 0)
    set_object(player, 3, fd);
  else if (strcmp(obj, "mendiane\n") == 0)
    set_object(player, 4, fd);
  else if (strcmp(obj, "phiras\n") == 0)
    set_object(player, 5, fd);
  else if (strcmp(obj, "thystame\n") == 0)
    set_object(player, 6, fd);
  else
    send_ko(fd);
}
