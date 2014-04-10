/*
** my_flags2.c for my_flags2 in /u/all/folie_a/cu/rendu/c/my_printf
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Apr 15 14:33:40 2009 adrien folie
** Last update Tue Apr 28 23:13:52 2009 adrien folie
*/

#include "my.h"

int		my_hex_maj(va_list *ap, int prec)
{
  unsigned int	x;
  int	i;
  int	j;

  i = 0;
  x = va_arg(*ap, unsigned int);
  j = my_check_nbr_u(x, 16, &i);
  if (prec > j)
    i = my_print_zero(prec, j);
  else
    i = 0;
  x = my_putnbr_base_maj(x, "0123456789ABCDEF", &i);
  return (x);
}

int		my_binaire(va_list *ap, int prec)
{
  unsigned int	b;
  int		i;
  int		j;

  i = 0;
  b = va_arg(*ap, unsigned int);
  j = my_check_nbr_u(b, 2, &i);
  if (prec > j)
    i = my_print_zero(prec, j);
  else
    i = 0;
  b = my_putnbr_base_u(b, "01", &i);
  return (b);
}

int		my_hex_min(va_list *ap, int prec)
{
  unsigned int	x;
  int		i;
  int		j;

  i = 0;
  x = va_arg(*ap, unsigned int);
  j = my_check_nbr_u(x, 16, &i);
  if (prec > j)
    i = my_print_zero(prec, j);
  else
    i = 0;
  x = my_putnbr_base_u(x, "0123456789ABCDEF", &i);
  return (x);
}

int		my_octal(va_list *ap, int prec)
{
  unsigned int	o;
  int		i;
  int		j;

  i = 0;
  o = va_arg(*ap, unsigned int);
  j = my_check_nbr_u(o, 8, &i);
  if (prec > j)
    i = my_print_zero(prec, j);
  else
    i = 0;
  o = my_putnbr_base_u(o, "01234567", &i);
  return (o);
}

int		my_pointer(va_list *ap, int prec)
{
  unsigned int	p;
  int		i;
  int		j;
  
  i = 0;
  p = va_arg(*ap, unsigned int);
  if (write(1, "0x", 2) == -1)
    exit(EXIT_FAILURE);
  j = my_check_nbr_u(p, 16, &i);
  if (prec > j)
    i = my_print_zero(prec, j);
  else
    i = 0;
  p = my_putnbr_base_u(p, "0123456789ABCDEF", &i);
  return (p + 2);
}
