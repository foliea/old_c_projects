/*
** tab_utils.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:10:45 2010 adrien folie
** Last update Mon Jul  5 03:10:45 2010 adrien folie
*/

#include <stdlib.h>
#include <stdio.h>

int	tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}

void	show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      puts(tab[i]);
      ++i;
    }
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
}
