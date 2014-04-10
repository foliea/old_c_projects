/*
** my_strdup.c for my_strdup.c in /u/all/folie_a/cu/rendu/piscine
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Mar 18 11:43:46 2009 adrien folie
** Last update Mon Mar 23 12:22:30 2009 adrien folie
*/

#include <stdlib.h>

char	*my_strdup(char *str)
{
  char	*dup;
  int	i;

  i = 0;
  dup = malloc((my_strlen(str) + 1) * sizeof(*str));
  while (str[i] != '\0')
    {
      dup[i] = str[i];
      i = i + 1;
    }
  dup[i] = '\0';
  return (dup);
}

