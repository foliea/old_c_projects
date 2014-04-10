/*
** xfunctions.c for my irc in /u/all/folie_a/public/dedern/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Apr 28 19:25:16 2010 edern bienvenu
** Last update Wed Apr 28 22:21:28 2010 adrien folie
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	aff_err(char *str);

int	xopen(char *path, int flag)
{
  int	fd;

  if ((fd = open(path, flag)) == -1)
    aff_err("OPEN ERROR");
  return (fd);
}

void	*xmalloc(int size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    aff_err("MALLOC FAILED");
  return (ptr);
}

int	xread(int fd, void *buf, int bytes)
{
  int	nb;

  if ((nb = read(fd, buf, bytes)) == -1)
    aff_err("READ FAILED");
  return (nb);
}
