/*
** cbuff.h for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:06:24 2010 adrien folie
** Last update Mon Jul 12 23:22:34 2010 adrien folie
*/

#ifndef CBUFF_H
#define CBUFF_H

#define EXCESS_FLOOD 8192
#define CREAD 0
#define CWRITE 1

typedef struct		s_ebuff
{
  char			character;
  struct s_ebuff	*next;
  struct s_ebuff	*prev;
}			t_ebuff;

typedef struct		s_cbuff
{
  struct s_ebuff	*begin;
  struct s_ebuff	*end;
  int			taille;
}			t_cbuff;

void	init_cbuff(t_cbuff *cbuff);
int	put_in_cbuff(t_cbuff *cbuff, char c, int sort);
void	add_to_cbuff(t_cbuff *cbuff, char *temp, int nb_read, int fd);
char	*manage_cbuff(t_cbuff *cbuff, int fd, int mode);
void	stack_write(t_cbuff *cbuff, char *str);

#endif
