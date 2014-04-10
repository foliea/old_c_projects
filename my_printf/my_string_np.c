/*
** my_string_np.c for my_string_np in /u/all/folie_a/cu/rendu/c/my_printf
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Apr 15 22:47:44 2009 adrien folie
** Last update Wed Apr 29 13:03:51 2009 adrien folie
*/

#include "my.h"

int	my_put_octal(unsigned char np)
{
  int	a;
  
  a = 0;
  my_putchar('\\');
  if ((np > 0) && (np <= 7))
    {
      my_putchar('0');
      my_putchar('0');
    }
  if ((np >= 8) && (np <= 31))
    my_putchar('0');
  my_putnbr_base_u(np, "01234567", &a);
  return (3);
}

int	my_string_np(va_list *ap, int prec)
{
  char	*s;
  int	i;
  int	j;

  i = 0;
  j = 0;
  s = va_arg(*ap, char *);
  if ((s == NULL) || (s == 0))
    i = my_string_null(prec);
  else
    {
      if (prec == -1)
        prec = my_strlen(s);
      while ((s[i] != '\0') && i < prec)
	{
	  if (s[i] < 32 || s[i] >= 127)
	    j = j + my_put_octal((unsigned char)s[i]);
	  else
	    my_putchar(s[i]);
	  i = i + 1;
	}
    }
  return (i + j);
}
