/*
** mns_recup_bin.c for my_getpath in /u/all/folie_a/cu/rendu/c/minishell1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Jun  1 03:50:38 2009 adrien folie
** Last update Tue Jun 16 18:45:40 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

int	my_str_is_in(char *str, char *to_find)
{
  int	save;
  int	i;
  int	a;

  a = 0;
  i = 0;
  save = 0;
  while (str[i] != '\0')
    {
      save = i;
      while ((str[i] == to_find[a]) && ((str[i] != '\0')
                                        || (to_find[a] != '\0')))
        {
          i = i + 1;
          a = a + 1;
        }
      if (to_find[a] == '\0')
        return (1);
      a = 0;
      i = i + 1;
    }
  return (0);
}

char	*my_path_dup(char *str, int i, int j)
{
  char	*dup;
  int	k;

  k = 0;
  dup = malloc((j - i + 1) * sizeof(*dup));
  if (dup == NULL)
    my_error_report(7);
  while (str[i] != '\0')
    {
      dup[k] = str[i];
      ++i;
      ++k;
    }
  dup[k] = '\0';
  return (dup);
}

char	*my_getenv(char **env, char *data)
{
  int   i;
  char  *path;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_str_is_in(env[i], data) != 0)
	{
	  path = my_path_dup(env[i], my_strlen(data), my_strlen(env[i]));
	  return (path);
	}
      ++i;
    }
  return (NULL);
}
