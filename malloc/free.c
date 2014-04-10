/*
** freelist.c for malloc in /u/all/folie_a/cu/rendu/proj/malloc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar  4 01:57:54 2010 adrien folie
** Last update Wed Mar 31 20:31:06 2010 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
#include "malloc.h"

struct s_block_descriptor	*buckets[32] = {NULL, NULL, NULL, NULL, NULL,
						NULL, NULL, NULL, NULL, NULL,
						NULL, NULL, NULL, NULL, NULL,
						NULL, NULL, NULL, NULL, NULL,
						NULL, NULL, NULL, NULL, NULL,
						NULL, NULL, NULL, NULL, NULL,
						NULL, NULL};

int	is_already_free(t_block_descriptor *list, t_block_descriptor *ptr)
{
  while (list != NULL)
    {
      if (list == ptr)
	return (-1);
      list = list->next;
    }
  return (0);
}

void			put_in_freelist(t_block_descriptor *ptr)
{
  t_block_descriptor	*tmp;

  tmp = buckets[ptr->p - 1];
  buckets[ptr->p - 1] = ptr;
  ptr->next = tmp;
}

void			*find_in_freelist(int p)
{
  void			*ptr;
  t_block_descriptor	*tmp;

  ptr = NULL;
  if (buckets[p - 1] != NULL)
    {
      tmp = buckets[p - 1];
      ptr = buckets[p - 1] + 1;
      buckets[p - 1] = buckets[p - 1]->next;
      tmp->next = NULL;
    }
  return (ptr);
}

void			free(void *ptr)
{
  t_block_descriptor	*temp;

  if (ptr == NULL)
    return ;
  temp = (t_block_descriptor *) ptr - 1;
  if (check_chunk(temp) == -1)
    {
      my_put_error("in free(): warning: modified (chunk-) pointer\n");
      return ;
    }
  if (is_already_free(buckets[temp->p - 1], temp) == -1)
    {
      my_put_error("in free(): warning: page is already free\n");
      return ;
    }
    if (is_malloc(temp, 1) == -1)
    {
      my_put_error("in free(): warning: malloc() has never been called\n");
      return ;
    }
  ret_from_list(temp);
  put_in_freelist(temp);
  return ;
}
