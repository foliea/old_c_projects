/*
** my_put_error.c for my_put_error in /u/all/folie_a/cu/rendu/c/corewar/vm
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri Aug 14 17:12:26 2009 adrien folie
** Last update Sat Sep 12 11:11:05 2009 thibaut ottemer
*/

#include <stdlib.h>
#include <unistd.h>
#include "sudoki-bi.h"

void	my_put_error(char *str)
{
  if (write(2, str, my_strlen(str)) == -1)
    exit(EXIT_FAILURE);
  exit(EXIT_FAILURE);
}

