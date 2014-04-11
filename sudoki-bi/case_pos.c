/*
** case_pos.c for case_pos in /u/all/folie_a/cu/public/sudoki
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Sep 13 16:33:29 2009 adrien folie
** Last update Sun Sep 13 17:25:54 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include "sudoki-bi.h"

void	init_case(t_pos *line)
{
  int	i;

  i = 0;
  while (i < 9)
    {
      line[i].str = my_strdup("123456789\0");
      ++i;
    }
}

t_pos	**pos_init(void)
{
  int	i;
  t_pos	**pos;

  i = 0;
  pos = malloc(9 * sizeof(t_pos *));
  while (i < 9)
    {
      pos[i] = malloc(9 * sizeof(t_pos *));
      init_case(pos[i]);
      ++i;
    }
  return (pos);
}

void     loop_check_nb(char **tab, t_pos **pos, int x, int y)
{
  char  nb;

  nb = '1';
  while (nb <= '9')
    {
      if (do_checks(tab, x, y, nb) == -1)
	pos[y - 1][(x / 2) - 1].str[nb - '0' - 1] = '0';
      nb++;
    }
}

void	loop_check(char **tab, t_pos **pos)
{
  int	x;
  int	y;

  y = 1;
  while (y <= 9)
    {
      x = 2;
      while (x <= 18)
	{
	  loop_check_nb(tab, pos, x, y);
	  x += 2;
	}
      y++;
    }
}
