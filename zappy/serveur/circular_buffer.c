/*
** circular_buffer.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Jun  1 23:26:17 2010 adrien folie
** Last update Sun Jun 20 18:48:06 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include "cbuff.h"
#include "fd_puts.h"

void	*xmalloc(int size);

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

void	manage_cbuff(t_cbuff *cbuff, int t, int fd)
{
  char	*tmp;
  int	size;

  while ((size = check_if_cmd(cbuff)) != -1)
    {
      tmp = recup_line(cbuff, size);
      print_time();
      printf("\033[0;36mReceived message from %d : \033[0;0m%s\n",
	     fd, tmp);
      manage_cmd(cbuff, t, tmp, fd);
    }
}

void	aff_cbuff(t_cbuff *cbuff)
{
  t_ebuff	*tmp;

  tmp = cbuff->begin;
  while (cbuff->begin != NULL)
    {
      putchar(cbuff->begin->character);
      cbuff->begin = cbuff->begin->next;
    }
  putchar('\n');
  cbuff->begin = tmp;
}

void	add_to_cbuff(t_cbuff *cbuff, char *temp, int nb_read, int t, int fd)
{
  int	i;

  i = 0;
  if (cbuff->taille > EXCESS_FLOOD)
    {
      cbuff->type = DEAD;
      return ;
    }
  while (i < nb_read)
    {
      put_in_cbuff(cbuff, temp[i], 1);
      ++i;
    }
  manage_cbuff(cbuff, t, fd);
}
