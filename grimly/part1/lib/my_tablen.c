/*
** my_tablen.c for my_tablen in /u/all/jacque_c/public/42sh/lib
** 
** Made by leo lopez
** Login   <lopez_l@epitech.net>
** 
** Started on  Tue Nov  3 14:47:05 2009 leo lopez
** Last update Tue Nov  3 14:47:26 2009 leo lopez
*/

#include <stdlib.h>

int     my_tablen(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}
