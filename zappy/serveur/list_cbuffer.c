/*
** list_player.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Tue Jun  1 16:40:50 2010 edern bienvenu
** Last update Wed Jun 16 02:18:05 2010 edern bienvenu
*/

#include <stdlib.h>
#include <sys/select.h>
#include "serveur.h"
#include "cbuff.h"

void	my_init_dcircular(t_dcircular *list)
{
  list->begin = NULL;
  list->end = NULL;
  list->taille = 0;
}

int		my_put_empty_dcircular(t_dcircular *list, int fd)
{
  t_circular	*new;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->fd = fd;
  new->cbuff = xmalloc(sizeof(struct s_cbuff));
  init_cbuff(new->cbuff);
  new->next = NULL;
  new->prev = NULL;
  list->begin = new;
  list->end = new;
  list->taille++;
  return (0);
}

int		my_put_begin_dcircular(t_dcircular *list, int fd)
{
  t_circular	*new;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->fd = fd;
  new->cbuff = xmalloc(sizeof(struct s_cbuff));
  init_cbuff(new->cbuff);
  new->next = list->begin;
  new->prev = NULL;
  list->begin->prev = new;
  list->begin = new;
  list->taille++;
  return (0);
}

int		my_put_end_dcircular(t_dcircular *list, int fd)
{
  t_circular	*new;

  new = xmalloc(sizeof(*new));
  if (new == NULL)
    return (1);
  new->fd = fd;
  new->cbuff = xmalloc(sizeof(struct s_cbuff));
  init_cbuff(new->cbuff);
  new->next = NULL;
  new->prev = list->end;
  list->end->next = new;
  list->end = new;
  list->taille++;
  return (0);
}

int		my_put_in_dcircular(t_dcircular *list,
				    int fd,
				    int sort)
{
  int		back;

  back = 1;
  if (list->taille == 0)
    back = my_put_empty_dcircular(list, fd);
  else if (sort == 1)
    back = my_put_end_dcircular(list, fd);
  else
    back = my_put_begin_dcircular(list, fd);
  return (back);
}
