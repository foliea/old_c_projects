/*
** lemipc.h for lemipc in /u/all/folie_a/cu/public/dedern/lemipc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 21 18:51:36 2010 adrien folie
** Last update Fri Jun  4 16:50:34 2010 adrien folie
*/

#ifndef LEMIPC_H_
#define LEMIPC_H_

#define MAX_TEAM 9
#define WIDTH 10
#define HEIGHT 10

typedef struct	s_brain
{
  int		x_me;
  int		y_me;
  int		x_target;
  int		y_target;
  int		diff_x;
  int		diff_y;
}		t_brain;

typedef struct	s_data
{
  char		*map;
  int		pos;
  int		shm_id;
  int		sem_id;
  int		msg_id;
  int		team;
  int		target;
}		t_data;

typedef struct	s_mymsg
{
  long		msg_type;
  int		nb_team;
  int		nb_target;
}		t_mymsg;

/*---- Functions ----*/

void	check_lose(t_data *data);
int	check_if_last(char *map);
void	aff_error(char *str);
void	random_move(t_data *data);
int	do_down(t_data *data);
int	do_up(t_data *data);
int	do_right(t_data *data);
int	do_left(t_data *data);
int	find_target(t_data *data);
void	intel_move(t_data *data);
void	send_message(t_data *data);
void	receive_message(t_data *data);
void	handler(__attribute__((unused)) int sig);
void	*xmalloc(int size);

#endif
