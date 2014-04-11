/*
** old_pwd.c for old_pwd in /u/all/folie_a/cu/rendu/c/minishell2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Tue Sep 29 17:04:20 2009 adrien folie
** Last update Mon Oct  5 01:53:17 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int	old_pwd(char ***env)
{
  char	**cmd;
  char	*pwd;

  cmd = malloc(4 * sizeof(*cmd));
  if (cmd == NULL)
    my_error_report(7);
  pwd = my_getenv(*env, "PWD=");
  if (pwd == NULL)
    return (0);
  cmd[0] = my_strdup("setenv");
  cmd[1] = my_strdup("OLDPWD");
  cmd[2] = pwd;
  cmd[3] = NULL;
  my_setenv(env, cmd);
  my_free_tab(cmd);
  return (0);
}

void	new_pwd(char ***env, char *new)
{
  char	**cmd;

  cmd = malloc(4 * sizeof(*cmd));
  if (cmd == NULL)
    my_error_report(7);
  cmd[0] = my_strdup("setenv");
  cmd[1] = my_strdup("PWD");
  cmd[2] = new;
  cmd[3] = NULL;
  my_setenv(env, cmd);
  free(cmd[0]);
  free(cmd[1]);
  free(cmd);
}

char	*do_epur(char *str, int separator, int opt)
{
  str = my_strepur(str, 0);
  if (opt == 1)
    str = my_strepur2(str, 0, separator);
  return (str);
}
