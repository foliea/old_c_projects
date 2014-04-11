/*
** my_strdup.c for my_strdup.c in /u/all/folie_a/cu/rendu/piscine
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Mar 18 11:43:46 2009 adrien folie
** Last update Fri Nov  6 23:10:31 2009 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>
int	my_strlen(char *str);

char	*my_strdup(char *str)
{
  char	*dup;
  int	i;

  i = 0;
  dup = malloc((my_strlen(str) + 1) * sizeof(*str));
  if (dup == NULL)
    {
      fprintf(stderr, "MAP ERROR\n");
      exit(EXIT_FAILURE);
    }
  while (str[i] != '\0')
    {
      dup[i] = str[i];
      i = i + 1;
    }
  dup[i] = '\0';
  return (dup);
}
