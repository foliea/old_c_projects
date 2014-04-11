/*
** send_ko.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun Jun 20 15:30:39 2010 edern bienvenu
** Last update Sun Jun 20 17:21:59 2010 edern bienvenu
*/

#include <stdio.h>
#include "fd_puts.h"

void	send_ko(int fd)
{
  printf("\033[0;31mSending message to %d :\033[0;0m ko\n", fd);
  fd_puts(fd, "ko\n");
}
