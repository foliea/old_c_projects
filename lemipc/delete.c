/*
** delete.c for delete in /u/all/folie_a/public/dedern/lemipc
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sat May 22 10:35:23 2010 edern bienvenu
** Last update Sat May 22 10:35:52 2010 edern bienvenu
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/msg.h>
#include <unistd.h>

void	init_game()
{
  int	shm_id;
  int	sem_id;
  key_t	key;

  key = ftok(".", 0);
  shm_id = shmget(key, 255, SHM_R | SHM_W);
  if (shm_id != -1)
    shmctl(shm_id, IPC_RMID, NULL);
  sem_id = semget(key, 1, SHM_R | SHM_W);
  if (sem_id != -1)
    semctl(sem_id, 1, IPC_RMID);
  return ;
}

int	main(int ac, char **av)
{
  init_game();
  return (0);
}
