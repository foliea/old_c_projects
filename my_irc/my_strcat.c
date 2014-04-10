/*
** my_strcat.c for my strcat in /u/all/bienve_e/cu/rendu/piscine/Jour_07
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Thu Mar 19 08:53:55 2009 edern bienvenu
** Last update Wed Apr 28 19:24:58 2010 edern bienvenu
*/

#include <stdlib.h>

int	my_strlen(char *str);
void	*xmalloc(int size);

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*res;

  i = 0;
  j = 0;
  res = xmalloc((my_strlen(str1) + my_strlen(str2) + 1));
  while (str1[i] != '\0')
    {
      res[j] = str1[i];
      i++;
      j++;
    }
  i = 0;
  while (str2[i] != '\0')
    {
      res[j] = str2[i];
      i++;
      j++;
    }
  res[j] = '\0';
  return (res);
}
