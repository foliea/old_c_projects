/*
** dlist.h for dlist in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Jun 14 19:09:46 2009 adrien folie
** Last update Mon Sep 28 13:57:03 2009 adrien folie
*/

#ifndef DLIST_H_
# define DLIST_H_

typedef struct		s_elem
{
    char		**data;
    char		*s;
    struct s_elem	*next;
    struct s_elem	*prev;
}			t_elem;

typedef struct		s_dlist
{
    struct s_elem	*begin;
    struct s_elem	*end;
    int			taille;
}			t_dlist;

int	my_getnbr(char *str);
void	aff_lists(t_dlist *list_a, t_dlist *list_b);
void	my_init_dlist(t_dlist *list);
void	my_put_empty_dlist(t_dlist *list, char **data, char *s);
void	my_put_begin_dlist(t_dlist *list, char **data, char *s);
void	my_put_end_dlist(t_dlist *list, char **data, char *s);
void	my_put_in_dlist(t_dlist *list, char **data, char *s, int sort);
void	my_show_begin_dlist(t_dlist *list);
void	my_show_end_dlist(t_dlist *list);
void	my_show_dlist(t_dlist *list, int sort);
void	my_free_dlist(t_dlist *list);

#endif /* !DLIST_H_ */
