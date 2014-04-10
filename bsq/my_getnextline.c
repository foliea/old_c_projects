/*
** my_getnextline.c for my_getnextline in /u/all/folie_a/cu/rendu/c/my_getnextline
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri Apr 24 13:34:55 2009 adrien folie
** Last update Fri May  8 16:56:22 2009 thibaut ottemer
*/

#include "bsq.h"
#define BUFF_SIZE 4096
#define	BUFF_CHAR 8192

int	xread(const int fd, char *buffer, int size)
{
  int	nb_read;

  if ((nb_read = read(fd, buffer, size)) == -1)
    {
      if((write(2, "Read Failed\n", 12)) == -1)
	exit(EXIT_FAILURE);
      exit(EXIT_FAILURE);
    }
  return (nb_read);
}

char		*get_next_line(const int fd)
{
  static int	nb_read = 0;
  static char	buffer[BUFF_SIZE];
  static int	i = 0;
  char		*res;
  int		j;

  res = xmalloc(BUFF_CHAR + 1);
  j = 0;
  while (i != -1)
    if (i == 0 && (nb_read = xread(fd, buffer, BUFF_SIZE)) == 0)
      i = -1;
    else
      {
	while (i < nb_read)
	  {
	    res[j++] = buffer[i++];
	    if (buffer[i - 1] == '\n' || i == nb_read)
	      if (buffer[i - 1] == '\n')
		{
		  res[j - 1] = '\0';
		  return (res);
		}
	  }
	i = 0;
      }
  return (NULL);
}
