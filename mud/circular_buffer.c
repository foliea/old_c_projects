/*
** circular_buffer.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:06:33 2010 adrien folie
** Last update Mon Jul 12 23:22:57 2010 adrien folie
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "tlist.h"
#include "cbuff.h"
#include "serveur.h"
#include "remove.h"

int		check_if_cmd(t_cbuff *cbuff)
{
  t_ebuff	*temp;
  int		i;

  temp = cbuff->begin;
  i = 0;
  while (cbuff->begin != NULL)
    {
      if (cbuff->begin->character == '\n')
	{
	  cbuff->begin = temp;
	  return (i);
	}
      ++i;
      cbuff->begin = cbuff->begin->next;
    }
  cbuff->begin =  temp;
  return (-1);
}

char		*recup_line(t_cbuff *cbuff, int size)
{
  int		i;
  char		*cmd;
  t_ebuff	*tmp;

  i = 0;
  cmd = xmalloc((size + 2) * sizeof(size));
  while (i < size)
    {
      cmd[i] = cbuff->begin->character;
      ++i;
      cbuff->taille--;
      tmp = cbuff->begin;
      cbuff->begin = cbuff->begin->next;
      free(tmp);
    }
  cbuff->taille--;
  cmd[i] = '\n';
  cmd[i + 1] = '\0';
  tmp = cbuff->begin;
  cbuff->begin = cbuff->begin->next;
  free(tmp);
  return (cmd);
}

char	*manage_cbuff(t_cbuff *cbuff, int fd, int mode)
{
  char	*tmp;
  int	size;

  if ((size = check_if_cmd(cbuff)) != -1)
    {
      tmp = recup_line(cbuff, size);
      if (mode == CREAD)
	printf("\033[0;36mReceived message from %d : \033[0;0m%s\n",
	       fd, tmp);
      else
	printf("\033[0;31mSend message to %d : \033[0;0m%s\n",
	       fd, tmp);
      return (tmp);
    }
  return (NULL);
}

void	stack_to_cbuff(t_env *e, t_cbuff *cbuff, int nb_read, int fd)
{
  int	i;
  char	*temp;

  i = 0;
  temp = e->fds[fd].buf_read;
  while (i < nb_read)
    {
      put_in_cbuff(cbuff, temp[i], 1);
      ++i;
    }
  if (cbuff->taille > EXCESS_FLOOD && check_if_cmd(cbuff) == -1)
    {
      e->fds[fd].type = FD_FREE;
      close(fd);
      ret_player(e->players, fd);
      printf("\033[0;33m** Kick : (excess flood) %d **\033[0;0m\n", fd);
      return ;
    }
}

void	stack_write(t_cbuff *cbuff, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      put_in_cbuff(cbuff, str[i], 1);
      ++i;
    }
}
