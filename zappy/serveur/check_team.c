/*
** check_team.c for zappy in /u/all/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Jun  7 22:14:08 2010 edern bienvenu
** Last update Sun Jun 20 17:13:00 2010 edern bienvenu
*/

#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"
#include "parsing.h"
#include "player.h"
#include "fd_puts.h"

extern t_parse parse;
extern t_teams *teams;

void	add_player_in_team(char *name, int fd)
{
  int	i;

  i = 0;
  while (i < parse.nb_team)
    {
      if (strcmp(teams[i].name, name) == 0)
	{
	  teams[i].nb_clients--;
	  printf("\033[0;31mSending message to %d : \033[0;0m%d\n\n",
		 fd, teams[i].nb_clients);
	  fd_putnbr(fd, teams[i].nb_clients);
	  fd_puts(fd, "\n");
	  my_put_in_dteam(teams[i].data, fd, 1);
	  return ;
	}
      ++i;
    }
}

int	check_team(char *name)
{
  int	i;

  i = 0;
  while (i < parse.nb_team)
    {
      if (strcmp(teams[i].name, name) == 0)
	return (teams[i].nb_clients);
      ++i;
    }
  return (-1);
}
