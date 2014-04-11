/*
** put.c for  in /u/all/gouesl_a/cu/rendu/my_ftp/common
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Apr 18 20:44:10 2010 antoine goueslard
** Last update Sun Apr 18 21:11:53 2010 antoine goueslard
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

char	*put_sent(char *to_send)
{
  char	*ret;
  char	**tab;
  
  tab = str_to_tab(to_send);
  if (tab[2] != 0 || tab[1] == 0)
    return (0);
  if (!(ret = calloc(strlen(to_send) + 3, sizeof(*ret))))
    exit(EXIT_FAILURE);
  ret[0] = 0;
  ret = strcat(ret, "C_PUT ");
  ret = strcat(ret, tab[1]);
  ret[strlen(ret) - 1] = 0;
  return (ret);
}

int	init_put(char *com, int s)
{
  int	fd;
  char	*str;
  
  if ((fd = put_open((str = put_sent(com)))) == -1)
    {
      puts("Open error");
      return (0);
    }
  my_puts(s,str);
  str = get_next_line(s);
  if (strcmp(str, "PUT_S_OK") != 0)
    {
      close (fd);
      puts("SEV NOK");
      return (0);
    }
  return (fd);
}


char	*do_put(int s, char *to_send)
{   
  int	fd;
  char	*str;
  
  if ((fd = init_put(to_send, s)) == 0)
    return (0);
  while (strlen(str = get_next_line(fd)))
    {
      my_puts(s,str);
      free(str);    
      str = get_next_line(s);
      free(str);
    }
  my_puts(s, "C_PUT_DONE");
  close(fd);
  return ("File Succesfully uploaded");
}


char	*serv_put(char *com)
{
  char *ret;
  int    fd;
  
  if ((fd = get_open(com)) == -1)
    {
      my_puts(2,"Open error");
    }
  my_puts(1, "PUT_S_OK");
  while (strcmp((ret = get_next_line(1)), "C_PUT_DONE"))
    {
      my_puts(fd, ret);
      my_puts(1, "ok");
    }
  close(fd);
  return ("File Download Succed");
}
