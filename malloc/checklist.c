/*
** checklist.c for malloc in /u/epitech_2013/bienve_e/cu/test
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri Mar 26 04:06:42 2010 edern bienvenu
** Last update Wed Mar 31 20:36:36 2010 adrien folie
*/

#include <unistd.h>
#include "malloc.h"

int	check_chunk(t_block_descriptor *ptr)
{
  if (ptr->magic != MAGIC)
    return (-1);
  return (0);
}
