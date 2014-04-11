/*
** ntn_main.c for ntn_main in /u/all/folie_a/cu/rendu/c/proj/ntn
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun May 24 15:35:27 2009 adrien folie
** Last update Sun May 24 23:23:12 2009 adrien folie
*/

#include <stdlib.h>
#include "ntn.h"

int	main(int ac, char **av)
{
  char	*res;
  int	pos;

  if (ac == 2)
    {
      if (av[1] != NULL)
        {
          res = int_to_str(calc(av[1]));
	  pos = my_strlen(res);
	  if (pos == 1 && res[0] == '0')
	    {
	      my_putstr("STRING NULL\n");
	      exit(EXIT_FAILURE);
	    }
	  check_zero(pos, res, 0);
          ntn_display(res, 0, pos);
          free(res);
        }
    }
  my_putchar('\n');
  return (0);
}
