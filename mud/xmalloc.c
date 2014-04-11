/*
** xmalloc.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul 12 23:50:26 2010 adrien folie
** Last update Mon Jul 12 23:51:46 2010 adrien folie
*/

#include <stdlib.h>
#include "utils.h"

void	*xmalloc(int size)
{
  void	*obj;

  if ((obj = malloc(size)) == NULL)
    aff_error("malloc failed");
  return (obj);
}
