/*
** cbuff.h for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Jun  1 23:56:28 2010 adrien folie
** Last update Sat Jun 19 03:36:35 2010 antoine goueslard
*/

#ifndef CBUFF_H
#define CBUFF_H

#define M_SIZE 1024
#define MAX_QUEUE 10

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

void		add_to_cbuff(t_cbuff *cbuff, char *temp, int nb_read, int t, int fd);

#endif
