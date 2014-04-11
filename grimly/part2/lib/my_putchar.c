/*
** my_putchar.c for my_putchar in /u/all/jacque_c/public/42sh/lib
** 
** Made by leo lopez
** Login   <lopez_l@epitech.net>
** 
** Started on  Tue Nov  3 14:24:31 2009 leo lopez
** Last update Tue Nov  3 14:24:57 2009 leo lopez
*/

#include <unistd.h>

int     my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (1);
  return (0);
}
