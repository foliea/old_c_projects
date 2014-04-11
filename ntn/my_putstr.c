/*
** my_putstr.c for my_putstr.c in /u/all/folie_a/cu/rendu/piscine/Jour_04
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Thu Mar 12 13:18:56 2009 adrien folie
** Last update Wed May 20 22:13:38 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char *str);

int	my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    exit(EXIT_FAILURE);
  return (my_strlen(str));
}
