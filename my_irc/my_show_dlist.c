/*
** my_show_dlist.c for 42 in /u/all/jacque_c/public/42sh/1_leo/lexer/lexer
** 
** Made by leo lopez
** Login   <lopez_l@epitech.net>
** 
** Started on  Mon Nov 30 11:43:38 2009 leo lopez
** Last update Tue Apr 27 22:35:02 2010 edern bienvenu
*/

#include <unistd.h>
#include "irc.h"

void		my_show_end_dlist(t_dlist *list)
{
  t_client        *temp;

  temp = list->end;
  while (list->end != NULL)
    {
      my_putstr(list->end->login);
      my_putstr("\t\t");
      my_putnbr(list->end->fd);
      my_putchar('\n');
      list->end = list->end->prev;
    }
  list->end = temp;
}

void		my_show_begin_dlist(t_dlist *list)
{
  t_client	*temp;

  temp = list->begin;
  while (list->begin != NULL)
    {
      my_putstr(list->begin->login);
      my_putstr("\t\t");
      my_putnbr(list->begin->fd);
      my_putchar('\n');
      list->begin = list->begin->next;
    }
  list->begin = temp;
}

void	my_show_dlist(t_dlist *list, int sort)
{
  if (sort == 1)
    my_show_begin_dlist(list);
  else
    my_show_end_dlist(list);
}
