/*
** main_serveur.c for main_serveur in /u/all/folie_a/cu/rendu/c/minitalk
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Oct 12 15:10:34 2009 adrien folie
** Last update Sat Oct 17 17:15:52 2009 adrien folie
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "minitalk.h"
#include "serveur.h"

void	write_pid(void)
{
  int	ppid;

  ppid = getpid();
  my_putstr("Serveur PID : ");
  my_put_nbr(ppid);
  my_putchar('\n');
}

int	main()
{
  write_pid();
  while (42)
    {
      wait_signals();
      my_putchar('\n');
    }
  return (0);
}
