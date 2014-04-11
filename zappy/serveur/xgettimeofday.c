/*
** xgettimeofday.c for zappy in /u/all/bienve_e/public/zappy/3_gary
** 
** Made by gary allouch
** Login   <allouc_g@epitech.net>
** 
** Started on  Sun Jun 20 14:56:43 2010 gary allouch
** Last update Sun Jun 20 17:21:34 2010 edern bienvenu
*/

#include <sys/time.h>

void	aff_error(char *str);

int	xgettimeofday(struct timeval *tp, struct timezone *tzp)
{
  if (gettimeofday(tp, tzp) < 0)
    aff_error("Error : gettimeofday");
  return (0);
  
}
