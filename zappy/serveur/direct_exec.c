/*
** direct_exec.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Jun 16 03:24:21 2010 edern bienvenu
** Last update Sun Jun 20 18:36:04 2010 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"
#include "fd_puts.h"
#include "elevation.h"

typedef struct	s_directcmd
{
  char		*cmd;
  int		(*f)();
}		t_directcmd;

static const struct s_directcmd	ind[] =
  {
    {"incantation\n", begin_elevation},
    {"connect_nbr\n", connect_nbr},
    {NULL, NULL}
  };

extern t_teams	*teams;

int	begin_elevation(__attribute__ ((unused)) char *cmd, int fd)
{
  if (check_elevation(fd) == -1)
    {
      printf("\033[0;31mSending message to %d :\033[0;0m ko\n", fd);
      fd_puts(fd, "ko\n");
      return (-1);
    }
  else
    {
      printf("\033[0;31mSending message to %d :\033[0;0m elevation en cours\n",
	     fd);
      fd_puts(fd, "elevation en cours\n");
    }
  return (0);
}

int	connect_nbr(char *cmd, int fd)
{
  int	nb;

  nb = get_nb_clients(teams, fd);
  printf("\033[0;31mSending message to %d :\033[0;0m %s\n", fd, cmd);
  fd_putnbr(fd, nb);
  fd_puts(fd, "\n");
  return (-1);
}

int	direct_exec(char *cmd, int fd)
{
  int	i;

  i = 0;
  while (ind[i].cmd != NULL)
    {
      if (strncmp(ind[i].cmd, cmd, strlen(ind[i].cmd)) == 0)
	return (ind[i].f(cmd, fd));
      ++i;
    }
  return (0);
}
