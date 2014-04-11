/*
** my_strdup.c for my_strdup.c in /u/all/folie_a/cu/rendu/piscine
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Mar 18 11:43:46 2009 adrien folie
** Last update Sat Sep 12 17:21:46 2009 thibaut ottemer
*/

#include <stdlib.h>
#include "sudoki-bi.h"

char	*my_strdup(char *str)
{
  char	*dup;
  int	i;

  i = 0;
  dup = malloc((my_strlen(str) + 1) * sizeof(*str));
  if (dup == NULL)
    my_put_error("Can't perform malloc\n");
  while (str[i] != '\0')
    {
      dup[i] = str[i];
      i = i + 1;
    }
  dup[i] = '\0';
  return (dup);
}
