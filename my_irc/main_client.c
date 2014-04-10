/*
** main_client.c for my_irc in /u/all/folie_a/cu/test/gtk
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Apr 28 01:09:19 2010 adrien folie
** Last update Wed Apr 28 10:15:38 2010 adrien folie
*/

#include <stdlib.h>
#include <gtk/gtk.h>
#include "window.h"

struct s_Window	Wdata;
int		serveur_socket;

int	main(int argc, char **argv)
{
  gtk_init(&argc, &argv);
  Wdata.pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(Wdata.pWindow), 640, 480);
  gtk_window_set_title(GTK_WINDOW(Wdata.pWindow), "my_irc");
  g_signal_connect(G_OBJECT(Wdata.pWindow), "destroy",
                   G_CALLBACK(gtk_main_quit), NULL);
  Wdata.pNotebook = gtk_notebook_new();
  Wdata.pVBox = gtk_vbox_new(FALSE, 0);
  gtk_box_pack_start(GTK_BOX(Wdata.pVBox), Wdata.pNotebook, TRUE, TRUE, 0);
  gtk_notebook_set_tab_pos(GTK_NOTEBOOK(Wdata.pNotebook), GTK_POS_TOP);
  gtk_notebook_set_scrollable(GTK_NOTEBOOK(Wdata.pNotebook), TRUE);
  gtk_container_add(GTK_CONTAINER(Wdata.pWindow), Wdata.pVBox);
  Wdata.begin = NULL;
  Wdata.begin = place_objects(Wdata.pNotebook, Wdata.begin, "Main");
  gtk_idle_add((GtkFunction) server_read, NULL);
  gtk_widget_show_all(Wdata.pWindow);
  gtk_main();
  return (0);
}
