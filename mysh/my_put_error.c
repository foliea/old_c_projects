/*
** my_put_error.c for my_put_error in /u/all/folie_a/cu/rendu/c/corewar/vm
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri Aug 14 17:12:26 2009 adrien folie
** Last update Thu Oct  1 17:59:01 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
int	my_strlen(char *str);

int	my_put_error(char *str)
{
  if (write(2, str, my_strlen(str)) == -1)
    exit(EXIT_FAILURE);
  return (my_strlen(str));
}

