/*
** my_show_to_wordbad.c for my_show_to_wordtab in /u/all/folie_a/cu/rendu/piscine/Jour_08
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Thu Mar 19 20:58:23 2009 adrien folie
** Last update Sat Sep 12 11:11:26 2009 thibaut ottemer
*/

#include <unistd.h>
#include "sudoki-bi.h"

int	my_show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
  return (TRUE);
}
