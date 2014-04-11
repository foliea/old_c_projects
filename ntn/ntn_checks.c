/*
** ntn_checks.c for ntn_checks in /u/all/folie_a/cu/rendu/c/proj/ntn
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun May 24 15:24:32 2009 adrien folie
** Last update Sun May 24 20:42:01 2009 adrien folie
*/

#include <stdlib.h>
#include "ntn.h"

int	check_str(int i, char *str)
{
  ++i;
  while (str[i] != '\0')
    {
      if (str[i] != '0')
        return (1);
      ++i;
    }
  return (0);
}

int	check2_str(int i, char *str)
{
  int	temp;

  temp = 3;
  --i;
  if (str[i] == '1')
    --i;
  while (i >= 0 && temp > 0)
    {
      if (str[i] > '0')
        {
          return (1);
        }
      --temp;
      --i;
    }
  return (0);
}

int	check_str_limit(int i, char *str)
{
  int	temp;

  temp = 0;
  ++i;
  while (str[i] != '\0' && temp < 3)
    {
      if (str[i] != '0')
        return (1);
      ++i;
      temp++;
    }
  return (0);
}

void	check_maxint(int i, char *str)
{
  if (my_strlen(str) == 10)
    {
      if (str[i] >= '3')
	my_error_int();
    }
}

void	check_zero(int pos, char *str, int i)
{
  if (pos == 1 && str[i] == '0')
    {
      my_putstr("zero\n");
      exit(EXIT_SUCCESS);
    }
}
