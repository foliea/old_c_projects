/*
** my_strcmp.c for my_strcmp in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Mar 16 20:43:45 2009 adrien folie
** Last update Fri May  8 16:39:51 2009 thibaut ottemer
*/

#include "bsq.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	diff;

  i = 0;
  diff = 0;
  while ((s1[i] == s2[i]) &&
	 ((s1[i] != '\0') || (s2[i] != '\0')))
    i++;
  if (s1[i] == s2[i])
    return (TRUE);
  diff = s1[i] - s2[i];
  return (diff);
}
