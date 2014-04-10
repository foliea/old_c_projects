/*
** str_to_word_tab.c for my irc in /u/all/folie_a/public/dedern/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Apr 28 18:14:38 2010 edern bienvenu
** Last update Wed Apr 28 18:15:51 2010 edern bienvenu
*/

#include <stdlib.h>
#include <string.h>
int	my_strlen(char *str);

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
  int	j;

  taille = my_countword(str, sep);
  tab = malloc((taille + 1) * sizeof(char *));
  if (tab == NULL)
    return (NULL);
  i = 0;
  while (i < taille)
    {
      tab[i] = malloc((strlen(str) + 1) * sizeof(char));
      if (tab[i] == NULL)
	return (NULL);
      j = 0;
      while (j <= my_strlen(str))
	tab[i][j++] = '\0';
      my_strlen(tab[i]);
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
