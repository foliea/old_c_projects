/*
** my_printf.c for my_printf in /u/all/folie_a/cu/rendu/c/my_printf
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Apr 13 05:14:33 2009 adrien folie
** Last update Thu May 14 21:28:07 2009 adrien folie
*/

#include "my.h"

typedef	struct	s_flags
{
  char		flag;
  int		(*f)();
}		t_flags;

static const t_flags	index[]=
{
    {'d', my_decimal},
    {'i', my_decimal},
    {'u', my_udecimal},
    {'s', my_string},
    {'S', my_string_np},
    {'c', my_character},
    {'b', my_binaire},
    {'o', my_octal},
    {'p', my_pointer},
    {'x', my_hex_min},
    {'%', my_put_purcent},
    {'X', my_hex_maj},
    {0, NULL}
};

int	my_flags(char flg, va_list *ap, int prec)
{
  int	i;
  int	taille;
  int	check;

  i = 0;
  check = 0;
  taille = 0;
  while (index[i].flag != 0)
    {
      if (flg == index[i].flag)
	{
	  taille = index[i].f(ap, prec);
	  check = 1;
	}
      i = i + 1;
    }
  if (check == 0)
    {
      my_putchar(flg);
      return (1);
    }
  return (taille);
}

int	my_precision(char *str, int i, int *prec)
{
  *prec = 0;
  if (str[i] >= '0' && str[i] <= '9')
    {
      while (str[i] >= '0' && str[i] <= '9')
	{
	  *prec = ((*prec) * 10 + str[i] - '0');
	  ++i;
	}
    }
  else
    *prec = 0;
  return (i);
}

int	my_parseur(char *str, va_list *ap)
{
  int	i;
  int	taille;
  int	prec;

  prec = 0;
  i = 0;
  taille = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '%')
        {
          if (str[i + 1] == '\0')
            return (taille);
          if (str[++i] == '.')
            i = my_precision(str, ++i, &prec);
          else
            prec = -1;
          taille += my_flags(str[i], ap, prec);
        }
      else
        taille += my_putchar(str[i]);
      ++i;
    }
  return (taille);
}

int		my_printf(char *str, ...)
{
  va_list	ap;
  int		taille;

  if ((str == NULL) || (str == 0))
    taille = my_string_null(6);
  else
    {
      va_start(ap, str);
      taille = my_parseur(str, &ap);
    }
  return (taille);
}
