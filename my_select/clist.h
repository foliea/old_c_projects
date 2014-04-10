/*
** dlist.h for dlist in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Jun 14 19:09:46 2009 adrien folie
** Last update Tue Jul  7 16:49:35 2009 adrien folie
*/

#ifndef CLIST_H_
#define CLIST_H_

typedef struct		s_elem
{
    char		*data;
    int			s;
    struct s_elem	*next;
    struct s_elem	*prev;
}			t_elem;

typedef struct		s_clist
{
    struct s_elem	*begin;
    struct s_elem	*end;
    int			taille;
}			t_clist;

char	*my_strdup(char *str);
void	my_init_clist(t_clist *list);
void	my_put_empty_clist(t_clist *list, char *data);
void	my_put_begin_clist(t_clist *list, char *data);
void	my_put_end_clist(t_clist *list, char *data);
void	my_put_in_clist(t_clist *list, char *data, int sort);
void	my_show_begin_clist(t_clist *list);
void	my_show_end_clist(t_clist *list);
void	my_show_clist(t_clist *list, int sort);
void	my_free_clist(t_clist *list);

#endif /* !CLIST_H_ */
