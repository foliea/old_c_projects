/*
** xmalloc.c for lemipc in /u/all/folie_a/cu/public/dedern/lemipc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Sun May 23 21:55:54 2010 adrien folie
** Last update Wed Jun 16 00:26:02 2010 edern bienvenu
*/

#include <stdlib.h>

void	aff_error(char *str);

void	*xmalloc(int size)
{
  void	*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    aff_error("Malloc failed");
  return (ptr);
}
