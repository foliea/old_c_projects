/*
** my_putstr.c for my_putstr.c in /u/all/folie_a/cu/rendu/piscine/Jour_04
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar 12 13:18:56 2009 adrien folie
** Last update Mon Mar 23 17:20:27 2009 adrien folie
*/

#include "my_libc.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}


