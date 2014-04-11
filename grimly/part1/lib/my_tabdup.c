/*
** my_tabdup.c for my_tabdup in /u/all/jacque_c/public/42sh/lib
** 
** Made by leo lopez
** Login   <lopez_l@epitech.net>
** 
** Started on  Tue Nov  3 14:47:34 2009 leo lopez
** Last update Tue Nov  3 14:48:56 2009 leo lopez
*/

#include <stdlib.h>
char	*my_strdup(char *str);
int	my_tablen(char **tab);

char	**my_tabdup(char **tab)
{
  int	i;
  char	**cpy;

  i = 0;
  cpy = malloc((my_tablen(tab) + 1) * sizeof(*tab));
  if (cpy == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      cpy[i] = my_strdup(tab[i]);
      if (cpy[i] == NULL)
        return (NULL);
      ++i;
    }
  cpy[i] = NULL;
  return (cpy);
}
