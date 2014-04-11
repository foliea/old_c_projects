/*
** move.c for  in /u/all/bienve_e/public/zappy/2_antoine/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Tue Jun  1 02:21:56 2010 antoine goueslard
** Last update Thu Jun 17 06:15:35 2010 antoine goueslard
*/

#include <stdlib.h>
#include "client.h"


t_act	*do_avance(int s, char *to_send, int fnbr, t_act *commands)
{
  int	i;

  i = can_do(s, commands);
  to_send = 0;
  if (i != 10)
    {
      commands = add_commands(fnbr, NULL, 7, commands);
      my_puts(s, "avance\n");
    }
  return (commands);
}

t_act	*do_droite(int s, char *to_send, int fnbr, t_act *commands)
{
  int	i;

  i = can_do(s, commands);
  to_send = 0;
  if (i != 10)
    {
      commands = add_commands(fnbr, NULL, 7, commands);
      my_puts(s, "droite\n");
    }
  return (commands);
}

t_act	*do_gauche(int s, char *to_send, int fnbr, t_act *commands)
{
  int	i;

  i = can_do(s, commands);
  to_send = 0;
  if (i != 10)
    {
      commands = add_commands(fnbr, NULL, 7, commands);
      my_puts(s, "gauche\n");
    }
   return (commands);
}

t_act	*do_voir(int s, char *to_send, int fnbr, t_act *commands)
{
  int	i;

  i = can_do(s, commands);
  to_send = 0;
  if (i != 10)
    {
      commands = add_commands(fnbr, NULL, 7, commands);
      my_puts(s, "voir\n");
    }
  return (commands);
}

t_act	*do_expulse(int s, char *to_send, int fnbr, t_act *commands)
{
  int	i;

  i = can_do(s, commands);
  to_send = 0;
  if (i != 10)
    {
      commands = add_commands(fnbr, NULL, 7, commands);
      my_puts(s, "expulse\n");
    }
  return (commands);
}
