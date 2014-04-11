/*
** free_list_buffer.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Jun 17 02:51:42 2010 adrien folie
** Last update Sun Jun 20 19:22:15 2010 adrien folie
*/

#include <stdlib.h>
#include "cbuff.h"
#include "free_obj.h"

extern t_dcircular	*buff_list;

void		free_list_buffer(void)
{
  t_circular	*tmp;

  while (buff_list->begin != NULL)
    {
      tmp = buff_list->begin;
      buff_list->begin = buff_list->begin->next;
      free_cbuffer(tmp->cbuff, 1);
      free(tmp);
    }
}
