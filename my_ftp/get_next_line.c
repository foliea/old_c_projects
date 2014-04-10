/*
** get_next_line.c for get_next_line.c in /u/all/folie_a/cu/rendu/c/get_next_line
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun May 31 22:22:51 2009 adrien folie
** Last update Sun Apr 18 19:50:05 2010 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#define BUFF_SIZE 2048
#define	BUFF_CHAR 4096

int	xread(const int fd, char *buffer, int size)
{
  int	nb_read;

  if ((nb_read = read(fd, buffer, size)) == -1)
    {
      if ((write(2, "Read Failed\n", 12)) == -1)
	exit(EXIT_FAILURE);
      exit(EXIT_FAILURE);
    }
  return (nb_read);
}

char	*line_malloc(int size)
{
  char	*tab;

  tab = malloc((size + 1) * sizeof(*tab));
  if (tab == NULL)
    {
      if (write(2, "Malloc Failed", 13) == -1)
	exit(EXIT_FAILURE);
      exit(EXIT_FAILURE);
    }
  return (tab);
}

char		*get_next_line(const int fd)
{
  static int	nb_read = 0;
  static char	buffer[BUFF_SIZE];
  static int	i = 0;
  char		*res;
  int		j;

  res = line_malloc(BUFF_CHAR);
  j = 0;
  while (i != -1)
    if (i == 0 && (nb_read = xread(fd, buffer, BUFF_SIZE)) == 0)
      i = -1;
    else
      {
	while (i < nb_read)
	  {
	    res[j++] = buffer[i++];
	    if (buffer[i - 1] == '\n' || i == nb_read || i == BUFF_CHAR)
	      if ((buffer[i - 1] == '\n') || (i == BUFF_CHAR))
		{
		  res[j - 1] = '\0';
		  return (res);
		}
	  }
	i = 0;
      }
  return (NULL);
}
