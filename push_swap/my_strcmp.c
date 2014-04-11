/*
** my_strcmp.c for my_strcmp() in /u/all/otteme_t/cu/rendu/piscine/Jour_06
** 
** Made by thibaut ottemer
** Login   <otteme_t@epitech.net>
** 
** Started on  Mon Mar 16 18:27:51 2009 thibaut ottemer
** Last update Fri Jul  3 11:02:08 2009 thibaut ottemer
*/

#include <stdlib.h>
#include "push.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) > my_strlen(s2))
    return (1);
  else if (my_strlen(s1) < my_strlen(s2))
    return (2);
  else
    while ((s1[i] != '\0') && (s2[i] != '\0'))
      {
	if (s1[i] == s2[i])
	  i++;
	else
	  return (s1[i] - s2[i]);
      }
  return (0);
}
