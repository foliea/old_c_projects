/*
** list_sudoki.c for sudoki-bi in /u/all/folie_a/public/sudoki
** 
** Made by thibaut ottemer
** Login   <otteme_t@epitech.net>
** 
** Started on  Sat Sep 12 17:38:22 2009 thibaut ottemer
** Last update Sat Sep 12 17:41:34 2009 thibaut ottemer
*/

#include <unistd.h>
#include <stdlib.h>
#include "sudoki-bi.h"

void	my_init_list(t_list *list)
{
  list->begin = NULL;
  list->end = NULL;
  list->taille = 0;
}

void		my_add_tab(t_list *list, char **tab)
{
  t_elem	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    my_put_error("Can't perform malloc\n");
  new->data = tab;
  new->next = NULL;
  if (list->taille == 0)
    {
      list->begin = new;
      list->end = new;
    }
  else
    {
      list->end->next = new;
      list->end = new;
    }
  list->taille++;
}

void		my_show_list_tab(t_list *list)
{
  t_elem	*temp;

  temp = list->begin;
  while (list->begin != NULL)
    {
      my_show_tab(list->begin->data);
      if (list->begin->next != NULL)
	my_putstr("####################\n");
      list->begin = list->begin->next;
    }
  list->begin = temp;
}

void		my_free_list_tab(t_list *list)
{
  t_elem	*temp;

  while (list->begin != NULL)
    {
      temp = list->begin;
      list->begin = list->begin->next;
      my_free_tab(temp->data);
      free(temp);
    }
}
