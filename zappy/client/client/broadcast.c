/*
** broadcast.c for  in /u/all/bienve_e/public/zappy/2_antoine
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Thu Jun 17 05:47:40 2010 antoine goueslard
** Last update Sun Jun 20 14:07:15 2010 antoine goueslard
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

extern t_play player;

char	*gen_message(void)
{
  char	*mess;

  if ((mess = calloc(1024, sizeof(*mess))) == 0)
    exit(EXIT_FAILURE);
  mess = strcat(mess,"broadcast ");
  mess = strcat(mess,player.team);
  mess = strcat(mess,"#");
  mess[strlen(mess)] = player.niveau + '0';
  mess = strcat(mess,"\n");
  my_puts(1,mess);
  return (mess);
}

void			get_message(char *ans)
{
  char			**messtab;
  char			**my_mess;
  struct timeval	since;

  messtab = stotab(ans, ',');
  if (messtab[1] != 0)
    {
      my_mess = stotab(messtab[1], '#');
      if (strcmp(my_mess[0],player.team) == 0
	  && atoi(my_mess[1]) == player.niveau)
	{
	  player.mess.dir = 1;
	  player.mess.level = atoi(my_mess[1]);
	  player.mess.from = atoi(&messtab[0][8]);
	  gettimeofday(&since, NULL);
	  player.mess.since = since;
	  printf("new message : from %i elevating\n",player.mess.from);
	}
    }
}
t_act	*do_broad(int s, char *to_send, int fnbr, t_act *commands)
{
  int	i;

  i = can_do(s, commands);
  to_send = gen_message();
  if (i != 10)
    {
      commands = add_commands(fnbr, NULL, 7, commands);
      my_puts(s, to_send);
    }
  return (commands);
}
