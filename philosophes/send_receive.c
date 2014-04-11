/*
** send_receive.c for philo in /u/all/folie_a/cu/public/dedern/philo
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue May  4 18:04:07 2010 adrien folie
** Last update Fri May  7 12:54:59 2010 edern bienvenu
*/

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include "philo.h"

extern t_philo	data[NB_THREADS];
extern t_mutex	utils[NB_MUTEX];

void	send_request(int nb, int nb_b)
{
  utils[nb_b].ask = nb;
  printf("\033[0;32m$%d ask for #%d\033[0;0m\n", nb, nb_b);
}

void	send_baguette(int nb, int nb_b)
{
  if (utils[nb_b].ask == -1)
    return ;
  pthread_mutex_unlock(&(utils[nb_b].mutex));
  utils[nb_b].etat = PROPRE;
  utils[nb_b].owner = utils[nb_b].ask;
  utils[nb_b].ask = -1;
  if (nb_b != nb)
    data[nb].G = EMPTY;
  else
    data[nb].D = EMPTY;
  printf("\033[0;36m$%d send baguette #%d to $%d\033[0;0m\n",
	 nb, nb_b, utils[nb_b].owner);
}

void	receive_baguette(int nb, int nb_b)
{
  if (utils[nb_b].owner == nb)
    {
      pthread_mutex_lock(&(utils[nb_b].mutex));
      if (nb_b != nb)
	data[nb].G = FULL;
      else
	data[nb].D = FULL;
    }
}
