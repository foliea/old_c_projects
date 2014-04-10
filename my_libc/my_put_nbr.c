/*
** my_put_nbr.c for my_put_nbr in /u/all/folie_a/cu/rendu/piscine/Jour_03
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Mar 11 20:40:10 2009 adrien folie
** Last update Thu Apr 16 11:43:22 2009 adrien folie
*/

#include "my_libc.h"

int	display(int i, unsigned nb2, int p, int nb)
{
  int	aff;
  int	car;

  aff = 0;
  car = 0;
  if (nb < 0)
    {
      my_putchar('-');
    }
  while (car < i)
    {
      aff = nb2 / p;
      if (nb < 0)
	{
	  my_putchar(aff + '0');
 	}
      else
	{
	  my_putchar(aff + '0');
	}
      nb2 = nb2 % p;
      p = p / 10;
      car = car + 1;
    }
  return (0);
}

int	power(int i, unsigned nb2, int nb)
{
  int	j;
  int	p;

  j = 1;
  p = 1;
  while (j < i)
    {
      p = p * 10;
      j = j + 1;
    }
  display(i, nb2, p, nb);
  return (0);
}

int	my_put_nbr(int nb)
{
  int	a;
  int	i;
  unsigned int nb2;

  i = 0;
  if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  if (nb < 0) 
    {
      nb2 = - nb;
    }
  else
    {
      nb2 = nb;
    }
  a = nb2;
  while (a != 0)
    {
      a = a / 10;
      i = i + 1;
    }
  power(i, nb2, nb);
  return (0);
}
