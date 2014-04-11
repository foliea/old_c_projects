/*
** philo.h for philo in /u/all/folie_a/cu/public/dedern/philo
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Sun May  2 19:34:44 2010 adrien folie
** Last update Tue May 11 17:50:56 2010 adrien folie
*/

#ifndef PHILO_H_
#define PHILO_H_

#define NB_THREADS 7
#define NB_MUTEX 7
#define EMPTY -1
#define FULL 0

typedef struct		s_philo
{
  pthread_t		thread;
  int			P;
  int			G;
  int			D;
  int			nb_trying;
  int			nb_eating;
  int			nb_exit;
  int			nb_sleeping;
  int			state;
}			t_philo;

#define PROPRE -1
#define SALE 0

typedef struct		s_mutex
{
  pthread_mutex_t	mutex;
  int			etat;
  int			owner;
  int			ask;
}			t_mutex;

/*---- Functions ----*/

void	send_request(int nb, int nb_b);
void	send_baguette(int nb, int nb_b);
void	receive_baguette(int nb, int nb_b);
void	handler(int sig);
void	trying_state(int nb);
void	eating_state(int nb);
void	exit_state(int nb);
void	sleeping_state(int nb);

#endif
