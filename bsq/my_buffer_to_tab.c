/*
** my_buffer_to_tab.c for my_buffer_to_tab.c in /u/all/folie_a/cu/rendu/c/bsq
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Thu Apr 30 08:07:15 2009 adrien folie
** Last update Fri May  8 16:55:40 2009 thibaut ottemer
*/

#include "bsq.h"

char     **my_buffer_to_tab(char **av, int i)
{
  int   fd;
  char  *first;
  char	**tab;
  int	taille;

  if ((fd = open(av[1], O_RDONLY)) == -1)
    my_error_report(1);
  first = get_next_line(fd);
  if (first == NULL)
    my_error_report(2);
  taille = my_getnbr(first);
  if (taille <= 0)
    my_error_report(3);
  tab = malloc((taille + 1) * sizeof(*tab));
  free(first);
  while (i < taille)
    {
      tab[i++] = get_next_line(fd);
      if (i != (taille - 1) && tab[i - 1] == NULL)
	my_error_report(2);
    }
  tab[i] = NULL;
  close(fd);
  tab = my_square(tab, -1, taille, 0);
  return (tab);
}

int	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
  return (TRUE);
}

int	main(int ac, char **av)
{
  char	**tab;

  if (ac < 2 || ac > 3)
    my_error_report(4);
  else
    {
      tab = my_buffer_to_tab(av, 0);
      if (ac == 3)
	{
	  if (my_strcmp(av[2], "-colors") == 0)
	    my_show_in_colors(tab);
	  else
	    my_error_report(5);
	}
      else
      my_show_tab(tab);
    }
  my_free_tab(tab);
  return (EXIT_SUCCESS);
}
