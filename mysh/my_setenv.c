/*
** my_setenv.c for my_setenv.c in /u/all/folie_a/cu/rendu/c/minishell1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Jun 10 13:39:04 2009 adrien folie
** Last update Thu Jun 18 15:28:48 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char	*my_line_env(char *l1, char *l2)
{
  int	i;
  int	j;
  char	*final;

  i = 0;
  j = 0;
  final = xmalloc(my_strlen(l1) + my_strlen(l2) + 1);
  while (l1[i] != '\0')
    {
      final[i] = l1[i];
      ++i;
    }
  final[i] = '=';
  ++i;
  while (l2[j] != '\0')
    {
      final[i] = l2[j];
      ++i;
      ++j;
    }
  final[i] = '\0';
  return (final);
}

void	my_addenv(char ***env, __attribute__((unused)) char **cmd, char *line)
{
  char	**tmp;
  char	**new;
  int	i;

  i = 0;
  tmp = *env;
  new = malloc((my_tab_len(tmp) + 2) * sizeof(*new));
  if (new == NULL)
    my_error_report(7);
  while (tmp[i] != NULL)
    {
      new[i] = tmp[i];
      ++i;
    }
  new[i] = line;
  ++i;
  new[i] = NULL;
  free(*env);
  *env = new;
}

int	my_line_is_in(char ***env, char *line, char **cmd)
{
  char	**temp;
  char	*del;
  int	i;

  i = 0;
  temp = *env;
  cmd[1] = my_env_var(cmd[1]);
  while (temp[i] != NULL)
    {
      if (my_str_is_in(temp[i], cmd[1]) == 1)
        {
          del = temp[i];
          temp[i] = line;
          free(del);
          return (1);
        }
      ++i;
    }
  return (0);
}

int	my_setenv(char ***env, char **cmd)
{
  char	*line;

  if (my_tab_len(cmd) < 2)
    return (0);
  if (my_tab_len(cmd) > 3)
    {
      my_putstr("setenv: Too many arguments.\n");
      return (0);
    }
  else
    {
      if (my_tab_len(cmd) == 2)
	line = my_line_env(cmd[1], "\0");
      else
	line = my_line_env(cmd[1], cmd[2]);
      if (my_line_is_in(env, line, cmd) == 0)
	my_addenv(env, cmd, line);
    }
  return (0);
}
