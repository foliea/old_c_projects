/*
** gnr.c for  in /u/all/bienve_e/public/zappy/2_antoine/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sat Jun 19 04:01:33 2010 antoine goueslard
** Last update Sun Jun 20 21:12:45 2010 antoine goueslard
*/

#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "client.h"

char	*xreal(char *ret, int size)
{
  if ((ret = realloc(ret, size)) == 0)
    {
      my_puts(2, "pb in realloc\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int	xrecv(int s, char* buff, int len, int flag)
{
  int	i;

  if ((i = recv(s, buff, len, flag)) < 0)
    {
      my_puts(2,"pb in reallc\n");
      exit(EXIT_FAILURE);
    }
  return (i);
}

char	*mstrcat(char *dest, char *src, int *pos)
{
  int	i;
  int	j;

  if (strlen(src) == 0)
    return (dest);
  i = *pos;
  j = strlen(dest) -1;
  if (j == -1)
    j = 0;
  while (src[i] != 0)
    {
      dest[i + j] = src[i];
      i++;
    }
  *pos = i;
  dest[i + j] = 0;
  return (dest);
}

char		*gnr(int s)
{
  int		d;
  int		pos;
  char		buff[4096];
  char		*ret;

  d = 0;
  pos = 0;
  if ((ret = calloc(4096, sizeof(char))) == 0)
      exit(EXIT_FAILURE);
  while (pos == 0)
    {
      memset(buff, 0, 4096);
      recv(s, buff, 4096, MSG_DONTWAIT);
      if (strlen(buff) == 0 && d == 0)
	{
	  return (ret);
	}
      ret = mstrcat(ret, buff, &pos);
      if (pos == 4095 || (pos != 0 && buff[pos - 1] != '\n'))
	{
	  ret = xreal(ret, 4096);
	  pos = 0;
	}
      d = 1;
    }
  return (ret);
}
