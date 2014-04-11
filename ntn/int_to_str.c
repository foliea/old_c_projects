/*
** int_to_str.c for int_to_str in /u/all/folie_a/cu/rendu/c/proj/ntn
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri May 22 22:26:16 2009 adrien folie
** Last update Sat May 23 10:43:23 2009 thibaut ottemer
*/

#include "ntn.h"

int	my_nblen(unsigned int nb)
{
  int	i;

  i = 1;
  while ((nb = nb / 10) > 0)
    ++i;
  return (i);
}

char		*int_to_str(int nombre)
{
  unsigned int	nb;
  int		size;
  int		last;
  char		*str;

  if (nombre < 0)
    {
      nb = -nombre;
      my_putstr("moins ");
    }
  else
    nb = nombre;
  size = my_nblen(nb);
  str = xmalloc(size);
  str[size] = '\0';
  while (size-- > 0)
    {
      last = nb % 10;
      str[size] = last + '0';
      nb = nb / 10;
    }
  return (str);
}
