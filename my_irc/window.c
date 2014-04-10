/*
** window.c for gtk in /u/all/folie_a/cu/test/gtk
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr 27 21:05:36 2010 adrien folie
** Last update Wed Apr 28 10:12:50 2010 adrien folie
*/

#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "window.h"

extern struct s_Window Wdata;

void			myGtk_puts(gchar *sBuffer,
				   GtkWidget *Text,
				   int LineReturn,
				   int WindowScrollEnd)
{
  GtkTextBuffer		*pTextBuffer;
  GtkTextIter		iEnd;
  GtkTextMark		*mk;

  pTextBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(Text));
  if (LineReturn == 1)
    {
      gtk_text_buffer_get_end_iter(pTextBuffer, &iEnd);
      gtk_text_buffer_insert(pTextBuffer, &iEnd, "\n", -1);
    }
  gtk_text_buffer_get_end_iter(pTextBuffer, &iEnd);
  gtk_text_buffer_insert(pTextBuffer, &iEnd, sBuffer, -1);
  if (WindowScrollEnd == 1)
    {
      mk = gtk_text_buffer_get_mark(pTextBuffer, "insert");
      gtk_text_view_scroll_to_mark(GTK_TEXT_VIEW(Text),
				   mk, 0.0, FALSE, 0.0, 0.0);
    }
}

void		myGtkScroll(GtkWidget *widget,
			    GtkTextBuffer *pTextBuffer)
{
  GtkTextMark	*mk;

  mk = gtk_text_buffer_get_mark(pTextBuffer, "insert");
  gtk_text_view_scroll_to_mark(GTK_TEXT_VIEW(GTK_WIDGET(widget)),
			       mk, 0.0, FALSE, 0.0, 0.0);
}

void		myGtkKeys(GtkWidget *widget,
			  GdkEventKey *event,
			  gpointer transfer)
{
  GtkTextBuffer	*pTextBuffer;
  gchar		*sBuffer;
  GtkTextIter	iStart;
  GtkTextIter	iEnd;
  t_myGtk	*data;

  data = transfer;
  pTextBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(GTK_WIDGET(widget)));
  gtk_text_buffer_get_start_iter(pTextBuffer, &iStart);
  gtk_text_buffer_get_end_iter(pTextBuffer, &iEnd);
  if (event->keyval == KEY_ENTER || event->keyval == NUM_ENTER)
    {
      sBuffer = gtk_text_buffer_get_text(pTextBuffer, &iStart, &iEnd, TRUE);
      if (strcmp(sBuffer, "\n") != 0)
	{
	  check_option(sBuffer, data->name);
	}
      gtk_text_buffer_delete(pTextBuffer, &iStart, &iEnd);
    }
  else
    myGtkScroll(widget, pTextBuffer);
}

void		place_other(t_myGtk *data)
{
  data->pHidebar = gtk_scrolled_window_new(NULL, NULL);
  gtk_table_attach_defaults(GTK_TABLE(data->pTable),
			    data->pHidebar, 0, 5, 5, 6);
  data->pTextView = gtk_text_view_new();
  gtk_container_add(GTK_CONTAINER(data->pHidebar), GTK_WIDGET(data->pTextView));
  g_signal_connect(G_OBJECT(data->pTextView), "key-press-event",
		   G_CALLBACK(myGtkKeys), (gpointer) data);
}

GSList		*place_objects(GtkWidget *pNotebook, GSList *list, char *name)
{
  t_myGtk	*data;
  GtkWidget	*pTabLabel;

  data = xmalloc(sizeof(struct s_myGtk));
  data->name = name;
  data->pTable = gtk_table_new(2, 2, TRUE);
  pTabLabel = gtk_label_new(name);
  gtk_notebook_append_page(GTK_NOTEBOOK(pNotebook), data->pTable, pTabLabel);
  data->pScrollbar = gtk_scrolled_window_new(NULL, NULL);
  gtk_table_attach_defaults(GTK_TABLE(data->pTable),
			    data->pScrollbar, 0, 4, 0, 5);
  data->ChatBuffer = gtk_text_view_new();
  gtk_text_view_set_editable(GTK_TEXT_VIEW(data->ChatBuffer), FALSE);
  gtk_container_add(GTK_CONTAINER(data->pScrollbar),
		    GTK_WIDGET(data->ChatBuffer));
  data->pScrollbar2 = gtk_scrolled_window_new(NULL, NULL);
  gtk_table_attach_defaults(GTK_TABLE(data->pTable),
			    data->pScrollbar2, 4, 5, 0, 5);
  myGtk_puts("Welcome !\n", data->ChatBuffer, 0, 1);
  data->ContactText = gtk_text_view_new();
  gtk_text_view_set_editable(GTK_TEXT_VIEW(data->ContactText), FALSE);
  gtk_container_add(GTK_CONTAINER(data->pScrollbar2),
		    GTK_WIDGET(data->ContactText));
  myGtk_puts("Contacts :", data->ContactText, 0, 0);
  place_other(data);
  return (g_slist_append(list, (gpointer) data));
}
