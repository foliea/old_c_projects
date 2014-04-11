/*
** my_showtab.c for my_showtab in /u/all/jacque_c/public/42sh/lib
** 
** Made by leo lopez
** Login   <lopez_l@epitech.net>
** 
** Started on  Tue Nov  3 14:44:29 2009 leo lopez
** Last update Tue Nov  3 14:50:24 2009 leo lopez
*/

#include <stdlib.h>
void	my_putchar(char c);
int	my_putstr(char *str);

void	my_showtab(char **tab)
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
