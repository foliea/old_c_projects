/*
** main.c for main in /u/all/folie_a/cu/rendu/c/my_printf
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Tue Apr 14 17:34:31 2009 adrien folie
** Last update Sat Sep 12 17:37:45 2009 adrien folie
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	main()
{
  char	str[] = "iPhone";
  int	a = 42;
  char	b = 'A';
  int	taille;
  unsigned int c = 255;
  char	*str2;

  str2 = malloc(7 * sizeof(char *));
  str2[0] = 'a';
  str2[1] = 's';
  str2[2] = 8;
  str2[3] = 't';
  str2[4] = 'e';
  str2[5] = 'k';
  str2[6] = '\0';
  taille = my_printf("a : %.6d c : %.4u str : %.3s c : %1 %%  %.6x %.5S %s %.3s %S %.2S %.9b\n%", a, c , str, c, str2, 0 , 0, str2, str2, c);
  my_printf(NULL);
  return (0);
}
