/*
** my_ioctl_mod.c for my_ioctl_mod in /u/all/folie_a/cu/rendu/c/my_select
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri Jun 19 01:39:25 2009 adrien folie
** Last update Mon Jul  6 15:05:39 2009 adrien folie
*/

#include "termios.h"
#include <sys/ioctl.h>


void			my_ioctl_mod(void)
{
  struct termios	term;

  ioctl(0, TIOCGETA, &term);
  term.c_lflag = term.c_lflag & ~(ICANON | ECHO | ISIG);
  ioctl(0, TIOCSETA, &term);
}
