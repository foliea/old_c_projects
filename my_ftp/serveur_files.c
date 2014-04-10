/*
** serveur_files.c for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Apr  9 18:43:54 2010 adrien folie
** Last update Sun Apr 18 03:13:25 2010 adrien folie
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "serveur.h"

void	loop_put(int cs, int fd)
{
  char	buff[1024];
  char	stop[1];
  int	nb_read;
  int	ok;

  ok = 1;
  while (ok)
    {
      xread(cs, stop, 1);
      if (stop[0] == '0')
	{
	  my_putstr("CONTINUE");
	  memset(buff, 0, 1024);
	  nb_read = xread(cs, buff, 1024);
	  xwrite(fd, buff, nb_read);
	  my_putstr("CONTINUE");
	}
      else
	{
	  my_putstr("CONTINUE");
	  ok = 0;
	}
    }
}

void	put_file(char **cmd, int cs)
{
  int	fd;
  char	stop[1];
  char	**name;

  xread(cs, stop, 1);
  if (stop[0] == '1')
    return ;
  name = str_to_wordtab(cmd[1], '/');
  fd = open(name[my_tablen(name) - 1], O_CREAT | O_RDWR | O_TRUNC | O_APPEND,
	    S_IROTH | S_IREAD | S_IWRITE | S_IRGRP);
  my_freetab(name);
  if (fd == -1)
    {
      my_putstr("QUIT");
      return ;
    }
  else
    my_putstr("CONTINUE");
  loop_put(cs, fd);
  close(fd);
}

void	loop_get(int cs, int fd)
{
  char	buff[1024];
  char	waiting[8];
  int	nb_read;
  int	ok;

  ok = 1;
  while (ok)
    {
      memset(buff, 0, 1024);
      nb_read = xread(fd, buff, 1024);
      if (nb_read > 0)
        {
          xwrite(cs, "0", 1);
          while (read(cs, waiting, 8) != 8);
          xwrite(cs, buff, nb_read);
          while (read(cs, waiting, 8) != 8);
        }
      else
        {
          xwrite(cs, "1", 1);
          while (read(cs, waiting, 8) != 8);
          ok = 0;
        }
    }
}

void	get_file(char **cmd, int cs)
{
  int	fd;
  char	waiting[8];

  fd = open(cmd[1], O_RDONLY);
  if (fd == -1)
    {
      xwrite(cs, "1", 1);
      return ;
    }
  xwrite(cs, "0", 1);
  if (xread(cs, waiting, 8) != 8)
    return ;
  loop_get(cs, fd);
  close(fd);
}
