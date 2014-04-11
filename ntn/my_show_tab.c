/*
** my_show_tab.c for my_show_tab.c in /u/all/folie_a/cu/rendu/c/proj/ntn
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sat May 23 00:10:56 2009 adrien folie
** Last update Sat May 23 10:41:28 2009 thibaut ottemer
*/

#include "ntn.h"

void	my_show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      ++i;
    }
}
