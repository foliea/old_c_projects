/*
** state.c for philo in /u/all/folie_a/cu/public/dedern/philo
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Sun May  2 19:30:39 2010 adrien folie
** Last update Tue May 11 18:03:40 2010 adrien folie
*/

#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include "philo.h"

extern t_philo		data[NB_THREADS];
extern t_mutex		utils[NB_MUTEX];

int	check_nb(int nb)
{
  int	nb_left;

  if (nb == 0)
    nb_left = NB_THREADS - 1;
  else
    nb_left = nb - 1;
  return (nb_left);
}

void	trying_state(int nb)
{
  int	nb_left;
  int	nb_right;

  nb_right = nb;
  nb_left = check_nb(nb);
  while (data[nb].G == EMPTY || data[nb].D == EMPTY)
    {
      if (data[nb].G == EMPTY)
	{
	  if (utils[nb_left].ask == -1)
	    send_request(nb, nb_left);
	  receive_baguette(nb, nb_left);
	}
      if (data[nb].D == EMPTY)
	{
	  if (utils[nb_right].ask == -1)
	    send_request(nb, nb_right);
	  receive_baguette(nb, nb_right);
	}
      if (data[nb].G == FULL && utils[nb_left].etat == SALE)
	send_baguette(nb, nb_left);
      if (data[nb].D == FULL && utils[nb_right].etat == SALE)
	send_baguette(nb, nb_right);
    }
}

void	eating_state(int nb)
{
  int	nb_right;
  int	nb_left;

  printf("\033[0;31m$%d : Eating state (%d) \033[0;0m\n",
	 nb, data[nb].nb_eating);
  nb_right = nb;
  nb_left = check_nb(nb);
  utils[nb_left].etat = SALE;
  utils[nb_right].etat = SALE;
  sleep(2);
}

void	exit_state(int nb)
{
  int	nb_right;
  int	nb_left;

  printf("$%d : Exit state (%d)\n", nb, data[nb].nb_exit);
  nb_right = nb;
  nb_left = check_nb(nb);
  if (utils[nb_left].ask != -1)
    send_baguette(nb, nb_left);
  if (utils[nb_right].ask != -1)
    send_baguette(nb, nb_right);
}

void		sleeping_state(int nb)
{
  time_t	start;
  time_t	point;
  int		nb_right;
  int		nb_left;

  printf("$%d : Sleeping state (%d)\n", nb, data[nb].nb_sleeping);
  nb_right = nb;
  nb_left = check_nb(nb);
  time(&start);
  time(&point);
  while (point - start > 5)
    {
      time(&point);
      if (utils[nb_left].ask != -1)
	send_baguette(nb, nb_left);
      if (utils[nb_right].ask != -1)
	send_baguette(nb, nb_right);
    }
}
