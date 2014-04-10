/*
n e** xfunctions.c for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Apr  9 17:33:35 2010 adrien folie
** Last update Sun Apr 18 03:22:18 2010 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

void	aff_error(char *str);

void	*xmalloc(int size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    aff_error("MALLOC FAILED");
  return (ptr);
}

int	xwrite(int d, const void *buf, size_t nbytes)
{
  int	i;

  if ((i = write(d, buf, nbytes)) == -1)
    exit(EXIT_FAILURE);
  return (i);
}
