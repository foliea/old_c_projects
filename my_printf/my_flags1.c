/*
** my_flags1.c for my_flags1 in /u/all/folie_a/cu/rendu/c/my_printf
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr 14 19:14:38 2009 adrien folie
** Last update Tue Apr 28 21:18:44 2009 adrien folie
*/

#include "my.h"

int	my_decimal(va_list *ap, int prec)
{
  int	d;
  int	i;
  int	j;
  int	sign;

  i = 0;
  sign = 0;
  d = va_arg(*ap, int);
  if (d < 0)
    {
      my_putchar('-');
      d = -d;
      sign = 1;
    }
  j = my_check_nbr_s(d, 10, &i);
  if (prec > j)
    i = my_print_zero(prec, j);
  else
    i = 0;
  d = my_putnbr_base_s(d, "0123456789", &i);
  return (d + sign);
}

int		my_udecimal(va_list *ap, int prec)
{
  unsigned int	u;
  int		i;
  int		j;

  i = 0;
  u = va_arg(*ap, unsigned int);
  j = my_check_nbr_u(u, 10, &i);
  if (prec > j)
    i = my_print_zero(prec, j);
  else
    i = 0;
  u = my_putnbr_base_u(u, "0123456789", &i);
  return (u);
}

int	my_string(va_list *ap, int prec)
{
  char	*str;
  int	i;

  str = va_arg(*ap, char *);
  i = my_printstr(str, prec);
  return (i);
}

int	my_character(va_list *ap, int prec)
{
  int	c;

  prec = prec;
  c = va_arg(*ap, int);
  my_putchar(c);
  return (1);
}

int	my_put_purcent(va_list *ap, int prec)
{
  prec = prec;
  ap = ap;
  my_putchar('%');
  return (1);
}
