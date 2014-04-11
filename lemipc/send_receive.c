/*
** send_receive.c for lemipc in /u/all/folie_a/cu/public/dedern/lemipc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 21 17:12:48 2010 adrien folie
** Last update Sun May 23 19:37:07 2010 edern bienvenu
*/

#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include "lemipc.h"

void		send_message(t_data *data)
{
  t_mymsg	msg;

  msg.msg_type = (long) data->team;
  if ((msg.nb_target = find_target(data)) == -1)
    return ;
  if (msgsnd(data->msg_id, &msg, sizeof(msg), IPC_NOWAIT) != -1)
    printf("Send target %d to teammates of team %d\n",
	   msg.nb_target, data->team);
}

void		receive_message(t_data *data)
{
  t_mymsg	msg;
  int		rcv;

  msg.msg_type = (long) data->team;
  rcv = msgrcv(data->msg_id, &msg, sizeof(msg), msg.msg_type, IPC_NOWAIT);
  if (rcv != -1 && msg.nb_target != -1)
    {
      data->target = msg.nb_target;
      printf("Switch to target %d\n", msg.nb_target);
    }
}
