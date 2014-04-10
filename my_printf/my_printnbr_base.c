/*
** my_printnbr_base.c for my_printnbr_base in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar 17 22:16:14 2009 adrien folie
** Last update Tue Apr 28 17:20:32 2009 adrien folie
*/

#include "my.h"

int	my_check_nbr_u(unsigned int nbr, int base_div, int *i)
{
  int	debut;

  debut = nbr / base_div;
  if (debut != 0)
    my_check_nbr_u(debut, base_div, i);
  *i = *i + 1;
  return (*i);
}

int	my_check_nbr_s(int nbr, int base_div, int *i)
{
  int	debut;

  debut = nbr / base_div;
  if (debut != 0)
    my_check_nbr_s(debut, base_div, i);
  *i = *i + 1;
  return (*i);
}

int	my_putnbr_base_u(unsigned int nbr, char *base, int *i)
{
  int	base_div;
  int	fin;
  int	debut;

  base_div = my_strlen(base);
  fin = nbr % base_div;
  debut = nbr / base_div;
  if (debut != 0)
    my_putnbr_base_u(debut, base, i);
  if ((fin > 9) && (fin < 36))
    my_putchar(fin - 10 + 'a');
  else
    my_putchar(fin + '0');
  *i = *i + 1;
  return (*i);
}

int	my_putnbr_base_maj(unsigned int nbr, char *base, int *i)
{
  int	base_div;
  int	fin;
  int	debut;

  base_div = my_strlen(base);
  fin = nbr % base_div;
  debut = nbr / base_div;
  if (debut != 0)
    my_putnbr_base_maj(debut, base, i);
  if ((fin > 9) && (fin < 36))
    my_putchar(fin - 10 + 'A');
  else
    my_putchar(fin + '0');
  *i = *i + 1;
  return (*i);
}

int	my_putnbr_base_s(int nbr, char *base, int *i)
{
  int	base_div;
  int	fin;
  int	debut;

  base_div = my_strlen(base);
  fin = nbr % base_div;
  debut = nbr / base_div;
  if (debut != 0)
	my_putnbr_base_s(debut, base, i);
  if ((fin > 9) && (fin < 36))
    my_putchar(fin - 10 + 'a');
  else
    my_putchar(fin + '0');
  *i = *i + 1;
  return (*i);
}
