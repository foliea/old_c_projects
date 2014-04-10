/*
** my_strdup_select.c for my_strdup_select.c in /u/all/folie_a/cu/rendu/piscine
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Mar 18 11:43:46 2009 adrien folie
** Last update Mon Mar 23 12:22:30 2009 adrien folie
*/

#include "my_ls.h"
#include <stdlib.h>

char	*my_strdup_select(char *str, int d, int f)
{
  char	*dup;
  int	i;

  i = 0;
  dup = malloc((f + 1) * sizeof(*dup));
  if (dup == NULL)
    my_error_report(7);
  while (i < f)
    {
      dup[i] = str[d];
      ++i;
      ++d;
    }
  dup[i] = '\0';
  return (dup);
}
