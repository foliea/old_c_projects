/*
** init.c for lemipc in /u/all/folie_a/public/dedern/lemipc
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sat May 22 10:54:50 2010 edern bienvenu
** Last update Sun May 23 19:49:58 2010 edern bienvenu
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

void	init_all(t_data *data, key_t key)
{
  printf("Create map...\n");
  data->shm_id = shmget(key, WIDTH * HEIGHT + 1, IPC_CREAT | SHM_R | SHM_W);
  if (data->shm_id == -1)
    aff_error("Creation failed");
  data->map = shmat(data->shm_id, NULL, 0);
  if (data->map == NULL)
    aff_error("Shmat failed");
  printf("%s\n", data->map);
  memset(data->map, '0', WIDTH * HEIGHT);
  data->map[WIDTH * HEIGHT] = 0;
  data->sem_id = semget(key, 1, IPC_CREAT | IPC_R | IPC_W);
  if (data->sem_id == -1)
    aff_error("Semaphore Creation failed");
  data->msg_id = msgget(key, IPC_CREAT | IPC_R | IPC_W);
  if (data->msg_id == -1)
    aff_error("Msgqueue Creation failed");
  if (semctl(data->sem_id, 0, SETVAL, 1) == -1)
    aff_error("Semaphore Creation failed");
  return ;
}
