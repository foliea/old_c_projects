/*
** ls_display.c for ls_display in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Thu May 21 14:40:52 2009 adrien folie
** Last update Tue May 26 05:14:08 2009 adrien folie
*/

#include <pwd.h>
#include <time.h>
#include <stdlib.h>
#include <grp.h>
#include "my_ls.h"

void	my_show_list(t_list *begin)
{
  while (begin != 0)
    {
      my_putstr(begin->name);
      my_putstr("\n");
      begin = begin->next;
    }
}

void		my_show_list_l(t_list *begin, int d)
{
  struct group	*gid;
  struct passwd	*uid;
  char		*temp;
  char		*time;

  if (d == 0)
    my_printf("total %d\n", count_blocks(begin));
  while (begin != 0)
    {
      gid = getgrgid(begin->stats.st_gid);
      uid = getpwuid(begin->stats.st_uid);
      temp = ctime(&begin->stats.st_mtime);
      time = my_strdup_select(temp, 4, 12);
      my_print_type(begin->stats.st_mode);
      my_print_chmod(begin->stats.st_mode);
      my_printf("%d\t", begin->stats.st_nlink);
      my_printf("%s\t %s\t", uid->pw_name, gid->gr_name);
      my_printf("%d\t", begin->stats.st_size);
      my_putstr(time);
      free(time);
      my_printf(" %s\n", begin->name);
      begin = begin->next;
    }
}

void	ls_display(t_list *begin, t_options option)
{
  if (option.l == 0)
    my_show_list(begin);
  else
    my_show_list_l(begin, option.d);
}
