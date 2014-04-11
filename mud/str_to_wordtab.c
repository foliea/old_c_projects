/*
** str_to_wordtab.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 01:32:57 2010 adrien folie
** Last update Mon Jul  5 01:33:05 2010 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "utils.h"

int	my_wordsnbr(char *str, char separator)
{
  int	words;
  int	no;
  int	d;

  d = 0;
  words = 0;
  no = 0;
  while (str[d] != '\0')
    {
      if (str[d] != separator)
        {
          if (no == 0)
            {
              words = words + 1;
              no = 1;
            }
        }
      else
        no = 0;
      ++d;
    }
  return (words);
}

char 	**alloc_mem(char *str, char separator)
{
  char	**tab;
  int	x;
  int	w;

  x = 0;
  w = my_wordsnbr(str, separator);
  tab = xmalloc((w + 1) * sizeof(char *));
  while (x < w)
    {
      tab[x] = xmalloc((strlen(str) + 1) * sizeof(char));
      ++x;
    }
  tab[x] = NULL;
  return (tab);
}

char	**str_to_wordtab(char *str, char separator)
{
  char	**tab;
  int	i;
  int	k;
  int	j;

  j = 0;
  i = 0;
  tab = alloc_mem(str, separator);
  while (str[i] != '\0')
    {
      k = 0;
      if (str[i] == separator)
	++i;
      while (str[i] != separator && str[i] != '\0')
	{
	  tab[j][k] = str[i];
          k = k + 1;
	  i = i + 1;
	}
      tab[j][k] = '\0';
      ++j;
    }
  return (tab);
}
