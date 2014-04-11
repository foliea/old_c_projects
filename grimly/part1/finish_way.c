/*
** finish_way.c for finish_way in /u/all/folie_a/cu/rendu/rush/grimly/part1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Nov  8 19:45:24 2009 adrien folie
** Last update Sun Nov  8 19:49:25 2009 adrien folie
*/

#include <stdlib.h>
#include "dlist.h"

void	finish_way(t_dlist *h, char **temp)
{
  t_elem	*tmp;

  tmp = h->begin;
  while (h->begin != NULL)
    {
      temp[h->begin->y][h->begin->x] = 'o';
      h->begin = h->begin->next;
    }
}
