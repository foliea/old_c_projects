/*
** cbuff.h for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Jun  1 23:56:28 2010 adrien folie
** Last update Sat Jun 19 03:48:23 2010 adrien folie
*/

#ifndef CBUFF_H
#define CBUFF_H

#define EXCESS_FLOOD 8192
#define MAX_QUEUE 10
#define WAITING_STATE -1
#define PLAYER 0
#define GRAPHICS 1
#define DEAD 2

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
  char			*queue[MAX_QUEUE];
  int			empty;
  char			type;
}			t_cbuff;

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

/*---- functions ----*/

void		aff_queue(t_cbuff *cbuff);
void		cmd_queue(t_cbuff *cbuff, int t, char *cmd, int fd);
void		move_queue(t_cbuff *cbuff, int t, char *cmd, int fd);
void		init_queue(t_cbuff *cbuff);
t_cbuff		*choose_buffer(int fd);
void		my_init_dcircular(t_dcircular *list);
int		my_put_in_dcircular(t_dcircular *list, int fd, int sort);
void		init_cbuff(t_cbuff *cbuff);
int		put_in_cbuff(t_cbuff *cbuff, char c, int sort);
void		manage_cmd(t_cbuff *cbuff, int t, char *tmp, int fd);
void		add_to_cbuff(t_cbuff *cbuff, char *temp, int nb_read, int t, int fd);

#endif
