/*
** add_client.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 28 21:31:41 2010 adrien folie
** Last update Sun Jun 20 16:23:27 2010 adrien folie
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
#include "planning.h"
#include "cbuff.h"
#include "fd_puts.h"
#include "player.h"

void	quit_client(int fd);

#define BUFF_SIZE 256

extern t_tlist		*planning;
extern t_dcircular	*buff_list;
extern t_dteam		*team;
extern t_parse		parse;

t_cbuff		*choose_buffer(int fd)
{
  t_circular	*tmp;
  t_cbuff	*cbuff;

  tmp = buff_list->begin;
  while (buff_list->begin != NULL)
    {
      if (buff_list->begin->fd == fd)
	{
	  cbuff = buff_list->begin->cbuff;
	  buff_list->begin = tmp;
	  return (cbuff);
	}
      buff_list->begin = buff_list->begin->next;
    }
  buff_list->begin = tmp;
  return (NULL);
}

void		client_read(t_env *e, int fd)
{
  char		buffer[BUFF_SIZE];
  int		nb_read;
  t_cbuff	*cbuff;
  int		ok;

  ok = 0;
  memset(buffer, 0, BUFF_SIZE);
  nb_read = read(fd, buffer, BUFF_SIZE);
  if (nb_read <= 0)
    {
      e->fds[fd].type = FD_FREE;
      printf("\033[0;33m** Deconnexion from %d **\033[0;0m\n", fd);
      quit_client(fd);
      return ;
    }
  cbuff = choose_buffer(fd);
  if (nb_read != -1 && cbuff != NULL && cbuff->type != DEAD)
    add_to_cbuff(cbuff, buffer, nb_read, e->t, fd);
}

void			add_client(t_env *e, int s)
{
  int			cs;
  struct sockaddr_in	client_sin;
  unsigned int		client_sin_len;

  client_sin_len = sizeof(client_sin);
  cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
  if (cs == -1)
    return ;
  my_put_in_dcircular(buff_list, cs, 1);
  printf("\033[0;33m** New Connexion from %s **\033[0;0m\n",
	 inet_ntoa(client_sin.sin_addr));
  fd_puts(cs, "BIENVENUE\n");
  printf("\033[0;31mSending to %d :\033[0;0m BIENVENUE\n", cs);
  e->fds[cs].type = FD_CLIENT;
  e->fds[cs].fct_read = client_read;
  e->fds[cs].fct_write = NULL;
}
