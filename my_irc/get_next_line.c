/*
** get_next_line.c for get next line in /u/all/folie_a/public/dedern/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Apr 28 19:25:25 2010 edern bienvenu
** Last update Wed Apr 28 19:25:26 2010 edern bienvenu
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*verif_and_alloc(int fd, char *str)
{
  if (fd == -1)
    fprintf(stderr, GNL_ERROR_FILE);
  str = malloc(sizeof(*str) * (BUFF_RETURN + 1));
  return (str);
}

char	*cpy_line(char *buffer, char *str, int *j, int *i)
{
  while (buffer[*j] != '\n' && buffer[*j] != '\0' && *i < BUFF_RETURN)
    {
      str[*i] = buffer[*j];
      *i = *i + 1;
      *j = *j + 1;
    }
  if (buffer[*j] == '\n' || *i == BUFF_RETURN)
    str[*i] = '\0';
  return (str);
}

char	*get_next_line(const int fd)
{
  char		*str;
  int		i;
  static int	nb_read;
  static int	j;
  static char	buffer[BUFF_SIZE + 1];

  i = 0;
  str = NULL;
  if (j == 0 && (nb_read = read(fd, buffer, BUFF_SIZE)) <= 0)
    return (NULL);
  str = verif_and_alloc(fd, str);
  while (i < BUFF_RETURN)
    {
      buffer[nb_read] = '\0';
      str = cpy_line(buffer, str, &j, &i);
      if (buffer[j] == '\n' || i == BUFF_RETURN)
	{
	  j = j + 1;
	  return (str);
	}
      j = 0;
      if (j == 0 && (nb_read = read(fd, buffer, BUFF_SIZE)) <= 0)
	return (i == 0 ? NULL : str);
    }
  return (NULL);
}
