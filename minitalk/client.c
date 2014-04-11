/*
** client.c for client in /u/all/folie_a/cu/rendu/c/minitalk
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Oct  5 23:03:46 2009 adrien folie
** Last update Mon Oct 19 10:10:50 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "minitalk.h"

int	waiting;

void	handler(int sig)
{
  if (sig == SIGUSR1)
    waiting = 1;
  if (signal(SIGUSR1, &handler) == SIG_ERR)
    my_put_error("Signal error\n");
}

void	send_char(char c, int pid)
{
  int	i;
  int	test;

  i = 0;
  test = 1;
  if (signal(SIGUSR1, &handler) == SIG_ERR)
    my_put_error("Signal error\n");
  while (i < 8)
    {
      waiting = 0;
      if ((test & c) == test)
	{
	  if (kill(pid, SIGUSR1) == -1)
	    my_put_error("kill: invalid process\n");
	}
      else
	{
	  if (kill(pid, SIGUSR2) == -1)
	    my_put_error("kill: invalid process\n");
	}
      while (waiting == 0)
        pause();
      test = test << 1;
      ++i;
    }
}

void	send_msg(char *str, int pid)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      send_char(str[i], pid);
      usleep(1);
      ++i;
    }
  send_char(0, pid);
}

void	send_pid(int fpid, int pid)
{
  int   i;
  int   test;

  i = 0;
  test = 1;
  while (i < 32)
    {
      if ((test & fpid) == test)
	{
	  if (kill(pid, SIGUSR1) == -1)
	    my_put_error("kill: invalid process\n");
	}
      else
	{
	  if (kill(pid, SIGUSR2) == -1)
	    my_put_error("kill: invalid process\n");
	}
      test = test << 1;
      usleep(300);
      ++i;
    }
}

int	main(int ac, char **av)
{
  int	pid;
  int	fpid;

  if (ac != 3)
    my_put_error("--usage : ./client [Pid] [Message]\n");
  pid = my_getnbr(av[1]);
  if (pid <= 0 || pid >= 2000000000)
    my_put_error("pid incorrect\n");
  fpid = getpid();
  waiting = 0;
  if (signal(SIGUSR1, &handler) == SIG_ERR)
    my_put_error("Signal error\n");
  send_pid(fpid, pid);
  while (waiting == 0)
    pause();
  send_msg(av[2], pid);
  return (0);
}
