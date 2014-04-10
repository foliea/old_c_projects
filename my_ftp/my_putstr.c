/*
** my_putstr.c for my_putstr.c in /u/all/folie_a/cu/rendu/piscine/Jour_04
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Thu Mar 12 13:18:56 2009 adrien folie
** Last update Fri Apr  9 18:34:31 2010 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	my_putstr(char *str)
{
  if (write(1, str, strlen(str)) == -1)
    exit(EXIT_FAILURE);
  return (strlen(str));
}
