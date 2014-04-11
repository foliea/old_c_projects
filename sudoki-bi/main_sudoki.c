/*
** main_sudoki.c for main_sudoki in /u/all/folie_a/cu/test/sudoki
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri Sep 11 22:04:00 2009 adrien folie
** Last update Sun Sep 13 20:27:53 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include "sudoki-bi.h"

char     **recup_grille(int *ok)
{
  char	**tab;
  char	*line;
  int	i;

  i = 0;
  tab = malloc((11 + 1) * sizeof(*tab));
  if (tab == NULL)
    my_put_error("Can't perform malloc\n");
  while (i < 11)
    {
      line = get_next_line(0);
      if (line == NULL)
	*ok = -1;
      else
	{
	  tab[i] = my_strdup(line);
	  free(line);
	}
      ++i;
    }
  tab[i] = NULL;
  return (tab);
}

int	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
  return (TRUE);
}

int	my_sudoki(void)
{
  char	**tab;
  t_pos **pos;
  int	ok;

  ok = 0;
  while (ok == 0)
    {

      tab = recup_grille(&ok);
      pos = pos_init();
      if (ok == 0)
	{
	  loop_check(tab, pos);
	  loop_human(tab, pos);
	  loop_main(tab, 2, 1);
	  puts("####################");
	}
    }
  return (0);
}

int		main(void)
{
  my_sudoki();
  return (0);
}
