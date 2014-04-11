/*
** do_pipes.c for do_pipes.c in /u/all/folie_a/cu/rendu/c/minishell2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sat Oct  3 01:30:30 2009 adrien folie
** Last update Mon Oct  5 01:56:09 2009 adrien folie
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "minishell.h"

int	fork_and_exec(t_elem *p, char ***env, int fd_in, int fd_out)
{
  pid_t	child;
  int	status;

  if ((child = fork()) == -1)
    return (-1);
  if (child != 0)
    wait(&status);
  else
    {
      if (fd_in != -1 && fd_in != 0)
	{
	  dup2(fd_in, 0);
	  close(fd_in);
	}
      if (fd_out != -1 && fd_in != 1)
	{
	  dup2(fd_out, 1);
	  close(fd_out);
	}
      execve(p->data[0], p->data, *env);
    }
  return (0);
}

typedef	struct	s_pipes
{
    int   fd_pipe[2];
    int   fd_in;
    int   fd_out;
    int   i;
    int   j;
}		t_pipes;

void	init_function_pipe(t_pipes *var)
{
  var->fd_in = -1;
  var->i = 0;
  var->j = 0;
}

void	close_function_pipe(t_pipes *var)
{
  close(var->fd_in);
  close(var->fd_out);
  var->fd_in = var->fd_pipe[0];
  var->i++;
}

int	do_next_command(t_elem *p, t_elem *e, t_pipes *var)
{
  if (p->next != NULL)
    {
      if (p == e->prev && p->s[0] == '>')
	{
	  if ((var->fd_out = redirection_right(p->next, &var->i)) == -1)
	    return (-1);
	}
      else
	{
	  pipe(var->fd_pipe);
	  var->fd_out = var->fd_pipe[1];
	}
    }
  else
    var->fd_out = -1;
  return (0);
}

int		do_pipes(t_dlist *list, char ***env)
{
  t_pipes	var;

  init_function_pipe(&var);
  while (var.i < list->taille)
    {
      if (list->begin->s != NULL && list->begin->s[0] == '<')
        {
	  list->begin = list->begin->next;
	  if ((var.fd_in = redirection_left(list, &var.i, &var.j)) == -1)
            return (0);
        }
      if (do_next_command(list->begin, list->end, &var) == -1)
	return (0);
      if (var.j == 0)
	fork_and_exec(list->begin, env, var.fd_in, var.fd_out);
      else
	var.j = fork_and_exec(list->begin->prev, env, var.fd_in, var.fd_out);
      close_function_pipe(&var);
      list->begin = list->begin->next;
    }
  return (0);
}
