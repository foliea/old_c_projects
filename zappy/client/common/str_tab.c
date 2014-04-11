/*
** str_tab.c for  in /u/all/gouesl_a/cu/rendu/my_ftp/common
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Apr 18 20:43:58 2010 antoine goueslard
** Last update Sun Jun 13 04:53:10 2010 antoine goueslard
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**mal_tab(int i)
{
  char **tab;
  
  if ((tab = calloc(i, sizeof(*tab))) == 0)
    exit(EXIT_FAILURE);
  return (tab);
}

char	*string_get(char *src, int *i)
{
  char	*str;
  int	j;
  
  j = 0;
  if ((str = calloc(strlen(&src[*i]) + 1, sizeof(*str))) == 0)
    exit(EXIT_FAILURE);
  while (src[*i] && src[*i] != '\n' && src[*i] != ' ')
    {
      str[j++] = src[(*i)++];
    }
  return (str);
}

char	**str_to_tab(char *str)
{
  char	**tab;
  int   i;
  int   j;
  
  i = 0;
  j = 0;
  tab = mal_tab(strlen(str) + 1);
  while (str[i])
    {
      tab[j++] = string_get(str, &i);
      while (str[i] && (str[i] == '\n' || str[i] == ' '))
	i++;
    }
  return (tab);
}

