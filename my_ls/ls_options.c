/*
** ls_options.c for ls_options in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed May 20 23:41:59 2009 adrien folie
** Last update Tue May 26 03:09:13 2009 adrien folie
*/

#include <stdlib.h>
#include "my_ls.h"

void	init_option(t_options *option)
{
  option->l = 0;
  option->a = 0;
  option->r = 0;
  option->R = 0;
  option->d = 0;
  option->t = 0;
}

void	my_check_option(char flag, t_options *option)
{
  if (flag == 'a')
    option->a = 1;
  else if (flag == 'l')
    option->l = 1;
  else if (flag == 'r')
    option->r = 1;
  else if (flag == 'R')
    option->R = 1;
  else if (flag == 'd')
    option->d = 1;
  else if (flag == 't')
    option->t = 1;
  else
    {
      my_printf("ls : illegal option --%c\n", flag);
      my_printf("usage: ls [-adlrtR] [file ...]\n");
      exit(EXIT_FAILURE);
    }
}

int    my_options(t_options *option, char **av, int ac, char **env)
{
  int	i;
  int	j;

  i = 1;
  init_option(option);
  option->home = my_getpwd(env);
  while (i < ac)
    {
      j = 1;
      if (av[i][0] == '.')
	return (i);
      while (av[i][j] != '\0')
        {
          if (av[i][0] != '-')
	    return (i);
          my_check_option(av[i][j], option);
          ++j;
        }
      if (j == 1)
	my_error_report(4);
      ++i;
    }
  return (-1);
}

int	isnot_hidden(char *file)
{
  if (file[0] == '.')
    return (1);
  return (0);
}
