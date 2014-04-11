/*
** print_time.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:10:11 2010 adrien folie
** Last update Mon Jul  5 03:10:11 2010 adrien folie
*/

#include <stdio.h>
#include <sys/time.h>
#include "utils.h"

void			print_time(void)
{
  struct timeval	now;

  if (gettimeofday(&now, NULL) == -1)
    aff_error("gettimeofday failed");
  printf("-- %i:%i --\n", (int) now.tv_sec,
	 (int) now.tv_usec);
}
