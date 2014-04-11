/*
** mini_next.c for  in /u/all/gouesl_a/cu/rendu/my_ftp/common
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Apr 18 20:44:16 2010 antoine goueslard
** Last update Sun Apr 18 21:01:29 2010 antoine goueslard
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*get_next_line(int fd)
{
  char	temp[1024];
  char	*result;
  int	i;
  
  i = 0;
  while (i < 1024)
    temp[i++] = 0;
  if ((i = read(fd,temp,1023)) == -1)
    exit(EXIT_FAILURE);
  result = strdup(temp);
  return (result);
}
