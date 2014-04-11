/*
** check_bin_list.c for check_bin_list in /u/all/folie_a/cu/rendu/c/minishell2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sat Oct  3 23:19:19 2009 adrien folie
** Last update Mon Oct  5 01:14:02 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
char	*my_str_link(char *s1, char *s2);

void	bin_error(char *temp, int ok)
{
  my_putstr(temp);
  if (ok == 3)
    my_putstr(": Permission denied\n");
  else
    my_putstr(": Command not found.\n");
}

int	do_access(char *bin)
{
  int	ok;

  if (access(bin, F_OK) == 0)
    {
      if (access(bin, X_OK | R_OK) == 0)
	ok = 1;
      else
	ok = 3;
    }
  else
    ok = 2;
  return (ok);
}

int	check_bin(char **cmd, char **path)
{
  int	i;
  int	ok;
  char	*temp;

  i = 0;
  temp = cmd[0];
  ok = 0;
  while (path[i] != NULL && ok != 1)
    {
      cmd[0] = my_str_link(path[i], temp);
      ok = do_access(cmd[0]);
      i++;
      if (ok != 1)
        free(cmd[0]);
      else
	free(temp);
    }
  if (ok != 1)
    {
      cmd[0] = temp;
      bin_error(temp, ok);
      return (-1);
    }
  return (0);
}

int		check_bin_list(t_dlist *list, char **env)
{
  t_elem	*temp;
  char		**path;
  int		i;

  i = 0;
  temp = list->begin;
  path = mns_recup_bin(env);
  while (i < list->taille)
    {
      if (check_bin(list->begin->data, path) == -1)
	return (-1);
      while (list->begin->s != NULL && list->begin->s[0] != '|')
	{
	  list->begin = list->begin->next;
	  ++i;
	}
      list->begin = list->begin->next;
      ++i;
    }
  my_free_tab(path);
  list->begin = temp;
  return (0);
}
