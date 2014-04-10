/*
** ls_mod.c for ls_mod in /u/all/folie_a/cu
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Tue May 26 04:28:13 2009 adrien folie
** Last update Tue May 26 05:44:28 2009 adrien folie
*/

#include "my_ls.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void	my_print_type(mode_t st_mode)
{
  if (S_ISDIR(st_mode))
    my_putchar('d');
  else if (S_ISREG(st_mode))
    my_putchar('-');
  else if (S_ISCHR(st_mode))
    my_putchar('c');
  else if (S_ISBLK(st_mode))
    my_putchar('b');
  else if (S_ISFIFO(st_mode))
    my_putchar('p');
  else if (S_ISLNK(st_mode))
    my_putchar('l');
  else if (S_ISSOCK(st_mode))
    my_putchar('s');
  else if (S_ISWHT(st_mode))
    my_putchar('w');
}

void	my_print_chmod(mode_t st_mode)
{
  S_IRUSR & st_mode ? my_putchar('r') : my_putchar('-');
  S_IWUSR & st_mode ? my_putchar('w') : my_putchar('-');
  S_IXUSR & st_mode ? my_putchar('x') : my_putchar('-');
  S_IRGRP & st_mode ? my_putchar('r') : my_putchar('-');
  S_IWGRP & st_mode ? my_putchar('w') : my_putchar('-');
  S_IXGRP & st_mode ? my_putchar('x') : my_putchar('-');
  S_IROTH & st_mode ? my_putchar('r') : my_putchar('-');
  S_IWOTH & st_mode ? my_putchar('w') : my_putchar('-');
  S_IXOTH & st_mode ? my_putchar('x') : my_putchar('-');
  my_putstr("  ");
}
