/*
** stat.c for stat.c in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Thu May 21 13:42:59 2009 adrien folie
** Last update Thu May 21 13:55:02 2009 adrien folie
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
  struct stat	sb;

  stat(av[1], &sb);
  printf("%d\n", sb.st_uid);
  return (0);
}
