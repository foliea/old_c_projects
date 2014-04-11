/*
** my_str_to_wordtab.c for my_str_to_wordtab in /u/all/folie_a/cu/rendu/piscine/Jour_08
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Mar 18 23:12:36 2009 adrien folie
** Last update Mon Oct  5 01:55:49 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

char	*my_strepur(char *str, int a)
{
  int	b;
  char	*cpy;
  int	ok;

  b = 0;
  ok = 0;
  cpy = xmalloc(my_strlen(str));
  while (str[a] != '\0')
    {
      if (str[a] != ' ' && str[a] != '\t')
	{
	  cpy[b++] = str[a];
	  ok = 1;
	}
      else if (ok == 1)
	{
	  cpy[b++] = ' ';
	  ok = 0;
	}
      ++a;
     }
  cpy[b] = '\0';
  if (cpy[my_strlen(cpy) -1] == ' ' || cpy[my_strlen(cpy) -1] == '\t')
    cpy[my_strlen(cpy) -1] = '\0';
  return (cpy);
}

char	*my_strepur2(char *str, int a, int separator)
{
  int	b;
  char	*cpy;
  int	ok;

  b = 0;
  ok = 0;
  cpy = xmalloc(my_strlen(str));
  while (str[a] != '\0')
    {
      if (ok == 0 && (str[a] == ' ' || str[a] == '\t'))
	++a;
      if (str[a] != separator)
        {
          cpy[b++] = str[a];
	  ok = 1;
        }
      else if (ok == 1)
        {

          cpy[b++] = separator;
          ok = 0;
        }
      ++a;
    }
  cpy[b] = '\0';
  if (cpy[my_strlen(cpy) -1] == separator)
    cpy[my_strlen(cpy) -1] = '\0';
  return (cpy);
}

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

char 	**alloc_mem(char *str, char **tab, char separator)
{
  int	x;
  int	w;

  x = 0;
  w = my_wordsnbr(str, separator);
  tab = malloc((w + 1) * sizeof(*tab));
  if (tab == NULL)
    my_error_report(7);
  while (x < w)
    {
      tab[x] = xmalloc(my_strlen(str));
      ++x;
    }
  tab[x] = NULL;
  return (tab);
}

char	**my_str_to_wordtab(char *str, char separator, int opt)
{
  char	**tab;
  char	*temp;
  int	i;
  int	k;
  int	j;

  j = 0;
  i = 0;
  temp = do_epur(str, separator, opt);
  tab = alloc_mem(temp, tab, separator);
  while (temp[i] != '\0')
    {
      k = 0;
      if (temp[i] == separator)
	++i;
      while (temp[i] != separator && temp[i] != '\0')
	{
	  tab[j][k] = temp[i];
          k = k + 1;
	  i = i + 1;
	}
      tab[j][k] = '\0';
      ++j;
    }
  free(temp);
  return (tab);
}
