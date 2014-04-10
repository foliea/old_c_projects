/*
** xfunctions.c for my_irc in /u/all/folie_a/cu/test/gtk
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Apr 28 01:13:32 2010 adrien folie
** Last update Wed Apr 28 01:13:37 2010 adrien folie
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	aff_error(char *str);

int	xopen(char *path, int flag)
{
  int	fd;

  if ((fd = open(path, flag)) == -1)
    aff_error("OPEN ERROR");
  return (fd);
}

void	*xmalloc(int size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    aff_error("MALLOC FAILED");
  return (ptr);
}

int	xread(int fd, void *buf, int bytes)
{
  int	nb;

  if ((nb = read(fd, buf, bytes)) == -1)
    aff_error("READ FAILED");
  return (nb);
}
