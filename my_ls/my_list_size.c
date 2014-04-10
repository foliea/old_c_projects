/*
** my_list_size.c for my_list_size in /u/all/folie_a/cu/rendu/piscine/Jour_11
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Mar 25 10:46:51 2009 adrien folie
** Last update Tue May 26 07:11:31 2009 adrien folie
*/

#include "my_ls.h"

int	my_list_size(t_list *begin)
{
  int	i;

  i = 0;
  while (begin != 0)
    {
      begin = begin->next;
      i = i + 1;
    }
  return (i);
}
