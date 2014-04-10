/*
** parser_ls.c for parser_ls in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon May 18 16:48:43 2009 adrien folie
** Last update Tue May 26 07:25:13 2009 adrien folie
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_ls.h"

t_list		*start_read(DIR *dir, t_options option)
{
  struct dirent	*d;
  struct stat	sb;
  t_list	*begin;

  begin = 0;
  while ((d = readdir(dir)) != NULL)
    {
      if (stat(d->d_name, &sb) == -1)
	my_error_report(5);
      if (option.a == 0)
	{
	  if (isnot_hidden(d->d_name) == 0)
	    {
	      if (option.t == 0)
		insert_by_name(&begin, d->d_name, sb);
	      else
		insert_by_time(&begin, d->d_name, sb);
	    }
	}
      else
	if (option.t == 0)
	  insert_by_name(&begin, d->d_name, sb);
	else
	  insert_by_time(&begin, d->d_name, sb);
    }
  return (begin);
}

void		others_directory(int ac, char **av, int pos, t_options option)
{
  t_list	*begin;
  DIR		*dir;

  while (pos++ < ac)
    {
      if ((dir = opendir(av[pos - 1])) == NULL)
        {
          my_printf("ls : %s: ", av[pos - 1]);
          my_error_report(1);
        }
      if (chdir(av[pos - 1]) == -1)
	my_error_report(6);
      if (option.yes != (ac - 1))
	my_printf("%s:\n", av[pos - 1]);
      begin = start_read(dir, option);
      if (option.r == 1 && my_list_size(begin) > 1)
	my_rev_list(&begin);
      if (my_list_size(begin) > 0)
	ls_display(begin, option);
      else
	my_error_report(8);
      my_free_list(&begin);
      closedir(dir);
      if (chdir(option.home) == -1)
	my_error_report(6);
    }
}

void		current_directory(int ac, char **av, t_options option)
{
  t_list	*begin;
  DIR		*dir;

  if ((dir = opendir(".")) == NULL)
    {
      my_printf("ls : . : ", av[ac - 1]);
      my_error_report(1);
    }
  begin = start_read(dir, option);
  if (option.r == 1 && my_list_size(begin) > 1)
    my_rev_list(&begin);
  if (my_list_size(begin) > 0)
    ls_display(begin, option);
  else
    my_error_report(8);
  my_free_list(&begin);
  closedir(dir);
}

int		main(int ac, char **av, char **env)
{
  t_options	option;
  int		pos;

  pos = my_options(&option, av, ac, env);
  option.yes = pos;
  if (option.d == 0)
    if (pos == -1)
      current_directory(ac, av, option);
    else
      others_directory(ac, av, pos, option);
  else
    option_d(ac, av, pos, option);
  free(option.home);
  return (0);
}
