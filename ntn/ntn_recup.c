/*
** ntn_recup.c for ntn_recup in /u/all/folie_a/cu/rendu/c/proj/ntn
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri May 22 23:03:01 2009 adrien folie
** Last update Sun May 24 20:15:27 2009 adrien folie
*/

#include "ntn.h"

int	count_nbr(char *str)
{
  int	yes;
  int	i;
  int	nb;

  yes = 1;
  i = 0;
  nb = 0;
  check_num(str, 0);
  while (str[i] != '\0')
    {
      if ((str[i] >= '0' && str[i] <= '9') && yes == 1)
	{
	  yes = 0;
	  ++nb;
	}
      if (str[i++] == '-')
	{
	  yes = 1;
	  if (str[i] == '-')
	    my_error();
	}
    }
  return (nb);
}

char	**infos_memory(char *str)
{
  char	**tab;
  int	i;
  int	taille;

  i = 0;
  taille = count_nbr(str) + 1;
  tab = malloc(taille * sizeof(*tab));
  if (tab == NULL)
    exit(EXIT_FAILURE);
  while (i < (taille - 1))
    {
      tab[i] = xmalloc(my_strlen(str));
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}

char	**recup_infos(char *str)
{
  char	**res;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  res = infos_memory(str);
  while (str[i] != '\0')
    {
      res[j][k] = str[i];
      if (str[i] == '-' && i != 0)
	{
	  res[j][k] = '\0';
	  ++j;
	  k = 0;
	  res[j][k] = '-';
	}
      ++k;
      ++i;
    }
  return (res);
}

int	calc(char *str)
{
  char	**res;
  int	result;
  int	i;

  i = 0;
  res = recup_infos(str);
  result = 0;
  while (res[i] != NULL)
    {
      result += my_getnbr(res[i]);
      free(res[i]);
      ++i;
    }
  free(res);
  return (result);
}
