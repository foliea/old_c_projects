/*
** loop_select.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Jul  9 05:15:45 2010 adrien folie
** Last update Thu Jul 15 01:17:31 2010 adrien folie
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
#include <signal.h>
#include "tlist.h"
#include "serveur.h"
#include "utils.h"

static int	run = 1;

void	set_fd(t_env *e)
{
  int	i;

  i = 0;
  e->max = 0;
  FD_ZERO(&e->fd_read);
  FD_ZERO(&e->fd_write);
  while (i < e->maxfd)
    {
      if (e->fds[i].type != FD_FREE)
        {
	  FD_SET(i, &e->fd_read);
	  if (strlen(e->fds[i].buf_write) > 0)
	    FD_SET(i, &e->fd_write);
          e->max = MAX(e->max, i);
        }
      i++;
    }
}

void	verif_read(t_env *e)
{
  int	i;
  int	end;

  i = 0;
  end = e->r;
  while ((i < e->maxfd) && (end > 0))
    {
      if (FD_ISSET(i, &e->fd_read))
	{
	  e->fds[i].fct_read(e, i);
	  end--;
	}
      i++;
    }
  return ;
}

void	verif_write(t_env *e)
{
  int	i;

  i = 0;
  while (i < e->maxfd)
    {
      if (FD_ISSET(i, &e->fd_write))
	e->fds[i].fct_write(e, i);
      i++;
    }
  return ;
}

void	quit_handler(__attribute__((unused))int sig)
{
  run = 0;
  puts("Serveur Quit");
}

void	loop_select(t_env *e)
{
  run = 1;
  if (signal(SIGINT, &quit_handler) == SIG_ERR)
    aff_error("signal failed");
  while (run)
    {
      set_fd(e);
      e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, NULL);
      if (run == 1)
	{
	  if (e->r == -1)
	    aff_error("select error");
	  verif_read(e);
	  verif_write(e);
	}
    }
}
