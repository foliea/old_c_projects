/*
** client_select.c for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr  6 17:02:26 2010 adrien folie
** Last update Sun Apr 18 19:57:13 2010 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/param.h>
#include "serveur.h"

typedef struct	s_built
{
  char		*builtin;
  void		(*f)();
}		t_built;

static const t_built	func[]=
{
  {"cd", serveur_cd},
  {"pwd", serveur_pwd},
  {"ls", serveur_ls},
  {"put", put_file},
  {"get", get_file},
  {NULL, NULL}
};

void	serveur_pwd(__attribute__((unused)) char **cmd,
		    __attribute__((unused)) int cs)
{
  char	buff[4096];

  memset(buff, 0, 4096);
  if (getcwd(buff, 4096) == NULL)
    my_putstr("ERROR : can't pwd");
  else
    my_putstr(buff);
}

void	serveur_cd(char **cmd, __attribute__((unused)) int cs)
{
  if (chdir(cmd[1]) == -1)
    my_putstr("ERROR : can't cd to this directory");
  else
    my_putstr("SUCCESS");
}

int	serveur_select(char **cmd, int cs)
{
  int	i;

  i = 0;
  while (func[i].builtin != NULL)
    {
      if (strcmp(cmd[0], func[i].builtin) == 0)
	{
	  func[i].f(cmd, cs);
	  return (1);
	}
      ++i;
    }
  return (0);
}

void	check_path(char **cmd, char *path, int cs)
{
  char	limit[4096];
  char	test[8];

  memset(limit, 0, 4096);
  if (realpath(cmd[1], limit) == NULL)
    {
      my_putstr("1");
      while (read(cs, test, 8) != 8);
    }
  else if (strncmp(path, limit, strlen(path)) != 0)
    {
      my_putstr("1");
      while (read(cs, test, 8) != 8);
    }
  else
    {
      my_putstr("0");
      while (read(cs, test, 8) != 8);
      serveur_select(cmd, cs);
    }
}

void	serveur_cmd(char *line, int cs, char *path)
{
  char	**cmd;
  char	test[8];

  cmd = str_to_wordtab(line, ' ');
  if (my_tablen(cmd) > 1 && strcmp(cmd[0], "put") != 0)
    check_path(cmd, path, cs);
  else
    {
      my_putstr("0");
      while (read(cs, test, 8) != 8);
      serveur_select(cmd, cs);
    }
  my_freetab(cmd);
}
