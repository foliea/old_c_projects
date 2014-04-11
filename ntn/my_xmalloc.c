/*
** my_xmalloc.c for my_xmalloc in /u/all/folie_a/cu/rendu/c/bsq
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr 21 15:30:15 2009 adrien folie
** Last update Thu Apr 30 06:45:26 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>

char	*xmalloc(int size)
{
  char	*tab;

  tab = malloc((size + 1) * sizeof(*tab));
  if (tab == NULL)
    {
      write(2, "Malloc Failed", 13);
      exit(EXIT_FAILURE);
    }
  return (tab);
}
