/*
** my_show_dlist.c for 42 in /u/all/jacque_c/public/42sh/1_leo/lexer/lexer
** 
** Made by leo lopez
** Login   <lopez_l@epitech.net>
** 
** Started on  Mon Nov 30 11:43:38 2009 leo lopez
** Last update Wed Apr 28 18:16:45 2010 edern bienvenu
*/

#include <unistd.h>
#include "irc.h"

void	my_show_dlist(t_dlist *list, int sort);

void		my_show_end_dchan(t_dchan *list)
{
  t_channel	*temp;

  temp = list->end;
  while (list->end != NULL)
    {
      my_putstr(list->end->name);
      my_putchar('\n');
      list->end = list->end->prev;
    }
  list->end = temp;
}

void		my_show_begin_dchan(t_dchan *list)
{
  t_channel	*temp;

  temp = list->begin;
  while (list->begin != NULL)
    {
      my_putstr(list->begin->name);
      my_putchar('\n');
      my_show_dlist(&(list->begin->users), 1);
      list->begin = list->begin->next;
    }
  list->begin = temp;
}

void	my_show_dchan(t_dchan *list, int sort)
{
  if (sort == 1)
    my_show_begin_dchan(list);
  else
    my_show_end_dchan(list);
}
