/*
** my_putchar.c for my_putchar in /u/all/folie_a/cu/rendu/lib/my
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar 19 00:22:55 2009 adrien folie
** Last update Tue Apr 28 11:25:34 2009 adrien folie
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(EXIT_FAILURE);
  return (1);
}
