/*
** get_ans.c for  in /u/all/bienve_e/public/zappy/2_antoine/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Wed Jun  2 00:17:33 2010 antoine goueslard
** Last update Sun Jun 20 21:13:44 2010 antoine goueslard
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "client.h"

extern t_play player;

t_act	*ret_classique(char *ans, t_act *commands)
{
  t_act *begin;
  
  begin = commands;
  if (begin != 0 && strlen(ans) != 0)
    {
      if (begin->fnbr <= 6 || begin->fnbr == 10)
	{	
	  commands = commands->next;
	  free (begin);
	}
      if (begin->fnbr == 9)
	if (strncmp(ans,"elevation en cours",18) != 0)
	  {
	    if (strncmp(ans,"niveau actuel :",15) == 0)
	      player.niveau = atoi(&ans[15]);
	    commands = commands->next;
	    free (begin);
	  }
    }
  else
    printf("Incorrect server answers \"%s\"",ans);
  return (commands);
}

t_act	*ret_iv(char *ans, t_act *commands)
{
  t_act *begin;
  
  begin = commands;
  if (begin != 0)
    {
      if (begin->fnbr == 7 || begin->fnbr == 8)
	{
	  if (begin->fnbr == 7)
	    ff_inv(&ans[1]);
	  else
	    ff_los(&ans[1]);
	  commands = commands->next;
	  free (begin);
	}
    }
  else
    printf("Incorrect server answers,:%s\n",ans);
  return (commands);
}

t_act	*ret_message(char *ans, t_act *commands)
{
  t_act *begin;

  begin = commands;
  get_message(ans);
  return (commands);
}

t_act	*check_ans(char *ans, t_act *commands)
{
  if (strlen(ans) > 0)
    {  
      if (strcmp(ans, "mort") == 0)
	{
	  my_puts(2, "Lol you'r dead\n");
	  fprintf(stderr, "you had %d food\n",player.inv.life);
	  exit(EXIT_SUCCESS);
	} 
      else if (ans[0] == '{')
	return (ret_iv(ans,  commands));
      if (strncmp(ans, "message", 7) == 0)
	return (ret_message(ans, commands));
      else
	return (ret_classique(ans, commands));
    }
  return (commands);
}

