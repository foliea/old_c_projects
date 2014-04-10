/*
** my_list_size.c for my_list_size in /u/all/folie_a/cu/rendu/piscine/Jour_11
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Mar 25 10:46:51 2009 adrien folie
** Last update Tue May 26 06:13:18 2009 adrien folie
*/

#include "my_ls.h"

int	count_blocks(t_list *begin)
{
  int	i;

  i = 0;
  while (begin != 0)
    {
      i += begin->stats.st_blocks;
      begin = begin->next;
    }
  return (i);
}
