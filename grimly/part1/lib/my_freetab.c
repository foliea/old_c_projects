/*
** my_freetab.c for my_freetab in /u/all/jacque_c/public/42sh/lib
** 
** Made by leo lopez
** Login   <lopez_l@epitech.net>
** 
** Started on  Tue Nov  3 14:45:47 2009 leo lopez
** Last update Tue Nov  3 14:50:14 2009 leo lopez
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
