/*
** list_utils.c for list_utils in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon May 18 17:48:12 2009 adrien folie
** Last update Fri May 22 01:17:49 2009 adrien folie
*/

#include <stdlib.h>
#include "my_ls.h"

void		insert_by_name(t_list **begin, char *data, struct stat sb)
{
  t_list	*temp;
  t_list	*curs;
  t_list	*new;

  temp = NULL;
  curs = *begin;
  new = malloc(sizeof(*new));
  if (new == NULL)
    exit(EXIT_FAILURE);
  new->name = data;
  new->stats = sb;
  while((curs != 0) && (my_strcmp(curs->name, data) < 0))
    {
      temp = curs;
      curs = curs->next;
    }
  new->next = curs;
  if (temp != NULL)
    temp->next = new;
  else
    *begin = new;
}

void		insert_by_time(t_list **begin, char *data, struct stat sb)
{
  t_list	*temp;
  t_list	*curs;
  t_list	*new;

  temp = NULL;
  curs = *begin;
  new = malloc(sizeof(*new));
  if (new == NULL)
    exit(EXIT_FAILURE);
  new->name = data;
  new->stats = sb;
  while((curs != 0) && sb.st_mtime < curs->stats.st_mtime)
    {
      temp = curs;
      curs = curs->next;
    }
  new->next = curs;
  if (temp != NULL)
    temp->next = new;
  else
    *begin = new;
}

t_list	*my_getlast(t_list *begin)
{
  while (begin != 0 && begin->next != 0)
    begin = begin->next;
  return (begin);
}

void	my_rev_list(t_list **begin)
{
  t_list	*last;
  t_list	*temp;
  t_list	*cur;

  last = my_getlast(*begin);
  temp = last;
  cur = (*begin);
  while ((cur->next)->next != 0)
    {
      last = my_getlast(*begin);
      while (cur->next != last)
        cur = cur->next;
      last->next = cur;
      cur->next = 0;
      cur = (*begin);
    }
  cur->next->next = cur;
  cur->next = 0;
  (*begin) = temp;
}

void		my_free_list(t_list **begin)
{
  t_list	*temp;

  while ((*begin)->next != 0)
    {
      temp = *begin;
      (*begin) = (*begin)->next;
      free(temp);
    }
  free(*begin);
}
