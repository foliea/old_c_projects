/*
** str_to_wordtab.c for str_to_wordtab in /u/all/folie_a/cu/42sh/lib
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Tue Nov  3 14:34:52 2009 adrien folie
** Last update Sun Nov  8 22:07:24 2009 adrien folie
*/

#include <stdlib.h>
#include "gen.h"
int	my_strlen(char *str);

void	check_egal(char *str, char sep)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == sep)
	++j;
      ++i;
    }
  if (j > 1)
    my_put_error("Multiple \"=\"\n");
}

int	my_countword(char *str, char sep)
{
  int	i;
  int	yes;
  int	nb;

  i = 0;
  yes = 1;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] != sep &&
	  yes == 1)
	{
	  ++nb;
	  yes = 0;
	}
      else if (str[i] == sep)
	yes = 1;
      ++i;
    }
  return (nb);
}

char	**my_mem_tab(char *str, char sep)
{
  char	**tab;
  int	taille;
  int	i;

  taille = my_countword(str, sep);
  tab = malloc((taille + 1) * sizeof(*tab));
  if (tab == NULL)
    return (NULL);
  i = 0;
  while (i < taille)
    {
      tab[i] = malloc((my_strlen(str) + 1) * sizeof(*tab));
      if (tab[i] == NULL)
	return (NULL);
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}

char	**str_to_wordtab(char *str, char sep)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  i = 0;
  j = 0;
  k = 0;
  check_egal(str, sep);
  if ((tab = my_mem_tab(str, sep)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (str[i] == sep)
	{
	  tab[j][k] = '\0';
	  ++j;
	  k = -1;
	}
      else
	tab[j][k] = str[i];
      ++i;
      ++k;
    }
  return (tab);
}
