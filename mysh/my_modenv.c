/*
** my_modenv.c for my_modenv in /u/all/folie_a/cu/rendu/c/minishell1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Jun 17 18:59:40 2009 adrien folie
** Last update Wed Jun 17 19:17:06 2009 adrien folie
*/

#include "stdlib.h"
#include "minishell.h"

char	*my_str_join(char *l1, char *l2)
{
  char	*cpy;
  int	i;
  int	j;

  i = 0;
  j = 0;
  cpy = xmalloc(my_strlen(l1) + my_strlen(l2));
  while (l1[i] != '\0')
    {
      cpy[i] = l1[i];
      ++i;
    }
  while (l2[j] != '\0')
    {
      cpy[i] = l2[j];
      ++i;
      ++j;
    }
  cpy[i] = '\0';
  return (cpy);
}

int	shlvl_plus(char **env, char *data)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_str_is_in(env[i], data) == 1)
	{
	  env[i][6] += 1;
	  return (1);
	}
      ++i;
    }
  return (0);
}

int	my_modenv(char **env, char *line, char *data)
{
  int	i;
  char	*temp;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_str_is_in(env[i], data))
	{
	  temp = env[i];
	  env[i] = my_str_join(data, line);
	  free(temp);
	  return (1);
	}
      ++i;
    }
  return (0);
}
