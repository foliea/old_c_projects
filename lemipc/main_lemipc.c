/*
** main_lemipc.c for lemipc in /u/all/folie_a/cu/public/dedern/lemipc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 21 17:12:59 2010 adrien folie
** Last update Sun May 23 20:00:21 2010 edern bienvenu
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include "lemipc.h"

void	init_all(t_data *data, key_t key);

t_data	*ptr;

void		handler(__attribute__((unused)) int sig)
{
  struct sembuf	sops;

  ptr->map[ptr->pos] = '0';
  sops.sem_op = 1;
  sops.sem_num = 0;
  sops.sem_flg = IPC_NOWAIT;
  if (semop(ptr->sem_id, &sops, 1) == -1)
    aff_error("Semop failed");
  if (check_if_last(ptr->map) == 0)
    {
      if (shmctl(ptr->shm_id, IPC_RMID, NULL) == -1)
	aff_error("Shcmtl failed");
      if (semctl(ptr->sem_id, 1, IPC_RMID) == -1)
	aff_error("Semctl failed");
      if (msgctl(ptr->msg_id, IPC_RMID, NULL) == -1)
	aff_error("Msgctl failed");
    }
  exit(EXIT_SUCCESS);
}

void	init_game(t_data *data)
{
  key_t key;

  if ((key = ftok(".", 0)) == -1)
    aff_error("Ftok failed");
  data->shm_id = shmget(key, WIDTH * HEIGHT + 1, SHM_R | SHM_W);
  if (data->shm_id == -1)
    init_all(data, key);
  else
    {
      data->map = shmat(data->shm_id, NULL, 0);
      if (data->map == NULL)
	aff_error("Shmat failed");
      data->sem_id = semget(key, 1, IPC_R | IPC_W);
      if (data->sem_id == -1)
	aff_error("Semaphore recuperation failed");
      data->msg_id = msgget(key, IPC_R | IPC_W);
      if (data->msg_id == -1)
	aff_error("Msgaueue Recuperation failed");
    }
}

void		init_player(t_data *data)
{
  int		ok;

  srand(time(NULL));
  data->pos = 0;
  data->target = -1;
  ok = 1;
  while (ok)
    {
      data->pos = rand() % (WIDTH * HEIGHT);
      if (data->map[data->pos] == '0')
	{
	  data->map[data->pos] = data->team + '0';
	  ok = 0;
	}
    }
}

void		game_loop(t_data *data)
{
  struct sembuf	sops;

  while (42)
    {
      receive_message(data);
      sops.sem_num = 0;
      sops.sem_flg = IPC_NOWAIT;
      sops.sem_op = -1;
      if (semop(data->sem_id, &sops, 1) != -1)
	{
	  puts("-- MOVE (SEMAPHORE LOCKED) --");
	  check_lose(data);
	  intel_move(data);
	  check_lose(data);
	  send_message(data);
	  sops.sem_op = 1;
	  if (semop(data->sem_id, &sops, 1) == -1)
	    aff_error("Semop error");
	  else
	    puts("-- WAIT (SEMAPHORE UNLOCKED) --");
	}
    }
}

int		main(int ac, char **av)
{
  t_data	*data;

  if (ac != 2)
    return (1);
  data = xmalloc(sizeof(*data));
  ptr = data;
  data->team = atoi(av[1]);
  if (data->team <= 0 || data->team > 9)
    aff_error("Bad team number");
  init_game(data);
  init_player(data);
  if (signal(SIGINT, &handler) == SIG_ERR)
    aff_error("Signal failed");
  game_loop(data);
  return (0);
}
