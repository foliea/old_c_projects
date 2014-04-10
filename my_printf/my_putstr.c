/*
** my_putstr.c for my_putstr.c in /u/all/folie_a/cu/rendu/piscine/Jour_04
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar 12 13:18:56 2009 adrien folie
** Last update Tue Apr 28 11:26:15 2009 adrien folie
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
int	my_strlen(char *str);

int	my_putstr(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 6;
  if ((str == NULL) || (str == 0))
    {
      if (write(1, "(null)", 6) == -1)
	exit(EXIT_FAILURE);
      return (nb);
    }
  else
    if (write(1, str, my_strlen(str)) == -1)
      exit(EXIT_FAILURE);
  return (my_strlen(str));
}
