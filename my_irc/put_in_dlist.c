/*
** list_utils.c for list_utils in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon May 18 17:48:12 2009 adrien folie
** Last update Wed Apr 28 18:13:20 2010 edern bienvenu
*/

#include <stdlib.h>
#include <sys/select.h>
#include "irc.h"

void	my_init_dlist(t_dlist *list)
{
  list->begin = NULL;
  list->end = NULL;
  list->taille = 0;
}

int		my_put_empty_dlist(t_dlist *list, char *login, int fd)
{
  t_client	*new;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->login = login;
  new->fd = fd;
  new->next = NULL;
  new->prev = NULL;
  list->begin = new;
  list->end = new;
  list->taille++;
  return (0);
}

int		my_put_begin_dlist(t_dlist *list, char *login, int fd)
{
  t_client	*new;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->login = login;
  new->fd = fd;
  new->next = list->begin;
  new->prev = NULL;
  list->begin->prev = new;
  list->begin = new;
  list->taille++;
  return (0);
}

int		my_put_end_dlist(t_dlist *list, char *login, int fd)
{
  t_client	*new;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->login = login;
  new->fd = fd;
  new->next = NULL;
  new->prev = list->end;
  list->end->next = new;
  list->end = new;
  list->taille++;
  return (0);
}

int		my_put_in_dlist(t_dlist *list, char *login, int fd, int sort)
{
  int		back;

  back = 1;
  if (login == NULL)
    return (back);
  if (list->taille == 0)
    back = my_put_empty_dlist(list, login, fd);
  else if (sort == 1)
    back = my_put_end_dlist(list, login, fd);
  else
    back = my_put_begin_dlist(list, login, fd);
  return (back);
}
