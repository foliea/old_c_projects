/*
** fd_puts.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Jul  9 05:15:59 2010 adrien folie
** Last update Fri Jul  9 05:16:00 2010 adrien folie
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
