/*
** parse_mud.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 01:32:38 2010 adrien folie
** Last update Thu Jul 15 02:56:40 2010 adrien folie
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "utils.h"
#include "get_next_line.h"
#include "tlist.h"
#include "room.h"

void	check_line(char *line, char sep, int opt)
{
  int	i;
  int	nb;
  int	s;

  i = 0;
  nb = 0;
  s = 0;
  while (line[i] != '\0')
    {
      if (line[i] == sep)
	{
	  if (s == 1)
	    aff_error("map incorrect");
	  nb++;
	  s = 1;
	}
      else
	s = 0;
      ++i;
    }
  if (nb != 3 && opt == 1)
    aff_error("map incorrect");
}

void	parse_obj(t_room *data, char *line)
{
  char	**obj;
  int	i;

  if (strlen(line) == 0)
    aff_error("map incorrect");
  if (line[0] == ',' || line[strlen(line) - 1] == ',')
    aff_error("map incorrect");
  check_line(line, ',', 0);
  obj = str_to_wordtab(line, ',');
  i = 0;
  while (obj[i] != NULL)
    {
      put_in_tlist(data->obj, strdup(obj[i]), 1);
      ++i;
    }
  free_tab(obj);
}

void	parse_links(t_room *data, char *line)
{
  char	**links;

  if (strlen(line) == 0)
    aff_error("map incorrect");
  if (line[0] == ',' || line[strlen(line) - 1] == ',')
    aff_error("map incorrect");
  check_line(line, ',', 1);
  links = str_to_wordtab(line, ',');
  data->nord = atoi(links[0]);
  data->sud = atoi(links[1]);
  data->est = atoi(links[2]);
  data->ouest = atoi(links[3]);
  free_tab(links);
}

void		parse_line(t_tlist *map, char *line)
{
  t_room	*data;
  char		**room;

  if (line[strlen(line) - 1] == ':')
    line[strlen(line) - 1] = '\0';
  data = xmalloc(sizeof(struct s_room));
  data->obj = xmalloc(sizeof(struct s_tlist));
      init_tlist(data->obj);
  room = str_to_wordtab(line, ':');
  data->id = atoi(room[0]);
  data->txt = strdup(room[1]);
  parse_links(data, room[2]);
  if (tab_len(room) == 4)
    parse_obj(data, room[3]);
  free_tab(room);
  put_in_tlist(map, data, 1);
}

void	parse_map(t_tlist *map, char *file)
{
  char	*line;
  int	fd;

  if (file == NULL)
    aff_error("map file incorrect");
  fd = open(file, O_RDONLY);
  if (fd == -1)
    aff_error("map file incorrect");
  while ((line = get_next_line(fd)) != NULL)
    {
      if (strlen(line) == 0)
	aff_error("map incorrect");
      if (line[0] == ':')
	aff_error("map incorrect");
      check_line(line, ':', 1);
      parse_line(map, line);
      free(line);
    }
  close (fd);
}
