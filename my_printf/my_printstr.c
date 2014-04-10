/*
** my_printstr.c for my_printstr.c in /u/all/folie_a/cu/rendu/piscine/Jour_04
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar 12 13:18:56 2009 adrien folie
** Last update Tue Apr 28 14:19:17 2009 adrien folie
*/

#include "my.h"

int	my_string_null(int prec)
{
  if (prec == -1 || prec > 6)
    prec = 6;
  if (write(1, "(null)", prec) == -1)
    exit(EXIT_FAILURE);
  return (prec);
}

int	my_printstr(char *str, int prec)
{
  int	i;

  i = prec;
  if ((str == NULL) || (str == 0))
    i = my_string_null(prec);
  else
    {
      if (prec == -1)
	prec = my_strlen(str);
      if (prec < my_strlen(str))
	{
	  if (write(1, str, prec) == -1)
	    exit(EXIT_FAILURE);
	}
      else
	i = my_putstr(str);
    }
  return (i);
}
