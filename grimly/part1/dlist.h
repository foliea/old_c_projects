/*
** dlist.h for dlist in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Jun 14 19:09:46 2009 adrien folie
** Last update Sat Nov  7 03:16:38 2009 adrien folie
*/

#ifndef DLIST_H_
# define DLIST_H_

typedef struct		s_elem
{
    int			x;
    int			y;
    struct s_elem	*next;
    struct s_elem	*prev;
}			t_elem;

typedef struct		s_dlist
{
    struct s_elem	*begin;
    struct s_elem	*end;
    int			taille;
}			t_dlist;

char	*my_strdup(char *str);
int	my_getnbr(char *str);
void	my_init_dlist(t_dlist *list);
int	my_put_empty_dlist(t_dlist *list, int x, int y);
int	my_put_begin_dlist(t_dlist *list, int x, int y);
int	my_put_end_dlist(t_dlist *list, int x, int y);
void	my_put_in_dlist(t_dlist *list, int x, int y, int sort);
void	my_show_begin_dlist(t_dlist *list);
void	my_show_end_dlist(t_dlist *list);
void	my_show_dlist(t_dlist *list, int sort);
void	my_free_dlist(t_dlist *list);

#endif /* !DLIST_H_ */
