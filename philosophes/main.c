/*
** main.c for philo in /u/all/folie_a/cu/public/dedern/philo
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Sun May  2 19:30:39 2010 adrien folie
** Last update Tue May 11 18:03:43 2010 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include "philo.h"

t_philo		data[NB_THREADS];
t_mutex		utils[NB_MUTEX];

void	init_philo(int nb)
{
  data[nb].G = EMPTY;
  data[nb].D = FULL;
  data[nb].nb_trying = 0;
  data[nb].nb_eating = 0;
  data[nb].nb_sleeping = 0;
  data[nb].nb_exit = 0;
  utils[nb].owner = nb;
  pthread_mutex_lock(&(utils[nb].mutex));
}

void	*do_thread(void	*arg)
{
  int	i;
  int	nb;

  nb = (int) arg;
  init_philo(nb);
  signal(SIGINT, &handler);
  i = 0;
  while (42)
    {
      data[nb].nb_trying++;
      printf("\033[0;33m$%d : Trying state (%d)\033[0;0m\n",
	     nb, data[nb].nb_trying);
      trying_state(nb);
      data[nb].nb_eating++;
      eating_state(nb);
      data[nb].nb_exit++;
      exit_state(nb);
      data[nb].nb_sleeping++;
      sleeping_state(nb);
      ++i;
    }
  pthread_exit(NULL);
}

void	init_threads(void)
{
  int	i;

  i = 0;
  while (i < NB_THREADS)
    {
      data[i].P = i;
      if (pthread_create(&(data[i].thread), NULL, do_thread, (void *) i))
	exit(EXIT_FAILURE);
      ++i;
    }
}

void	init_mutex()
{
  int	i;

  i = 0;
  while (i < NB_MUTEX)
    {
      pthread_mutex_init(&(utils[i].mutex), NULL);
      utils[i].ask = -1;
      utils[i].owner = -1;
      if (i % 2 == 0)
	utils[i].etat = SALE;
      else
	utils[i].etat = PROPRE;
      ++i;
    }
}

int	main()
{
  init_threads();
  init_mutex();
  pthread_exit(NULL);
  return (0);
}
