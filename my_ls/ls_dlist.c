/*
** ls_dlist.c for ls_dlist.c in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Tue May 26 05:48:23 2009 adrien folie
** Last update Tue May 26 07:12:55 2009 adrien folie
*/

#include "my_ls.h"

t_list		*option_dlist(int ac, char **av, int pos, t_options option)
{
  t_list	*begin;
  struct stat	sb;

  begin = 0;
  if (pos == -1)
    {
      if ((stat(".", &sb)) == -1)
        my_error_report(5);
      if (option.t == 0)
        insert_by_name(&begin, ".", sb);
      else
        insert_by_time(&begin, ".", sb);
    }
  else
    while (pos < ac)
      {
        if ((stat(av[pos], &sb)) == -1)
	  my_error_report(5);
        if (option.t == 0)
          insert_by_name(&begin, av[pos], sb);
        else
          insert_by_time(&begin, av[pos], sb);
	++pos;
      }
  return (begin);
}

void		option_d(int ac, char **av, int pos, t_options option)
{
  t_list	*begin;

  begin = option_dlist(ac, av, pos, option);
  if (option.r == 1 && my_list_size(begin) > 1)
    my_rev_list(&begin);
  ls_display(begin, option);
  my_free_list(&begin);
}
