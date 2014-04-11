/*
** ret_obj.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:27:40 2010 adrien folie
** Last update Wed Jul  7 02:16:35 2010 adrien folie
*/

#include <stdlib.h>
#include "cbuff.h"

void		free_cbuff(t_cbuff *cbuff)
{
  t_ebuff	*tmp;

  while (cbuff->begin != NULL)
    {
      tmp = cbuff->begin;
      cbuff->begin = cbuff->begin->next;
      free(tmp);
    }
}
