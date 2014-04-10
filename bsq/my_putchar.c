/*
** my_putchar.c for my_putchar in /u/all/folie_a/cu/rendu/lib/my
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar 19 00:22:55 2009 adrien folie
** Last update Fri May  8 16:36:11 2009 thibaut ottemer
*/

#include "bsq.h"

void	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    exit(EXIT_FAILURE);
}
