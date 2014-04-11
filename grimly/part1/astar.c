/*
** astar.c for astar in /u/all/folie_a/cu/rendu/rush/grimly/part1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sat Nov  7 17:28:45 2009 adrien folie
** Last update Sun Nov  8 19:59:05 2009 adrien folie
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "librush.h"
#include "grimly.h"

int	move_on(t_lab *lab, int *x, int *y, char **map)
{
  int	i;
  int	tmp;

  i = 0;
  tmp = 0;
  check_case(lab, *x, *y, map);
  while (i < 4)
    {
      if ((lab->hiden[*y][*x].cout[i] != -1.0 &&
	   (lab->hiden[*y][*x].cout[i] < lab->hiden[*y][*x].cout[tmp]))
	|| lab->hiden[*y][*x].cout[tmp] == -1.0)
	tmp = i;
      ++i;
    }
  if (lab->hiden[*y][*x].cout[tmp] == -1.0)
    return (-1);
  if (tmp == UP)
    *y -= 1;
  if (tmp == DOWN)
    *y += 1;
  if (tmp == LEFT)
    *x -= 1;
  if (tmp == RIGHT)
    *x += 1;
  return (0);
}

int	check_crevasse(char **map, int x, int y)
{
  int	i;

  i = 0;
  if (map[y][x + 1] == '*')
    ++i;
  if (map[y][x - 1] == '*')
    ++i;
  if (map[y - 1][x] == '*')
    ++i;
  if (map[y + 1][x] == '*')
    ++i;
  return (i);
}

void	complete_map(char **map, int w, int h)
{
  int	ok;
  int	i;
  int	j;

  ok = 1;
  while (ok == 1)
    {
      ok = 0;
      j = 1;
      while (j < h - 1)
	{
	  i = 1;
	  while (i < w - 1)
	    {
	      if (map[j][i] == ' ')
		{
		  if (check_crevasse(map, i, j) >= 3)
		    {
		      map[j][i] = '*';
		      ok = 1;
		    }
		}
	      ++i;
	    }
	  ++j;
	}
    }
}

void	print_result(t_lab *lab, char **map, int score)
{
  map[lab->enter.y][lab->enter.x] = '1';
  if (lab->auteur != NULL)
    {
      my_putstr(lab->auteur);
      my_putchar('\n');
    }
  printf("%dx%d\n", lab->w, lab->h);
  my_showtab(map);
  printf("= > RESULTAT EN %d COUPS !\n", score);
}

void		move_back(t_dlist *history, int *x, int *y, char **map, char **temp, t_lab *lab)
{
  t_elem	*tmp;

  if (*y == lab->enter.y && *x == lab->enter.x)
    my_put_error("MAP_ERROR\n");
/*  if (temp[*y][*x] == '1')
    {
      lab->exit.begin = lab->exit.begin->next;
      if (lab->exit.begin)
	my_put_error("MAP_ERROR\n");
      else
	do_move(lab, temp);
    }
    my_put_error("MAP_ERROR\n");*/
  tmp = history->end;
  temp[*y][*x] = ' ';
  map[*y][*x] = '*';
  *x = tmp->x;
  *y = tmp->y;
  history->end = history->end->prev;
  history->taille--;
  free(tmp);
}

void		do_move(t_lab *lab, char **map)
{
  char		**temp;
  int		x;
  int		y;
  t_dlist	history;

  my_init_dlist(&history);
  temp = my_tabdup(map);
  x = lab->enter.x;
  y = lab->enter.y;
  hiden_malloc(lab);
  complete_map(map, lab->w, lab->h);
  while (map[y][x] != '2')
    {
      my_put_in_dlist(&history, x, y, 1);
      while (move_on(lab, &x, &y, map) == -1)
	move_back(&history, &x, &y, map, temp, lab);
      if (map[y][x] != '2')
	{
	  temp[y][x] = 'o';
	  map[y][x] = '0';
	}
    }
  print_result(lab, temp, history.taille);
  my_free_dlist(&history);
  my_freetab(temp);
}
