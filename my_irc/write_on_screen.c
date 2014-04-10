/*
** write_on_screen.c for gtk in /u/all/folie_a/cu/test/gtk
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr 27 20:20:26 2010 adrien folie
** Last update Wed Apr 28 10:13:08 2010 adrien folie
*/

#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "window.h"

void		clean_text_view(t_myGtk *data)
{
  GtkTextBuffer	*pTextBuffer;
  GtkTextIter	iStart;
  GtkTextIter	iEnd;

  pTextBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(data->ContactText));
  gtk_text_buffer_get_start_iter(pTextBuffer, &iStart);
  gtk_text_buffer_get_end_iter(pTextBuffer, &iEnd);
  gtk_text_buffer_delete(pTextBuffer, &iStart, &iEnd);
}

void		write_on_screen(GSList *list,
				char *channel,
				char *msg,
				int LineReturn)
{
  GSList	*temp;
  t_myGtk	*data;

  temp = list;
  while (list != NULL)
    {
      data = list->data;
      if (strcmp(channel, data->name) == 0)
	{
	  myGtk_puts((gchar *) msg, data->ChatBuffer, 0, 1);
	  if (LineReturn == 1)
	    myGtk_puts((gchar *) "\n", data->ChatBuffer, 0, 1);
	}
      list = list->next;
    }
  list = temp;
}

void		write_on_contacts(GSList *list, char *channel, char *msg)
{
  GSList	*temp;
  t_myGtk	*data;

 temp = list;
  while (list != NULL)
    {
      data = list->data;
      if (strcmp(channel, data->name) == 0)
        {
	  clean_text_view(data);
          myGtk_puts((gchar *) msg, data->ContactText, 0, 1);
        }
      list = list->next;
    }
  list = temp;
}
