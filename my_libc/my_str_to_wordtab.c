/*
** my_str_to_wordtab.c for my_str_to_wordtab in /u/all/folie_a/cu/rendu/piscine/Jour_08
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Mar 18 23:12:36 2009 adrien folie
** Last update Mon Mar 23 19:40:02 2009 adrien folie
*/

#include <stdlib.h>

char	*my_strepur(char *str, int a)
{
  int	b;
  char	*cpy;
  int	ok;
  
  b = 0;
  ok = 0;
  cpy = malloc((my_strlen(str) + 1) * sizeof(*str));
  while (str[a] != '\0')
    {
      if ((str[a] >= 'a' && str[a] <= 'z') || (str[a] >= 'A' && str[a] <= 'Z') 
	  || (str[a] >= '0' && str[a] <= '9'))
	{
	  cpy[b++] = str[a];
	  ok = 1;
	}
      else if (ok == 1)
	{
	  cpy[b++] = ' ';
	  ok = 0;
	}
      a = a + 1; 
     }
  cpy[b] = '\0'; 
  return (cpy);
}

int	my_wordsnbr(char *str)
{
  int	words;
  int	no;
  int	d;

  d = 0;
  words = 0;
  no = 0;
  while (str[d] != '\0')
    {
      if ((str[d] >= 'a' && str[d] <= 'z') || (str[d] >= 'A' && str[d] <= 'Z')
          || (str[d] >= '0' && str[d] <= '9'))
        {
          if (no == 0)
            {
              words = words + 1;
              no = 1;
            }
        }
      else
        no = 0;
      d = d + 1;
    }
  return (words);
}

char 	**alloc_mem(char *str, char **tab)
{
  int	x;
  int	w;
  
  x = 0;
  w = my_wordsnbr(str);
  tab = malloc((w + 1) * sizeof(**tab));
  while (x < w)
    {
      tab[x] = malloc((my_strlen(str) + 1) * sizeof(*tab));
      x = x + 1; 
    }
  tab[x] = 0;
  return (tab);
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  str = my_strepur(str, j);
  tab = alloc_mem(str, tab);
  while (str[i] != '\0')
    {
      k = 0;
      while (str[i] != ' ' && str[i] != '\0')
	{
	  tab[j][k] = str[i];
          k = k + 1;
	  i = i + 1;
	}
      tab[j][k] = '\0';
      j = j + 1;
      if (str[i] == ' ')
	  i = i + 1;
    }
  return (tab);
}
