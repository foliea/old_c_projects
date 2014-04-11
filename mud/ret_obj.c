/*
** ret_obj.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:27:40 2010 adrien folie
** Last update Mon Jul 12 23:17:22 2010 adrien folie
*/

#include <stdlib.h>
#include <string.h>
#include "tlist.h"
#include "cbuff.h"
#include "remove.h"


void		remove_middle_inv(t_tlist *inv, char *obj)
{
  t_telem	*save;
  t_telem	*tmp;
  int		i;

  i = 0;
  save = inv->begin;
  while (inv->begin != NULL)
    {
      if (strcmp(inv->begin->data, obj) == 0)
	{
	  tmp = inv->begin;
	  if (i == 0)
	    remove_mid_beg(inv);
	  else if (i > 0 && i < inv->taille - 1)
	    remove_mid_mid(inv, save);
	  else
	    remove_mid_end(inv, save);
	  inv->taille--;
	  free(tmp->data);
	  free(tmp);
	  return ;
	}
      inv->begin = inv->begin->next;
      ++i;
    }
}

void		ret_obj(t_tlist *inv, char *obj)
{
  t_telem	*tmp;

  if (inv->taille == 1 && strcmp(inv->begin->data, obj) == 0)
    {
      tmp = inv->begin;
      init_tlist(inv);
      free(tmp->data);
      free(tmp);
    }
  if (inv->taille > 1)
    remove_middle_inv(inv, obj);
}

void		free_objs(t_tlist *objs)
{
  t_telem	*tmp;

  while (objs->begin != NULL)
    {
      tmp = objs->begin;
      objs->begin = objs->begin->next;
      free(tmp->data);
      free(tmp);
    }
}
