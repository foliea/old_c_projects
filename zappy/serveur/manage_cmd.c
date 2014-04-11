/*
** manage_cmd.c for zappy in /u/all/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Jun 14 04:16:26 2010 edern bienvenu
** Last update Sun Jun 20 09:36:52 2010 adrien folie
*/

#include <string.h>
#include <stdio.h>
#include "cbuff.h"
#include "check.h"
#include "fd_puts.h"

void		put_in_teams(t_cbuff *cbuff, char *tmp, int fd)
{
  int		nb;

  tmp[strlen(tmp) - 1] = '\0';
  if ((nb = check_team(tmp)) > 0)
    {
      cbuff->type = PLAYER;
      add_player_in_team(tmp, fd);
    }
  else
    {
      cbuff->type = DEAD;
      printf("\033[0;31mSending message to %d :\033[0;0m ko\n", fd);
      fd_puts(fd, "ko\n");
    }
}

void	choose_type(t_cbuff *cbuff, char *tmp, int fd)
{
  if (strcmp("GRAPHICS\n", tmp) == 0)
    cbuff->type = GRAPHICS;
  else
    put_in_teams(cbuff, tmp, fd);
}

void	manage_cmd(t_cbuff *cbuff, int t, char *tmp, int fd)
{
  if (cbuff->type == PLAYER)
    cmd_queue(cbuff, t, tmp, fd);
  if (cbuff->type == GRAPHICS)
    puts("Graphics Cmd : Work in progress");
  if (cbuff->type == WAITING_STATE)
    choose_type(cbuff, tmp, fd);
}
