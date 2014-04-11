/*
** my_unsetenv.c for my_unsetenv.c in /u/all/folie_a/cu/rendu/c/minishell1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Jun 10 13:42:04 2009 adrien folie
** Last update Thu Jun 18 16:15:38 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char	*my_env_var(char *data)
{
  int	i;
  char	*cpy;

  i = 0;
  cpy = xmalloc(my_strlen(data) + 1);
  while (data[i] != '\0')
    {
      cpy[i] = data[i];
      ++i;
    }
  cpy[i] = '=';
  ++i;
  cpy[i] = '\0';
  free(data);
  return (cpy);
}

char	**my_ret_env(char **temp, char **cmd)
{
  int	i;
  int	j;
  char	**new;

  i = 0;
  j = 0;
  new = malloc(my_tab_len(temp) * sizeof(*new));
  if (new == NULL)
    my_error_report(7);
  cmd[1] = my_env_var(cmd[1]);
  while (temp[j] != NULL)
    {
      if (my_str_is_in(temp[j], cmd[1]) == 1)
	{
	  free(temp[j]);
	  ++j;
	}
      if (temp[j] != NULL)
        new[i++] = temp[j++];
    }
  new[i] = NULL;
  return (new);
}

int	my_var_in_env(char **env, char *var)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_str_is_in(env[i], var) == 1)
	return (1);
      ++i;
    }
  return (0);
}

int	my_unsetenv(char ***env, char **cmd)
{
  char	**temp;

  temp = *env;
  if (my_tab_len(cmd) < 2)
    return (0);
  if (my_tab_len(*env) == 1)
    {
      temp[0] = NULL;
      return (0);
    }
  else
    {
      if (my_var_in_env(*env, cmd[1]) == 1)
	{
	  *env = my_ret_env(*env, cmd);
	  free(temp);
	}
    }
  return (0);
}
