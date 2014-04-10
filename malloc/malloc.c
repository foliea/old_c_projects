/*
** malloc.c for malloc in /u/all/folie_a/cu/rendu/proj/malloc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar  2 01:56:20 2010 adrien folie
** Last update Fri Apr  2 01:33:19 2010 adrien folie
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "malloc.h"

t_block_descriptor *list = NULL;
int	mem_begin;

int			is_malloc(t_block_descriptor *ptr, int to_free)
{
  t_block_descriptor	*tmp;
  unsigned int		p;

  tmp = list;
  while (list != NULL)
    {
      if (list == ptr)
	{
	  p = list->p;
	  list = tmp;
	  if (to_free == 1)
	    ret_from_list(ptr);
	  return (p);
	}
      list = list->next;
    }
  list = tmp;
  return (-1);
}

void			show_alloc_mem(void)
{
  t_block_descriptor	*tmp;

  tmp = list;
  printf("break : 0x%x\n", (unsigned int) sbrk(0));
  while (list != NULL)
    {
      printf("0x%x - 0x%x : %d octets\n",
	     (unsigned int) list,
	     (unsigned int) list + power_of_two(list->p),
	     power_of_two(list->p));
      list = list->next;
    }
  list = tmp;
}

int			ret_from_list(t_block_descriptor *ptr)
{
  t_block_descriptor	*tmp;

  if (list == ptr)
    {
      list = list->next;
      return (0);
    }
  tmp = list;
  while (list != NULL)
    {
      if (list->next == ptr)
	list->next = list->next->next;
      list = list->next;
    }
  list = tmp;
  return (0);
}

void			add_to_list(t_block_descriptor *ptr)
{
  t_block_descriptor	*tmp;

  tmp = list;
  list = ptr;
  ptr->next = tmp;
}

void			*malloc(size_t size)
{
  int			n;
  t_block_descriptor	*ptr;

  is_malloc(ptr, 1);
  n = power_of_two(size + sizeof(t_block_descriptor));
  if ((ptr = find_in_freelist(multiple_of_two(n))) == NULL)
    {
      ptr = sbrk(n);
      if ((int) ptr == -1)
	return (NULL);
      ptr->p = multiple_of_two(n);
      ptr->next = NULL;
      ptr->magic = MAGIC;
      ptr += 1;
    }
  add_to_list(ptr - 1);
  return (ptr);
}
