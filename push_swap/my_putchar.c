/*
** my_putchar.c for my_putchar in /u/all/folie_a/cu/rendu/lib/my
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar 19 00:22:55 2009 adrien folie
** Last update Thu Mar 19 00:36:37 2009 adrien folie
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
