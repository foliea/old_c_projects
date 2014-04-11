/*
** str_to_wordtab.c for ZAPPY in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri Jun 18 02:22:56 2010 edern bienvenu
** Last update Fri Jun 18 02:23:02 2010 edern bienvenu
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

char	**cpy_str_to_tab(char *str, char **tab, int j, int *i, char sep)
{
  int	k;

  k = 0;
  while (str[*i] != '\0' && (str[*i] == sep || str[*i] == '\t'))
    (*i)++;
  while (str[*i] != '\0' && (str[*i] != sep && str[*i] != '\t'))
    {
      tab[j][k] = str[*i];
      *i = *i + 1;
      k = k + 1;
    }
  if (str[*i] != '\0')
    tab[j][k] = '\0';
  return (tab);
}

int	count_word(char *str, char sep)
{
  int	nb_wrd;
  int	i;

  i = 0;
  nb_wrd = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && (str[i] == sep || str[i] == '\t'))
	i++;
      while (str[i] && (str[i] != sep && str[i] != '\t'))
	i++;
      if (str[i - 1] && (str[i - 1] != sep && str[i - 1] != '\t'))
	nb_wrd++;
    }
  return (nb_wrd);
}

char	**str_to_tab_sep(char *str, char sep)
{
  int	i;
  int	j;
  char	**tab;
  int	nb_wrd;
  
  if (str == NULL || (nb_wrd = count_word(str, sep)) == 0)
    return (NULL);
  tab = xmalloc((nb_wrd + 1) * sizeof(*tab));
  i = 0;
  while (i < nb_wrd)
    {
      tab[i] = xmalloc((strlen(str) + 1) * sizeof(**tab));
      memset(tab[i++], 0, strlen(str));
    }
  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      tab = cpy_str_to_tab(str, tab, j, &i, sep);
      j = j + 1;
    }
  tab[j] = NULL;
  return (tab);
}
