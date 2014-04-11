/*
** cbuff.h for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Jun  1 23:56:28 2010 adrien folie
** Last update Wed Jun  2 03:09:00 2010 adrien folie
*/

#define M_SIZE 1024

typedef struct	s_cbuff
{
  char		data[M_SIZE];
  int		start;
  int		end;
}		t_cbuff;

typedef struct		s_circular
{
  int			fd;
  t_cbuff		*cbuff;
  struct s_circular	*next;
  struct s_circular	*prev;
}			t_circular;

typedef struct		s_dcircular
{
  struct s_circular	*begin;
  struct s_circular	*end;
  int			taille;
}			t_dcircular;
