/*
** loop.c for loop in /u/all/bienve_e/rendu/c/my_irc/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 26 14:08:33 2010 edern bienvenu
** Last update Sun Jun 20 19:26:23 2010 adrien folie
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
#include "serveur.h"
#include "planning.h"
#include "cbuff.h"
#include "manage.h"
#include "parsing.h"
#include "free_obj.h"

t_tlist		*planning;
t_dcircular	*buff_list;
static t_fd	*fdclose;
extern t_parse	parse;

void	handler(__attribute__((unused)) int sig)
{
  close(parse.s);
  fdclose = NULL;
  free_list_buffer();
  free_list_teams();
  free_list_planning();
  exit(EXIT_SUCCESS);
}

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

void	verif_fd(t_env *e)
{
  int	i;

  i = 0;
  while ((i < e->maxfd) && (e->r > 0))
    {
      if (FD_ISSET(i, &e->fd_read))
        e->fds[i].fct_read(e, i);
      if (FD_ISSET(i, &e->fd_write))
	e->fds[i].fct_write(e, i);
      if (FD_ISSET(i, &e->fd_read) ||
          FD_ISSET(i, &e->fd_write))
        e->r--;
      i++;
    }
  return ;
}

void	catch_sig(__attribute__((unused)) int sig)
{
  puts("** Warning : broken pipe **");
  return ;
}

void			loop_select(t_env *e)
{
  struct timeval	*timeout;

  planning = xmalloc(sizeof(struct s_tlist));
  buff_list = xmalloc(sizeof(struct s_dcircular));
  my_init_dcircular(buff_list);
  init_tlist(planning);
  fdclose = e->fds;
  if (signal(SIGINT, &handler) == SIG_ERR
      || signal(SIGPIPE, &catch_sig) == SIG_ERR)
    aff_error("Signal failed");
  while (42)
    {
      timeout = manage_planning(planning);
      set_fd(e);
      e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, timeout);
      if (e->r > 0)
	verif_fd(e);
      else
	exec_planning(planning, e->t);
      if (timeout != NULL)
	free(timeout);
    }
}
