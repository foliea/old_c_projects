/*
** mns_builtins.c for mns_builtins in /u/all/folie_a/cu/rendu/c/minishell1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Thu Jun  4 13:42:08 2009 adrien folie
** Last update Mon Oct  5 01:56:31 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

typedef struct	s_built
{
    char	*builtin;
    int		(*f)();
}		t_built;

static const t_built	index[]=
{
  {"env", my_env},
  {"cd", my_cd},
  {"unsetenv", my_unsetenv},
  {"setenv", my_setenv},
  {NULL, NULL}
};

int	my_env(char ***env, __attribute__((unused)) char **cmd)
{
  if (*env == NULL)
    return (0);
  my_show_tab(*env);
  return (0);
}

void	do_alone(t_elem *p, char ***env)
{
  if (one_builtin(p->data, env) == 0)
    do_cmd(p, env, 1);
}

int	one_builtin(char **cmd, char ***env)
{
  int	i;

  i = 0;
  while (index[i].builtin != NULL)
    {
      if (my_strcmp(cmd[0], index[i].builtin) == 1)
        {
          index[i].f(env, cmd);
          return (1);
        }
      ++i;
    }
  return (0);
}
