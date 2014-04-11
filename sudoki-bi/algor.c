/*
** algor.c for check_case in /u/all/folie_a/cu/public/sudoki
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sat Sep 12 14:27:05 2009 adrien folie
** Last update Sun Sep 13 20:30:27 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "sudoki-bi.h"

int	check_line(char **tab, int y, char nb)
{
  int	i;

  i = 2;
  while (i <= 18)
    {
      if (tab[y][i] == nb)
	return (-1);
      i += 2;
    }
  return (0);
}

int	check_col(char **tab, int x, char nb)
{
  int	i;

  i = 1;
  while (i <= 9)
    {
      if (tab[i][x] == nb)
	return (-1);
      ++i;
    }
  return (0);
}

int	check_carre(char **tab, int x, int y, char nb)
{
  int	i;
  int	j;
  int	temp;

  if (y == 2 || y == 5 || y == 8)
    y--;
  else if (y == 3 || y == 6 || y == 9)
    y -= 2;
  if (x == 4 || x == 10 || x == 16)
    x -= 2;
  else if (x == 6 || x == 12 || x == 18)
    x -= 4;
  i = 0;
  temp = x;
  while (i < 3)
    {
      j = 0;
      x = temp;
      while (j < 3)
	{
	  if (tab[y][x] == nb)
	    return (-1);
	  x += 2;
	  j++;
	}
      y++;
      i++;
    }
  return (0);
}

int	do_checks(char **tab, int x, int y, char nb)
{
  if (tab[y][x] == ' ')
    if (check_line(tab, y, nb) == 0)
	if (check_col(tab, x, nb) == 0)
	  if (check_carre(tab, x, y, nb) == 0)
	    return (0);
  return (-1);
}

int	do_check(char **tab, int x, int y, char nb)
{
  if (tab[y][x] == nb)
    return (0);
  if (tab[y][x] == ' ')
    if (check_line(tab, y, nb) == 0)
      if (check_col(tab, x, nb) == 0)
	if (check_carre(tab, x, y, nb) == 0)
	  return (0);
  return (-1);
}

int	loop_main(char **tab, int x, int y)
{
  char	nb;
  char	temp;

  nb = '1';
  if (y == 10)
      my_show_tab(tab);
  else
    while (nb <= '9')
      {
	if (do_check(tab, x, y, nb) == 0)
	{
	  temp = tab[y][x];
	  tab[y][x] = nb;
	  if (x == 18)
	    loop_main(tab, 2, y + 1);
	  else
	    loop_main(tab, x + 2, y);
	  if (y == 10)
	    return (0);
	  tab[y][x] = temp;
	}
	++nb;
      }
  return (0);
}
