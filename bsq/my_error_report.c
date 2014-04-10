/*
** my_error_report.c for my_error_report in /u/all/folie_a/cu/rendu/c/bsq
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed May  6 16:15:41 2009 adrien folie
** Last update Thu May  7 18:51:45 2009 adrien folie
*/

#include "bsq.h"

typedef struct	s_errors
{
    int		nb;
    char	*report;
}		t_errors;

static const t_errors	index[]=
{
  {1, "Open Failed\n"},
  {2, "File Incorrect\n"},
  {3, "Map Header Incorrect\n"},
  {4, "Invalid Arguments\n"},
  {5, "Invalid Option\n"},
  {6, "Error Line\n"},
  {7, "Error Character\n"},
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
