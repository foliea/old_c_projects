/*
** my_error_report.c for my_error_report in /u/all/folie_a/cu/rendu/c/bsq
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed May  6 16:15:41 2009 adrien folie
** Last update Mon Oct  5 01:50:05 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

typedef struct	s_errors
{
    int		nb;
    char	*report;
}		t_errors;

static const t_errors	index[]=
{
  {1, "Arguments Inalids\n"},
  {2, " not found, environment is corrupted\n"},
  {3, "\n"},
  {4, "Open Failed\n"},
  {5, "Function fork failed\n"},
  {6, "Function chdir failed\n"},
  {7, "Function malloc Failed\n"},
  {0, NULL}
};

void	my_error_report(int error)
{
  int	i;

  i = 0;
  while (index[i].nb != 0)
    {
      if (error == index[i].nb)
	if ((write(2, index[i].report, my_strlen(index[i].report))) == -1)
	  exit(EXIT_FAILURE);
      ++i;
    }
  exit(EXIT_FAILURE);
}
