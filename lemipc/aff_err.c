/*
** aff_err.c for lemipc in /u/all/folie_a/public/dedern/lemipc
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri May 21 23:18:01 2010 edern bienvenu
** Last update Sun May 23 19:37:08 2010 edern bienvenu
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	aff_error(char *str)
{
  write(2, str, strlen(str));
  write(2, "\n", 1);
  exit(EXIT_FAILURE);
}
