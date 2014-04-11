/*
** mns_main.c for main in /u/all/folie_a/cu/rendu/c/minishell1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun May 31 23:13:58 2009 adrien folie
** Last update Mon Oct  5 01:01:15 2009 adrien folie
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "minishell.h"
#include "get_next_line.h"
#define PROMPT "$>"

int	re_prompt(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == '\n')
	return (1);
      ++i;
    }
  return (0);
}

int	mns_main(char ***env)
{
  char	*line;
  int	ok;

  ok = 1;
  old_pwd(env);
  while (ok == 1)
    {
      my_putstr(PROMPT);
      line = get_next_line(0);
      if (line == NULL)
	{
	  my_putchar('\n');
	  return (0);
	}
      if (my_strcmp("exit", line) != 1)
	{
	  if (my_check_str(line) == 1)
	    mns_recup_cmd(line, env);
	  ok = 1;
	}
      else
	ok = 0;
      free(line);
    }
  return (0);
}

int	main(int ac, __attribute__((unused)) char **av, char **env)
{
  char	**cpy;

  if (ac == 1)
    {
      cpy = my_tab_dup(env);
      mns_main(&cpy);
      my_free_tab(cpy);
    }
  else
    {
      my_put_error("Arguments invalids.\n");
      exit(EXIT_FAILURE);
    }
  my_putstr("---\tMinishell by folie_a.\t\t\t---\n");
  my_putstr("---\t2.0 for FreeBsd, Linux and SunOs.\t---\n");
  return (0);
}
