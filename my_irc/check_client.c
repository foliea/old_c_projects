/*
** check_client.c for my_irc in /u/all/folie_a/cu/test/gtk
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr 27 23:54:58 2010 adrien folie
** Last update Tue Apr 27 23:55:40 2010 adrien folie
*/

#include <string.h>
#include <gtk/gtk.h>
#include "window.h"

int		channel_exist(GSList *list, char *channel)
{
  GSList        *temp;
  t_myGtk	*data;

  temp = list;
  while (list != NULL)
    {
      data = list->data;
      if (strcmp(data->name, channel) == 0)
	{
	  list = temp;
	  return (1);
	}
      list = list->next;
    }
  list = temp;
  return (0);
}
