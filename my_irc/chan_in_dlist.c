/*
** list_utils.c for list_utils in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon May 18 17:48:12 2009 adrien folie
** Last update Wed Apr 28 18:14:21 2010 edern bienvenu
*/

#include <stdlib.h>
#include <sys/select.h>
#include "irc.h"

extern struct s_serv	sdata;

void	my_init_dchan(t_dchan *list)
{
  list->begin = NULL;
  list->end = NULL;
  list->taille = 0;

}

int		my_put_empty_dchan(t_dchan *list, char *name, int fd)
{
  t_channel	*new;
  char		*login;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  my_init_dlist(&(new->users));
  new->name = name;
  login = whois(fd);
  my_put_in_dlist(&(new->users), login, fd, 1);
  new->next = NULL;
  new->prev = NULL;
  list->begin = new;
  list->end = new;
  list->taille++;
  return (0);
}

int		my_put_begin_dchan(t_dchan *list, char *name, int fd)
{
  t_channel	*new;
  char		*login;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->name = name;
  login = whois(fd);
  my_put_in_dlist(&(new->users), login, fd, 1);
  new->next = list->begin;
  new->prev = NULL;
  list->begin->prev = new;
  list->begin = new;
  list->taille++;
  return (0);
}

int		my_put_end_dchan(t_dchan *list, char *name, int fd)
{
  t_channel	*new;
  char		*login;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->name = name;
  login = whois(fd);
  my_put_in_dlist(&(new->users), login, fd, 1);
  new->next = NULL;
  new->prev = list->end;
  list->end->next = new;
  list->end = new;
  list->taille++;
  return (0);
}

int		my_put_in_dchan(t_dchan *list, char *name, int fd, int sort)
{
  int		back;

  back = 1;
  if (name == NULL)
    return (back);
  if (list->taille == 0)
    back = my_put_empty_dchan(list, name, fd);
  else if (sort == 1)
    back = my_put_end_dchan(list, name, fd);
  else
    back = my_put_begin_dchan(list, name, fd);
  return (back);
}
