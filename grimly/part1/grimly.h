/*
** grimly.h for grimly in /u/all/folie_a/cu/rendu/rush/grimly/part1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri Nov  6 23:25:49 2009 adrien folie
** Last update Sun Nov  8 02:54:42 2009 adrien folie
*/

#ifndef GRIMLY_H_
# define GRIMLY_H_

#include "dlist.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

typedef struct	s_point
{
    int		x;
    int		y;
}		t_point;

typedef struct	s_case
{
    float	cout[4];
}		t_case;

typedef struct	s_lab
{
    int		w;
    int		h;
    char	*auteur;
    t_point	enter;
    t_dlist	exit;
    t_case	**hiden;
}		t_lab;

char	*xmalloc(int size);
char	**my_tabdup(char **tab);
int	height_len(char *line, int i);
int	width_len(char *line);
int	find_height(char *line, int i);
int	find_width(char *line, int i);
int	my_put_error(char *str);
int	check_case(t_lab *lab, int x, int y, char **map);
void	check_file(char *file);
void	lab_size(t_lab *lab, char *line, int fd, int i);
void	read_file(int fd);
void	print_lab(t_lab lab);
void	check_map(t_lab *lab, char **map);
void	do_move(t_lab *lab, char **map);
void	hiden_malloc(t_lab *lab);

#endif /* !GRIMLY_H_ */
