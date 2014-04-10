/*
** my_getpwd.c for my_getpwd in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Tue May 26 02:52:37 2009 adrien folie
** Last update Tue May 26 03:33:32 2009 adrien folie
*/

#include <stdlib.h>
#include "my_ls.h"

int    my_str_is_in(char *str, char *to_find)
{
  int   save;
  int   i;
  int   a;

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

char	*my_pwd_dup(char *str, int i, int j)
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

char	*my_getpwd(char **env)
{
  int	i;
  char	*pwd;

  i = 0;
  while (env[i] != NULL && pwd != NULL)
    {
      if (my_str_is_in(env[i], "PWD=") != 0)
	pwd = my_pwd_dup(env[i], 4, my_strlen(env[i]));
      ++i;
    }
  return (pwd);
}
