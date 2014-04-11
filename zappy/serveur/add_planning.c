/*
** add_planning.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 28 22:28:37 2010 adrien folie
** Last update Sun Jun 20 18:46:21 2010 edern bienvenu
*/

#include <sys/time.h>
#include <string.h>
#include <stdio.h>
#include "serveur.h"
#include "planning.h"
#include "cbuff.h"
#include "fd_puts.h"

extern t_tlist	*planning;

typedef struct	s_cmd_time
{
  char		*cmd;
  int		delay;
}		t_cmd_time;

static const t_cmd_time	actions[] =
  {
    {"avance\n", 7},
    {"droite\n", 7},
    {"gauche\n", 7},
    {"voir\n", 7},
    {"inventaire\n", 1},
    {"prend ", 7},
    {"pose ", 7},
    {"expulse\n", 7},
    {"broadcast ", 7},
    {"incantation\n", 300},
    {"fork\n", 42},
    {"connect_nbr\n", 0},
    {"\neclosion\n", 600},
    {NULL, 0}
  };

int	find_time(char *cmd)
{
  int	i;

  i = 0;
  while (actions[i].cmd != NULL)
    {
      if (strncmp(cmd, actions[i].cmd, strlen(actions[i].cmd)) == 0)
	return (actions[i].delay);
      ++i;
    }
  return (-1);
}

int			add_planning(int t, char *cmd, int fd)
{
  struct timeval	now;
  struct timeval	*end;
  float			add;
  int			diff;

  if ((diff = find_time(cmd)) == -1)
    {
      move_queue(choose_buffer(fd), t, cmd, fd);
      printf("\033[0;31mSending message to %d :\033[0;0m ko\n", fd);
      fd_puts(fd, "ko\n");
      return (-1);
    }
  if (direct_exec(cmd, fd) == -1)
    {
      move_queue(choose_buffer(fd), t, cmd, fd);
      return (-1);
    }
  if (gettimeofday(&now, NULL) == -1)
    aff_error("gettimeofday failed");
  end = xmalloc(sizeof(struct timeval));
  add = ((float) diff / (float) t) * 1000000.;
  end->tv_sec = now.tv_sec + (long) add / 1000000;
  end->tv_usec = now.tv_usec + (long) add % 1000000;
  insert_tlist(planning, cmd, fd, end);
  return (0);
}
