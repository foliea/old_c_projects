/*
** my_freetab.c for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr  6 17:07:49 2010 adrien folie
** Last update Tue Apr  6 17:07:50 2010 adrien folie
*/

#include <stdlib.h>

void	my_freetab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
}
