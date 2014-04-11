/*
** free_list_planning.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Jun 17 05:16:42 2010 adrien folie
** Last update Sun Jun 20 19:19:55 2010 adrien folie
*/

#include <stdlib.h>
#include "planning.h"

extern t_tlist	*planning;

void		free_list_planning(void)
{
  t_telem	*tmp;

  while (planning->begin != NULL)
    {
      tmp = planning->begin;
      planning->begin = planning->begin->next;
      free(tmp->cmd);
      free(tmp);
    }
}
