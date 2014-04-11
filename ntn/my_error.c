/*
** ntn_recup.c for ntn_recup in /u/all/folie_a/cu/rendu/c/proj/ntn
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri May 22 23:03:01 2009 adrien folie
** Last update Sun May 24 15:12:54 2009 thibaut ottemer
*/

#include "ntn.h"

void	my_error(void)
{
  if ((write(2,"Argument Invalid\n", 17)) == -1)
    exit(EXIT_FAILURE);
  exit(EXIT_FAILURE);
}

void	my_error_int(void)
{
  if ((write(2,"too large for int\n", 18)) == -1)
    exit(EXIT_FAILURE);
  exit(EXIT_FAILURE);
}

void	check_num(char *str, int i)
{
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
	my_error();
      i++;
    }
  if (str[my_strlen(str) - 1] == '-')
    my_error();
}

int	check_limit(char *str, int i, int j)
{
  int	res;

  res = 0;
  while (str[j] == '-' || str[j] == '0')
    {
      j++;
      i++;
    }
  if ((str[i + 0] >= '3' && my_strlen(&str[i + 0]) == 10 + j) ||
      (str[i + 0] <= '2' && (my_getnbr(&str[i + 1]) > 147483647 + i)))
    res = 1;
  return (res);
}
