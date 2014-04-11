/*
** end.c for philosophes in /u/all/folie_a/public/dedern/philo
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri May  7 12:47:11 2010 edern bienvenu
** Last update Tue May 11 18:06:13 2010 adrien folie
*/

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "philo.h"

extern t_philo	data[NB_THREADS];
extern t_mutex	utils[NB_MUTEX];

void	aff_end(int nb)
{
  printf("\n\033[0;31m********Resultat Philosophes #%d*********\033[0;0m\n",
	 nb);
  printf("Eating state : %d\n",
	 data[nb].nb_eating);
  printf("Sleeping state : %d\n",
	 data[nb].nb_sleeping);
  printf("Trying state : %d\n",
	 data[nb].nb_trying);
  printf("\033[0;31m********Fin Philosophes #%d**************\033[0;0m\n\n",
	 nb);
}

void	handler(__attribute__((unused)) int sig)
{
  int	i;

  i = 0;
  puts("");
  while (i < NB_THREADS)
    {
      aff_end(i);
      i++;
    }
  exit(EXIT_SUCCESS);
}
