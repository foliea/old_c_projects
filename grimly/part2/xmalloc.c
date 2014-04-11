/*
** xmalloc.c for rtv1 in /u/all/otteme_t/cu/rendu/c/rtv1
** 
** Made by thibaut ottemer
** Login   <otteme_t@epitech.net>
** 
** Started on  Tue Oct  6 16:31:33 2009 thibaut ottemer
** Last update Tue Oct  6 16:34:55 2009 thibaut ottemer
*/

#include <stdlib.h>
#include <unistd.h>

void	*xmalloc(int size)
{
  void	*str;

  if ((str = malloc(size)) == NULL)
    {
      write(2, "Can't perform malloc\n", 21);
      exit(EXIT_FAILURE);
    }
  return (str);
}
