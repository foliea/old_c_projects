/*
** my_error_report.c for my_error_report in /u/all/folie_a/cu/rendu/c/bsq
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed May  6 16:15:41 2009 adrien folie
** Last update Tue May 26 07:17:48 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_ls.h"

typedef struct	s_errors
{
    int		nb;
    char	*report;
}		t_errors;

static const t_errors	index[]=
{
  {1, "No such file or directory\n"},
  {2, "\n"},
  {3, "ls : illegal arguments\n"},
  {4, "ls: -: No such file or directory\n"},
  {5, "Function stat failed\n"},
  {6, "Function chdir failed\n"},
  {7, "Malloc Failed\n"},
  {8, "total 0\n"},
  {0, NULL}
};

void	my_error_report(int error)
{
  int	i;

  i = 0;
  while (index[i].nb != 0)
    {
      if (error == index[i].nb)
	if((write(2, index[i].report, my_strlen(index[i].report))) == -1)
	  exit(EXIT_FAILURE);
      ++i;
    }
  exit(EXIT_FAILURE);
}
