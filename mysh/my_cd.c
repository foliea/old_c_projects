/*
** my_cd.c for my_cd in /u/all/folie_a/cu/rendu/c/minishell2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sat Oct  3 01:20:52 2009 adrien folie
** Last update Mon Oct  5 00:03:10 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"

int	exec_cd(char ***env, char *dir, int f)
{
  if (access(dir, F_OK) != 0)
    {
      my_putstr(dir);
      my_putstr(": No such file or directory.\n");
    }
  else
    {
      if (chdir(dir) == -1)
        {
          my_putstr(dir);
	  my_putstr(": Permission denied.\n");
        }
      else
	{
	  old_pwd(env);
	  new_pwd(env, dir);
	}
    }
  if (f == 1)
    free(dir);
  return (0);
}

int	do_cd(char ***env, char **cmd)
{
  char	*dir;
  int	i;

  i = 1;
  if (my_tab_len(cmd) == 1)
    {
      if (*env != NULL)
        dir = my_getenv(*env, "HOME=");
      if (dir == NULL)
        my_putstr("cd: HOME not set\n");
      else
        exec_cd(env, dir, 1);
    }
  else
    {
      if ((i = my_strcmp("-", cmd[1])) == -1)
	dir = cmd[1];
      else
	dir = my_getenv(*env, "OLDPWD=");
      if (dir == NULL)
	my_putstr("cd: can't find OLDPWD.\n");
      else
	exec_cd(env, dir, i);
    }
  return (0);
}

int	my_cd(char ***env, char **cmd)
{
  if (my_tab_len(cmd) > 2)
    my_putstr("cd: Too many arguments.\n");
  else
    do_cd(env, cmd);
  return (0);
}
