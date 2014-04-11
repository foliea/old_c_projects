/*
** serveur.c for serveur in /u/all/folie_a/cu/rendu/c/minitalk
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Oct  5 22:13:09 2009 adrien folie
** Last update Sun Oct 18 23:24:35 2009 adrien folie
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "minitalk.h"

int	fpid = 0;

void			recup_char(int nb)
{
  static unsigned char	result = 0;
  static int		i = 0;
  int			save;

  save = fpid;
  if (i == 8)
    {
      i = 0;
      result = 0;
    }
  result = result + (nb << i);
  ++i;
  if (i == 8)
    {
      if (result != 0)
	my_putchar(result);
      else
	fpid = -2;
    }
  if (kill(save, SIGUSR1) == -1)
    my_put_error("\nkill: invalid process\n");
}

void	recup_pid(int nb)
{
  static unsigned int	res = 0;
  static int		j = 0;

  if (fpid == -2)
    {
      j = 0;
      fpid = 0;
      res = 0;
    }
  res = res + (nb << j);
  ++j;
  if (j == 32)
    fpid = res;
}

void	handler(int sig)
{
  if (sig == SIGUSR1)
    recup_char(1);
  else if (sig == SIGUSR2)
    recup_char(0);
  if (signal(SIGUSR1, &handler) == SIG_ERR)
    my_put_error("Signal error\n");
  if (signal(SIGUSR2, &handler) == SIG_ERR)
    my_put_error("Signal error\n");
}

void	h_pid(int sig)
{
  if (sig == SIGUSR1)
    recup_pid(1);
  else if (sig == SIGUSR2)
    recup_pid(0);
  if (signal(SIGUSR1, &h_pid) == SIG_ERR)
    my_put_error("Signal error\n");
  if (signal(SIGUSR2, &h_pid) == SIG_ERR)
    my_put_error("Signal error\n");
}

void	wait_signals(void)
{
  if (signal(SIGUSR1, &h_pid) == SIG_ERR)
    my_put_error("Signal error\n");
  if (signal(SIGUSR2, &h_pid) == SIG_ERR)
    my_put_error("Signal error\n");
  while (fpid <= 0)
    pause();
  if (signal(SIGUSR1, &handler) == SIG_ERR)
    my_put_error("Signal error\n");
  if (signal(SIGUSR2, &handler) == SIG_ERR)
    my_put_error("Signal error\n");
  if (kill(fpid, SIGUSR1) == -1)
    my_put_error("\nkill: invalid process\n");
  while (fpid > 0)
    pause();
}
