/*
** window.h for gtk in /u/all/folie_a/cu/test/gtk
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Apr 26 15:35:27 2010 adrien folie
** Last update Sun Dec  5 11:52:19 2010 adrien folie
*/

#ifndef WINDOW_H
#define WINDOW_H

#define KEY_ENTER 65293
#define NUM_ENTER 65421

#include <gtk/gtk.h>

typedef struct	s_myGtk
{
  char		*name;
  GtkWidget	*pTable;
  GtkWidget	*pScrollbar;
  GtkWidget	*pScrollbar2;
  GtkWidget	*pHidebar;
  GtkWidget	*pTextView;
  GtkWidget	*ContactText;
  GtkWidget	*ChatBuffer;
}		t_myGtk;

typedef struct	s_Window
{
  GtkWidget	*pWindow;
  GtkWidget	*pNotebook;
  GtkWidget	*pVBox;
  GSList	*begin;
}		t_Window;

int	tablen(char **t);
int	channel_exist(GSList *list, char *channel);
char	*my_strcat(char *str1, char *str2);
char	**str_to_wordtab(char *str, char separator);
char	**client_connect(char *cmd);
void	server_read(void);
void	write_on_screen(GSList *list, char *channel, char *msg, int LineReturn);
void	write_on_contacts(GSList *list, char *channel, char *msg);
void	send_msg(int s, char *line, char *channel);
void	check_option(char *line, char *channel);
void	myGtk_puts(gchar *sBuffer, GtkWidget *Text, int LineReturn, int WindowScrollEnd);
void	*xmalloc(int size);
GSList	*place_objects(GtkWidget *pNotebook, GSList *list, char *name);

#endif
