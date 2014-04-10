/*
** my_strlen.c for my_strlen in /u/all/folie_a/cu/rendu/piscine/Jour_04
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Thu Mar 12 17:18:15 2009 adrien folie
** Last update Sat Jun 13 14:32:36 2009 adrien folie
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    ++i;
  return (i);
}

int	my_check_str(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	return (1);
      ++i;
    }
  return (0);
}
