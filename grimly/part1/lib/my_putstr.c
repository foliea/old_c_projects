/*
** my_putstr.c for my_putstr in /u/all/jacque_c/public/42sh/lib
** 
** Made by leo lopez
** Login   <lopez_l@epitech.net>
** 
** Started on  Tue Nov  3 14:25:09 2009 leo lopez
** Last update Tue Nov  3 14:26:12 2009 leo lopez
*/

#include <unistd.h>
int	my_strlen(char *str);

int     my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    return (1);
  return (0);
}
