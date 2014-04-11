/*
** my_putnbr.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Jun 18 02:06:48 2010 adrien folie
** Last update Sun Jun 20 17:54:37 2010 edern bienvenu
*/

#include <unistd.h>
#include <stdlib.h>
#include "fd_puts.h"

void	fd_putnbr(int fd, int nb)
{
  char	*final;

  final = inttostr(nb);
  fd_puts(fd, final);
  free(final);
  return ;
}
