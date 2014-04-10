/*
** aff_err.c for epikong in /u/epitech_2013/bienve_e/cu/rush
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri Mar 26 20:57:12 2010 edern bienvenu
** Last update Mon Apr 26 14:18:15 2010 edern bienvenu
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	aff_err(char *str)
{
  write(2, str, strlen(str));
  write(2, "\n", 1);
  exit(EXIT_FAILURE);
}
