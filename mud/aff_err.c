/*
** aff_err.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:06:09 2010 adrien folie
** Last update Mon Jul  5 03:06:10 2010 adrien folie
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
