/*
** client_files.c for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Apr  9 18:49:40 2010 adrien folie
** Last update Sun Apr 18 19:46:44 2010 adrien folie
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "client.h"

void	loop_puts(int s, int fd)
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
	  xwrite(s, "0", 1);
	  while (xread(s, waiting, 8) != 8);
	  xwrite(s, buff, nb_read);
	  while (xread(s, waiting, 8) != 8);
	}
      else
	{
	  xwrite(s, "1", 1);
	  while (xread(s, waiting, 8) != 8);
	  ok = 0;
	}
    }
}

void	put_files(char **cmd, int s)
{
  int	fd;
  char	waiting[8];

  fd = open(cmd[1], O_RDONLY);
  if (fd == -1)
    {
      puts("ERROR : can't open source file");
      xwrite(s, "1", 1);
      return ;
    }
  xwrite(s, "0", 1);
  if (xread(s, waiting, 8) != 8)
    {
      puts("ERROR : can't open destination file");
      return ;
    }
  loop_puts(s, fd);
  puts("SUCCESS");
  close(fd);
}

void	loop_gets(int s, int fd)
{
  char	buff[1024];
  char	stop[1];
  int	nb_read;
  int	ok;

  ok = 1;
  while (ok)
    {
      xread(s, stop, 1);
      if (stop[0] == '0')
	{
	  xwrite(s, "CONTINUE", 8);
          memset(buff, 0, 1024);
          nb_read = xread(s, buff, 1024);
          xwrite(fd, buff, nb_read);
	  xwrite(s, "CONTINUE", 8);
        }
      else
        {
	  xwrite(s, "CONTINUE", 8);
          ok = 0;
        }
    }
}

void	get_files(char **cmd, int s)
{
  int	fd;
  char	stop[1];
  char	**name;

  xread(s, stop, 1);
  if (stop[0] == '1')
    {
      puts("ERROR : can't open source file");
      return ;
    }
  name = str_to_wordtab(cmd[1], '/');
  fd = open(name[my_tablen(name) - 1], O_CREAT | O_RDWR | O_TRUNC | O_APPEND,
            S_IROTH | S_IREAD | S_IWRITE | S_IRGRP);
  my_freetab(name);
  if (fd == -1)
    {
      xwrite(s, "QUIT", 4);
      puts("ERROR : can't open destination file");
      return ;
    }
  else
    xwrite(s, "CONTINUE", 8);
  loop_gets(s, fd);
  puts("SUCCESS");
  close(fd);
}
