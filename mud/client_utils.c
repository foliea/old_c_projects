/*
** client_utils.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:06:43 2010 adrien folie
** Last update Thu Jul 15 01:43:48 2010 adrien folie
*/

#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "tlist.h"
#include "cbuff.h"
#include "room.h"
#include "player.h"
#include "serveur.h"
#include "remove.h"
#include "stack.h"

t_cbuff		*choose_buffer(t_tlist *players, int fd, int mode)
{
  t_telem	*tmp;
  t_player	*player;

  tmp = players->begin;
  while (players->begin != NULL)
    {
      player = players->begin->data;
      if (player->fd == fd)
	{
	  players->begin = tmp;
	  if (mode == CREAD)
	    return (player->cread);
	  else
	    return (player->cwrite);
	}
      players->begin = players->begin->next;
    }
  players->begin = tmp;
  return (NULL);
}

void		client_write(t_env *e, int fd)
{
  t_cbuff	*cbuff;
  char		*msg;

  if ((cbuff = choose_buffer(e->players, fd, CWRITE)) == NULL)
    return ;
  while ((msg = manage_cbuff(cbuff, fd, CWRITE)) != NULL)
    if (write(fd, msg, strlen(msg)) == -1)
      {
	e->fds[fd].type = FD_FREE;
	close(fd);
	ret_player(e->players, fd);
	printf("\033[0;33m** Deconnexion from %d **\033[0;0m\n", fd);
	return ;
      }
}

void		client_read(t_env *e, int fd)
{
  char		*cmd;
  int		nb_read;
  t_cbuff	*cbuff;

  memset(e->fds[fd].buf_read, 0, BUF_SIZE);
  if ((nb_read = read(fd, e->fds[fd].buf_read, BUF_SIZE)) <= 0)
    {
      e->fds[fd].type = FD_FREE;
      close(fd);
      ret_player(e->players, fd);
      printf("\033[0;33m** Deconnexion from %d **\033[0;0m\n", fd);
      return ;
    }
  cbuff = choose_buffer(e->players, fd, CREAD);
  if (cbuff != NULL)
    stack_to_cbuff(e, cbuff, nb_read, fd);
  while ((cmd = manage_cbuff(cbuff, fd, CREAD)) != NULL)
    do_cmd(cmd, e, fd);
}

void		init_client(t_env *e, int cs)
{
  t_player	*data;

  data = xmalloc(sizeof(struct s_player));
  data->fd = cs;
  data->pos = 1;
  data->life = LIFE_START;
  data->cread = xmalloc(sizeof(struct s_cbuff));
  init_cbuff(data->cread);
  data->cwrite = xmalloc(sizeof(struct s_cbuff));
  init_cbuff(data->cwrite);
  data->obj = xmalloc(sizeof(struct s_tlist));
  init_tlist(data->obj);
  put_in_tlist(e->players, data, 1);
}

void			add_client(t_env *e, int s)
{
  int			cs;
  struct sockaddr_in	client_sin;
  unsigned int		client_sin_len;

  client_sin_len = sizeof(client_sin);
  if ((cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len)) == -1)
    return ;
  printf("\033[0;33m** New Connexion from %s : fd : %d **\033[0;0m\n",
	 inet_ntoa(client_sin.sin_addr), cs);
  if (cs >= e->maxfd)
    {
      close(cs);
      printf("\033[0;33m** Kick %s : fd : %d is too high **\033[0;0m\n",
	 inet_ntoa(client_sin.sin_addr), cs);

      return ;
    }
  init_client(e, cs);
  e->fds[cs].type = FD_CLIENT;
  e->fds[cs].fct_read = client_read;
  e->fds[cs].fct_write = client_write;
  my_room(e, cs);
  FD_SET(cs, &e->fd_write);
  FD_CLR(cs, &e->fd_read);
}
