/*
** my_tablen.c for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Apr 15 00:55:03 2010 adrien folie
** Last update Sun Apr 18 19:45:41 2010 adrien folie
*/

#include <stdlib.h>

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}
