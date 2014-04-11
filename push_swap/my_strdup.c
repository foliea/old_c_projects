/*
** my_strdup.c for my_strdup.c in /u/all/folie_a/cu/rendu/piscine
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Mar 18 11:43:46 2009 adrien folie
** Last update Fri Jul  3 10:42:09 2009 thibaut ottemer
*/

#include <stdlib.h>
#include "push.h"

char	*my_strdup(char *str)
{
  char	*dup;
  int	i;

  i = 0;
  dup = malloc((my_strlen(str) + 1) * sizeof(*dup));
  if (dup == NULL)
    exit(EXIT_FAILURE);
  while (str[i] != '\0')
    {
      dup[i] = str[i];
      i++;
    }
  dup[i] = '\0';
  return (dup);
}
