/*
** main_grimly.c for main_grimly in /u/all/folie_a/cu/rendu/rush/grimly/part1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri Nov  6 23:16:06 2009 adrien folie
** Last update Sun Nov  8 02:08:15 2009 adrien folie
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "librush.h"
#include "get_next_line.h"
#include "grimly.h"

void	check_file(char *file)
{
  int	size;

  size = my_strlen(file) - 1;
  if (file[size] != 'p' || file[size - 1] != 'a'
    || file[size - 2] != 'm' || file[size - 3] != '.')
    my_put_error("MAP ERROR\n");
}

void	lab_size(t_lab *lab, char *line, int fd, int i)
{
  int	x;

  if (i == 1)
    {
      if ((line = get_next_line(fd)) == NULL)
	my_put_error("MAP ERROR\n");
    }
  else
    lab->auteur = NULL;
  x = width_len(line);
  lab->w = find_width(line, x);
  lab->h = find_height(line, x + 1);
}

char	**create_lab(t_lab *lab, char *line, int fd)
{
  char	**map;
  int	i;

  i = 0;
  if ((map = malloc((lab->h + 1) * sizeof(*map))) == NULL)
    my_put_error("MAP ERROR\n");
  while (i < lab->h)
    {
      if ((line = get_next_line(fd)) == NULL)
	my_put_error("MAP ERROR\n");
      if (my_strlen(line) != lab->w)
	my_put_error("MAP ERROR\n");
      map[i] = my_strdup(line);
      ++i;
    }
  map[i] = NULL;
  if ((line = get_next_line(fd)) != NULL)
    my_put_error("MAP ERROR\n");
  return (map);
}

void	read_file(int fd)
{
  t_lab	lab;
  char	*line;
  char	**map;

  if ((line = get_next_line(fd)) == NULL)
    my_put_error("MAP ERROR\n");
  if (strncmp(line, "AUTEUR", 6) == 0)
    {
      lab.auteur = my_strdup(line);
      if (my_strlen(lab.auteur) > 50)
	my_put_error("MAP ERROR\n");
      lab_size(&lab, line, fd, 1);
    }
  else
    lab_size(&lab, line, fd, 0);
  map = create_lab(&lab, line, fd);
  close(fd);
  check_map(&lab, map);
  do_move(&lab, map);
}

int	main(int ac, char **av)
{
  int	fd;

  if (ac != 3 || my_strcmp(av[1], "-f") != 0)
    my_put_error("MAP ERROR\n");
  check_file(av[2]);
  if ((fd = open(av[2], O_RDONLY)) == -1)
    my_put_error("MAP ERROR\n");
  read_file(fd);
  return (0);
}
