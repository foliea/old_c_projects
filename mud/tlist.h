/*
** tlist.h for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:10:58 2010 adrien folie
** Last update Thu Jul  8 05:49:28 2010 adrien folie
*/

#ifndef TLIST_H
#define TLIST_H

typedef struct	       	s_telem
{
  struct s_telem	*next;
  struct s_telem	*prev;
  void			*data;
}			t_telem;

typedef struct	s_tlist
{
  t_telem	*begin;
  t_telem	*end;
  int		taille;
}		t_tlist;

void	init_tlist(t_tlist *list);
void	put_in_tlist(t_tlist *list, void *data, int sort);

#endif
