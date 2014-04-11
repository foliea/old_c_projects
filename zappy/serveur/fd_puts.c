/*
** fd_puts.c for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu May 27 02:39:20 2010 adrien folie
** Last update Wed Jun 16 00:36:29 2010 edern bienvenu
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	fd_puts(int fd, char *str)
{
  if (write(fd, str, strlen(str)) == -1)
    exit(EXIT_FAILURE);
  return (strlen(str));
}
