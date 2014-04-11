/*
** strlib.c for \ in /u/all/gouesl_a/cu/rendu/my_ftp/common
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Apr 18 20:43:54 2010 antoine goueslard
** Last update Sat May 29 02:47:25 2010 antoine goueslard
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	my_puts(int fd, char *str)
{
  if (write(fd, str, strlen(str)) < 0)
	exit(EXIT_FAILURE);
}

void	my_putstr(char *str)
{
  my_puts(1, str);
}

void	my_putnbr(int i)
{
  printf("%i \n", i);
}

void	put_error(char *str)
{
  my_puts(2, str);
  exit(EXIT_FAILURE);
}

int	check_word(char *src, char c)
{
  int	i;

  i = 0;
  while (src[i] != c
	 && src[i] != 0)
    i++;
  if (src[i] != 0)
    return (i);
  return (-1);
}

char	*my_copy(char *src, int i)
{
  src[i++] = 0;
  return (&src[i]);
}

char		**expand(char **lines, int end, char c)
{
  int		i;

  i = check_word(lines[end], c);
  if (i == -1)
    {
      lines[end + 1] = 0;
      return (lines);
    }
  else
    {
      lines[end + 1] = my_copy(lines[end], i);
      if (lines[end + 1][0] == 0)
	{
	  lines[end + 1] = 0;
	  return (lines);
	}
      return (expand(lines, end + 1, c));
    }
}

char	**stotab(char *path, char c)
{
  char	**lines;
  
  if ((lines = malloc(1024 * sizeof(*lines))) == 0)
    exit(EXIT_FAILURE);
  lines[0] = path;
  lines[1] = 0;
  lines  = expand(lines, 0, c);
  return (lines);
}
