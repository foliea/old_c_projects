/*
** mns_sort_cmd.c for mns_sort_cmd.c in /u/all/folie_a/cu/rendu/c/minishell2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Sep 28 13:07:10 2009 adrien folie
** Last update Sat Oct  3 17:43:00 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int	find_size(char **tab, int i)
{
  int	t;

  t = my_tab_len(tab);
  while (i != t && tab[i][0] != '>' && tab[i][0] != '<' && tab[i][0] != '|')
    ++i;
  return (i);
}

char	**create_elem(char **cmd, int i, int j)
{
  char	**new;
  int	k;

  k = 0;
  new = malloc((j - i + 1) * sizeof(*new));
  if (new == NULL)
    exit(EXIT_FAILURE);
  while (i < j)
    {
      new[k] = cmd[i];
      ++k;
      ++i;
    }
  new[k] = NULL;
  return (new);
}

void	print_sort_error(char **cmd, int s)
{
  if (cmd[s][0] == '|')
    my_putstr("Invalid null command.\n");
  if (cmd[s][0] == '>' || cmd[s][0] == '<')
    my_putstr("Missing name for redirect.\n");
  my_free_tab(cmd);
}

int	check_before_sort(char **cmd)
{
  int	s;

  s = my_tab_len(cmd);
  if (cmd[s - 1][0] == '|' || cmd[s - 1][0] == '<' || cmd[s - 1][0] == '>')
    {
      print_sort_error(cmd, s - 1);
      return (-1);
    }
  if (cmd[0][0] == '|' || cmd[0][0] == '<' || cmd[0][0] == '>')
    {
      print_sort_error(cmd, 0);
      return (-1);
    }
  return (0);
}

int	mns_sort_cmd(t_dlist *list, char *line)
{
  char	**cmd;
  char	**new;
  int	i;
  int	j;
  int	s;

  i = 0;
  cmd = my_str_to_wordtab(line, ' ', 0);
  s = my_tab_len(cmd);
  if (check_before_sort(cmd) == 0)
    {
      while (i <= s)
	{
	  j = find_size(cmd, i);
	  new = create_elem(cmd, i, j);
	  my_put_in_dlist(list, new, cmd[j], 1);
	  i = j + 1;
	}
    }
  else
    return (-1);
  free(cmd);
  return (0);
}
