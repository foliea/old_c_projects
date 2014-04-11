/*
** print_time.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Sun Jun 20 16:27:39 2010 adrien folie
** Last update Sun Jun 20 17:38:40 2010 edern bienvenu
*/

#include <stdio.h>
#include <sys/time.h>

void	aff_error(char *str);

void			print_time(void)
{
  struct timeval	now;

  if (gettimeofday(&now, NULL) == -1)
    aff_error("gettimeofday failed");
  printf("-- %i:%i --\n", (int) now.tv_sec,
	 (int) now.tv_usec);
}
