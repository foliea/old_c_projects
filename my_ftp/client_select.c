/*
** client_select.c for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr  6 17:02:26 2010 adrien folie
** Last update Sun Apr 18 03:10:46 2010 adrien folie
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "client.h"
#include "get_next_line.h"

#define BUFF_SIZE 50

typedef struct	s_built
{
  char		*builtin;
  void		(*f)();
}		t_built;

static const t_built	func[]=
{
  {"cd", client_cd},
  {"pwd", client_pwd},
  {"ls", client_ls},
  {"put", put_files},
  {"get", get_files},
  {NULL, NULL}
};

void	client_pwd(__attribute__((unused)) char **cmd, int s)
{
  char	buff[4096];

  memset(buff, 0, 4096);
  xread(s, buff, 4096);
  puts(buff);
}

void	client_ls(__attribute__((unused)) char **cmd, int s)
{
  char	buff[BUFF_SIZE];
  int	ok;
  int	nb_read;

  ok = 1;
  while (ok != 0)
    {
      memset(buff, 0, BUFF_SIZE);
      nb_read = xread(s, buff, BUFF_SIZE);
      my_putstr(buff);
      xwrite(s, "CONTINUE", 8);
      memset(buff, 0, BUFF_SIZE);
      xread(s, buff, 1);
      if (buff[0] == '1')
	ok = 0;
      xwrite(s, "CONTINUE", 8);
    }
  puts("SUCCESS");
}

void	client_cd(__attribute__((unused)) char **cmd, int s)
{
  char	buff[4096];

  memset(buff, 0, 4096);
  xread(s, buff, 4096);
  puts(buff);
}

int	client_select(char **cmd, int s)
{
  int	i;

  i = 0;
  while (func[i].builtin != NULL)
    {
      if (strcmp(cmd[0], func[i].builtin) == 0)
	{
	  func[i].f(cmd, s);
	  return (1);
	}
      ++i;
    }
  return (0);
}

void	client_cmd(char *line, int s)
{
  char	**cmd;
  char	limit[1];

  cmd = str_to_wordtab(line, ' ');
  xwrite(s, line, strlen(line));
  memset(limit, 0, 1);
  xread(s, limit, 1);
  if (limit[0] == '0')
    {
      xwrite(s, "CONTINUE", 8);
      client_select(cmd, s);
    }
  else
    {
      xwrite(s, "CONTINUE", 8);
      puts("ERROR : security error");

    }
  my_freetab(cmd);
}
