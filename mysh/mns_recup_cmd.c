/*
** mns_recup_cmd.c for mns_recup_cmd in /u/all/folie_a/cu/rendu/c/minishell1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Tue Jun  2 15:39:59 2009 adrien folie
** Last update Mon Apr 12 00:55:02 2010 adrien folie
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "minishell.h"

char    *my_str_link(char *s1, char *s2)
{
  int   i;
  int   j;
  char  *cpy;

  i = 0;
  j = 0;
  if (s2[0] == '/' || (s2[0] == '.' && s2[1] == '/'))
    return (s2);
  cpy = xmalloc(my_strlen(s1) + my_strlen(s2) + 1);
  while (s1[i] != '\0')
    {
      cpy[i] = s1[i];
      ++i;
    }
  if (s1[my_strlen(s1) - 1] != '/')
    cpy[i++] = '/';
  while (s2[j] != '\0')
    {
      cpy[i] = s2[j];
      ++i;
      ++j;
    }
  cpy[i] = '\0';
  return (cpy);
}

int		exec_cmd(char **cmd, char ***env, int cas)
{
  pid_t		pid;
  int		status ;

  puts(cmd[0]);
  if (access(cmd[0], X_OK | R_OK) == 0)
    {
      if (cas == 0)
	execve(cmd[0], cmd, *env);
      else if (cas == 1)
	{
	  if ((pid = fork()) == -1)
	    {
	      my_putstr("Fork failed\n");
	      return (-1);
	    }
	  if (pid != 0)
	    wait(&status);
	  else
	    execve(cmd[0], cmd, *env);
	}
    }
  else
    {
      my_putstr(cmd[0]);
      my_putstr(": Permission denied\n");
    }
  return (0);
}

void		check_cmd(char **cmd, char **path, char ***env, int cas)
{
  int		i;
  int		yes;
  struct stat	sb;
  char		*temp;

  i = 0;
  temp = cmd[0];
  yes = 0;
  while (path[i] != NULL && yes == 0)
    {
      cmd[0] = my_str_link(path[i], temp);
      if (stat(cmd[0], &sb) != -1)
	{
	  exec_cmd(cmd, env, cas);
	  yes = 1;
	}
      ++i;
      if (my_strcmp(cmd[0], temp) != 1)
	free(cmd[0]);
    }
  if (yes == 0)
    {
      my_putstr(temp);
      my_putstr(": Command not found.\n");
    }
  cmd[0] = temp;
}

void	do_cmd(t_elem *p, char ***env, int cas)
{
  char	**path;

  path = mns_recup_bin(*env);
  if (path != NULL)
    {
      check_cmd(p->data, path, env, cas);
      my_free_tab(path);
    }
  else
    {
      my_putstr(p->data[0]);
      my_putstr(": Command not found.\n");
    }
}

void		mns_recup_cmd(char *line, char ***env)
{
  t_dlist	list;
  char		**tab;
  int		i;

  i = 0;
  tab = my_str_to_wordtab(line, ';', 1);
  while (tab[i] != NULL)
    {
      my_init_dlist(&list);
      if (mns_sort_cmd(&list, tab[i]) != -1)
	{
	  if (check_list(&list) == 0)
	    {
	      if (list.taille > 1)
		{
		  if (check_bin_list(&list, *env) != -1)
		    do_pipes(&list, env);
		}
	      else
		do_alone(list.begin, env);
	    }
	  my_free_dlist(&list);
	}
      ++i;
    }
  my_free_tab(tab);
}
