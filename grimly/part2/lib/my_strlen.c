/*
** my_strlen.c for my_strlen in /u/all/jacque_c/public/42sh/lib
** 
** Made by leo lopez
** Login   <lopez_l@epitech.net>
** 
** Started on  Tue Nov  3 14:23:44 2009 leo lopez
** Last update Tue Nov  3 14:24:16 2009 leo lopez
*/

#include <stdlib.h>

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    ++i;
  return (i);
}
