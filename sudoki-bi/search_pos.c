/*
** search_pos.c for search_pos in /u/all/folie_a/cu/public/sudoki
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Sep 13 17:27:40 2009 adrien folie
** Last update Sun Sep 13 18:32:44 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include "sudoki-bi.h"

int	is_alone(char *str)
{
  int	i;
  int	j;
  char	temp;

  i = 0;
  j = 0;
  temp = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '0')
	{
	  ++j;
	  temp = str[i];
	}
      if (j > 1)
	return (0);
      ++i;
    }
  return (temp);
}

int	loop_search(char **tab, t_pos **pos)
{
  int	x;
  int	y;
  int	ok;
  char	nb;

  y = 1;
  ok = 0;
  while (y <= 9)
    {
      x = 2;
      while (x <= 18)
        {
	  if ((nb = is_alone(pos[y - 1][(x / 2) - 1].str)) != 0)
	    {
	      tab[y][x] = nb;
	      ok = 1;
	    }
          x += 2;
        }
      y++;
    }
  loop_check(tab, pos);
  return (ok);
}

int	loop_human(char **tab, t_pos **pos)
{
  while (loop_search(tab, pos) == 1);
  return (0);
}
