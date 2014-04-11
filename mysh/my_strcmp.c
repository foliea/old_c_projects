/*
** my_strcmp.c for my_strcmp in /u/all/folie_a/cu/rendu/piscine/Jour_06
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Mar 16 20:43:45 2009 adrien folie
** Last update Tue Jun  2 14:32:12 2009 adrien folie
*/

#include "minishell.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (-1);
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (-1);
      ++i;
    }
  return (1);
}
