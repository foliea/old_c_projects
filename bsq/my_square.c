/*
** my_square.c for BSQ in /u/all/otteme_t/cu/rendu/c/bsq
**
** Made by thibaut ottemer
** Login   <otteme_t@epitech.net>
**
** Started on  Wed Apr 22 15:18:13 2009 thibaut ottemer
** Last update Fri May  8 17:12:20 2009 thibaut ottemer
*/

#include "bsq.h"

void	check_error_file(char **tab, int i)
{
  int	j;
  int	j_save;

  j_save = my_strlen(tab[0]);
  while (tab[++i])
    {
      j = -1;
      while (tab[i][++j])
        if (tab[i][j] != 'o' && tab[i][j] != '.')
	  my_error_report(6);
      if (j != j_save)
	my_error_report(7);
    }
}

char	**my_transform(char **tab, int pos1, int pos2, int size)
{
  int	i;
  int	j;

  i = -1;
  while (++i != size)
    {
      j = -1;
      while (++j != size)
	tab[pos1 + i][pos2 + j] = 'x';
    }
  return (tab);
}

int	check_square(char **tab, int pos1, int pos2, int size)
{
  int	i;
  int	j;

  i = -1;
  while (tab[pos1 + ++i] && i <= size)
    {
      j = -1;
      while (tab[pos1 + i][pos2 + ++j] && j <= size)
	if (tab[pos1 + i][pos2 + j] == 'o')
	  return (FALSE);
      if (j - 1 < size)
	return (FALSE);
    }
  if (i > size)
    return (TRUE);
  return (FALSE);
}

char	**my_square(char **tab, int i, int nb_line, int size)
{
  int	j;
  int	length_col;
  int	pos1;
  int	pos2;

  check_error_file(tab, -1);
  length_col = my_strlen(tab[1]);
  while (tab[++i] && (i + size <= nb_line))
    {
      j = -1;
      while (tab[i][++j] != '\0' && (size + j <= length_col))
	while (check_square(tab, i, j, size) == TRUE)
	  {
	    pos1 = i;
	    pos2 = j;
	    size++;
	  }
    }
  return (my_transform(tab, pos1, pos2, size));
}
