/*
** serveur_ls.c for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr 13 15:21:34 2010 adrien folie
** Last update Sun Apr 18 03:14:05 2010 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "serveur.h"

void	send_ls(int cs, struct dirent **tab, int i)
{
  char	buff[8];
  int	nb_read;
  int	j;

  j = 0;
  while (j < i)
    {
      if (strcmp(tab[j]->d_name, ".") != 0
	  && strcmp(tab[j]->d_name, "..") != 0)
        {
          puts(tab[j]->d_name);
          while ((nb_read = xread(cs, buff, 8)) != 8);
          if (j + 1 != i)
            {
              my_putstr("0");
              while ((nb_read = xread(cs, buff, 8)) != 8);
            }
        }
      ++j;
    }
}

void		serveur_ls(__attribute__((unused)) char **cmd, int cs)
{
  struct dirent	**tab;
  int		i;
  char		buff[8];
  int		nb_read;

  i = scandir(".", &tab, 0, alphasort);
  if (i == -1)
    {
      my_putstr("ERROR : can't ls");
      while ((nb_read = xread(cs, buff, 8)) != 8);
      my_putstr("1");
      while ((nb_read = xread(cs, buff, 8)) != 8);
    }
  if (i == 2)
    puts("Total : 0");
  send_ls(cs, tab, i);
  my_putstr("1");
  while ((nb_read = xread(cs, buff, 8)) != 8);
}
