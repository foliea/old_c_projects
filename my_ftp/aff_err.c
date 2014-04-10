/*
** aff_err.c for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Apr  9 17:35:17 2010 adrien folie
** Last update Sun Apr 18 03:24:10 2010 adrien folie
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
