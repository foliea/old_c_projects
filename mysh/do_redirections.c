/*
** do_redirections.c for do_redirections.c in /u/all/folie_a/cu/rendu/c/minishell2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri Oct  2 02:40:59 2009 adrien folie
** Last update Sat Oct  3 22:44:40 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "minishell.h"

int	redirection_right(t_elem *p, int *i)
{
  int	fd;

  if (my_strlen(p->prev->s) == 2)
    {
      if ((fd = open(p->data[0], O_CREAT | O_WRONLY | O_APPEND)) == -1)
	{
	  my_putstr(p->data[0]);
	  my_putstr(": Permission denied\n");
	}
    }
  else
    {
      if ((fd = open(p->data[0], O_CREAT | O_WRONLY | O_TRUNC)) == -1)
	{
          my_putstr(p->data[0]);
          my_putstr(": Permission denied\n");
        }
    }
  *i = *i + 1;
  return (fd);
}

int	double_left(char *str)
{
  char	*line;

  while (42)
    {
      my_putstr("? ");
      line = get_next_line(0);
      if (line == NULL)
	return (-1);
      if (my_strcmp(line, str) == 1)
	{
	  free(line);
	  return (-1);
	}
      free(line);
    }
}

int	redirection_left(t_dlist *list, int *i, int *j)
{
  int	fd;

  *j = 1;
  if (my_strlen(list->begin->prev->s) == 2)
    fd = double_left(list->begin->data[0]);
  else if ((fd = open(list->begin->data[0], O_RDONLY)) == -1)
    {
      my_putstr(list->begin->data[0]);
      my_putstr(": No such file or directory.\n");
    }
  *i = *i + 1;
  return (fd);
}
