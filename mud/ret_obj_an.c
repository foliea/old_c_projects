/*
** ret_obj_an.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:34:04 2010 adrien folie
** Last update Mon Jul  5 03:35:23 2010 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
#include "tlist.h"

void	remove_mid_end(t_tlist *recup, t_telem *save)
{
  recup->begin->prev->next = NULL;
  recup->end = recup->begin->prev;
  recup->begin = save;
}

void	remove_mid_mid(t_tlist *recup, t_telem *save)
{
  recup->begin->prev->next = recup->begin->next;
  recup->begin->next->prev = recup->begin->prev;
  recup->begin = save;
}

void	remove_mid_beg(t_tlist *team)
{
  team->begin = team->begin->next;
  team->begin->prev = NULL;
}

