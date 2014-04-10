/*
** my_show_to_wordbad.c for my_show_to_wordtab in /u/all/folie_a/cu/rendu/piscine/Jour_08
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Thu Mar 19 20:58:23 2009 adrien folie
** Last update Mon May 18 00:01:33 2009 adrien folie
*/

#include "bsq.h"
#include "colors.h"

int	my_print_yellow(char c)
{
  couleur("33");
  my_printf("%c", c);
  couleur("0");
  return (FALSE);
}

int	my_print_magenta(char c)
{
  couleur("35");
  my_printf("%c", c);
  couleur("0");
  return (FALSE);
}

int	my_print_green(char c)
{
  couleur("32");
  my_printf("%c", c);
  couleur("0");
  return (FALSE);
}

int	my_put_incolor(char *tab)
{
  int	i;

  i = 0;
  while (tab[i] != '\0')
    {
      if (tab[i] == '.')
	my_print_yellow(tab[i]);
      if (tab[i] == 'o')
	my_print_magenta(tab[i]);
      if (tab[i] == 'x')
	my_print_green(tab[i]);
      if ((tab[i] >= '0') && (tab[i] <= '9'))
	my_printf("%c", tab[i]);
      ++i;
    }
  my_putchar('\n');
  return (TRUE);
}

int	my_show_in_colors(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_put_incolor(tab[i]);
      ++i;
    }
  return (TRUE);
}
