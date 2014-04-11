/*
** find_size.c for find_size in /u/all/folie_a/cu/rendu/rush/grimly/part1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sat Nov  7 01:35:57 2009 adrien folie
** Last update Sat Nov  7 22:14:11 2009 adrien folie
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "librush.h"
#include "grimly.h"

int	find_width(char *line, int i)
{
  char	*width;
  int	j;

  j = 0;
  width = xmalloc((i + 1) * sizeof(width));
  while (j < i)
    {
      width[j] = line[j];
      ++j;
    }
  width[j] = '\0';
  j = my_getnbr(width);
  free(width);
  if (j <= 1 || j > 2000000)
    my_put_error("MAP ERROR\n");
  return (j);
}

int	find_height(char *line, int i)
{
  char	*height;
  int	size;
  int	j;

  size = height_len(line, i);
  height = xmalloc((size + 1) * sizeof(height));
  j = 0;
  while (line[i] != '\0')
    {
      height[j] = line[i];
      ++i;
      ++j;
    }
  height[j] = '\0';
  i = my_getnbr(height);
  free(height);
  if (i <= 1 || i > 2000000)
    my_put_error("MAP ERROR\n");
  return (i);
}

int	width_len(char *line)
{
  int	i;

  i = 0;
  while (line[i] != 'x')
    {
      if (line[i] < '0' || line[i] > '9')
	my_put_error("MAP ERROR\n");
      ++i;
    }
  return (i);
}

int	height_len(char *line, int i)
{
  int	j;

  j = i;
  while (line[i] != '\0')
    {
      if (line[i] < '0' || line[i] > '9')
	my_put_error("MAP ERROR\n");
      ++i;
    }
  return (i - j + 1);
}
