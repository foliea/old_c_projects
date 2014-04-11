/*
** ret_cbuff.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Jun 15 03:39:59 2010 adrien folie
** Last update Sun Jun 20 17:31:37 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include "cbuff.h"
#include "ret_cbuff.h"

extern t_dcircular	*buff_list;

void		free_cbuffer(t_cbuff *cbuffer, int end)
{
  t_ebuff	*tmp;
  int		i;

  i = 1;
  while (cbuffer->begin != NULL)
    {
      tmp = cbuffer->begin;
      cbuffer->begin = cbuffer->begin->next;
      free(tmp);
    }
  if (end == 1)
    {
      while (i < cbuffer->empty)
	{
	  free(cbuffer->queue[i]);
	  i++;
	}
    }
  free(cbuffer);
}

void		remove_middle_cbuffer(int fd)
{
  t_circular	*save;
  t_circular	*tmp;
  int		i;

  i = 0;
  save = buff_list->begin;
  while (buff_list->begin != NULL)
    {
      if (buff_list->begin->fd == fd)
	{
	  tmp = buff_list->begin;
	  if (i == 0)
	    cremove_mid_beg();
	  else if (i > 0 && i < buff_list->taille - 1)
	    cremove_mid_mid(save);
	  else
	    cremove_mid_end(save);
	  buff_list->taille--;
	  free_cbuffer(tmp->cbuff, 1);
	  free(tmp);
	  return ;
	}
      buff_list->begin = buff_list->begin->next;
      ++i;
    }
}

void		ret_cbuffer(int fd)
{
  t_circular	*tmp;

  if (buff_list->taille == 1 && buff_list->begin->fd == fd)
    {
      tmp = buff_list->begin;
      my_init_dcircular(buff_list);
      free_cbuffer(tmp->cbuff, 1);
      free(tmp);
    }
  if (buff_list->taille > 1)
    remove_middle_cbuffer(fd);
}
