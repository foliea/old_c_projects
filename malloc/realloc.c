/*
** realloc.c for malloc in /u/all/folie_a/cu/rendu/proj/malloc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar 23 03:04:21 2010 adrien folie
** Last update Fri Apr  2 01:24:04 2010 adrien folie
*/

#include <stdio.h>
#include <string.h>
#include "malloc.h"

extern struct s_block_descriptor	*buckets[32];

void	*check_realloc_error(t_block_descriptor *temp)
{
  if (is_already_free(buckets[temp->p - 1], temp) == -1)
    {
      my_put_error("in realloc(): warning: pointer to wrong page\n");
      return (NULL);
    }
  if (check_chunk(temp) == -1)
    {
      my_put_error("in realloc(): warning: modified (chunk-) pointer\n");
      return (NULL);
    }
  return (temp);
}

void			*realloc(void *ptr, size_t size)
{
  void			*new;
  t_block_descriptor	*temp;
  size_t		old_size;

    show_alloc_mem();
  temp = (t_block_descriptor *) ptr - 1;
  if (ptr != NULL && check_realloc_error(temp) == NULL)
    return (NULL);
  if (ptr == NULL || (int) (old_size = is_malloc(temp, 0)) == -1)
    {
      if (ptr != NULL)
	my_put_error("in realloc(): warning: malloc() has never been called\n");
      ptr = malloc(size);
      return (ptr);
    }
  if (old_size < size)
    return (ptr);
  new = malloc(size);
  if (new == NULL)
    return (ptr);
  new = memcpy(new, ptr, old_size);
  free(ptr);
  ptr = new;
  return (new);
}
