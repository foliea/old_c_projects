/*
** my_xmalloc.c for my_xmalloc in /u/all/folie_a/cu/rendu/c/bsq
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr 21 15:30:15 2009 adrien folie
** Last update Fri Jul  3 10:50:26 2009 thibaut ottemer
*/

#include <stdlib.h>
#include <unistd.h>

void	*xmalloc(int size)
{
  void	*tab;

  tab = malloc(size);
  if (tab == NULL)
    {
      write(2, "Malloc Failed", 13);
      exit(EXIT_FAILURE);
    }
  return (tab);
}
