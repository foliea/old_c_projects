/*
** my_op.c for my_op in /u/all/folie_a/cu/rendu/piscine/Jour_10/do-op
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Mar 23 14:58:27 2009 adrien folie
** Last update Mon Mar 23 17:30:58 2009 adrien folie
*/

#include <stdlib.h>
#include "my_libc.h"

int	my_add(int n1, int n2)
{
  return (n1 + n2);
}

int	my_sub(int n1, int n2)
{
  return (n1 - n2);
}

int	my_div(int n1, int n2)
{
  if (n2 == 0)
    {
      my_putstr("Division by 0 useless\n");
      exit(EXIT_FAILURE);
    }
  return (n1 / n2);
}

int	my_mult(int n1, int n2)
{
  return (n1 * n2);
}

int	my_mod(int n1, int n2)
{
  if (n2 == 0)
    {
      my_putstr("Modulo  by 0 useless\n");
      exit(EXIT_FAILURE);
    }
  return (n1 % n2);
}
