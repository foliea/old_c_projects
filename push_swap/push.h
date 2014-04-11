/*
** push.h for push in /u/all/folie_a/cu/rendu/c/push_swap
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Jun 14 19:10:47 2009 adrien folie
** Last update Fri Jul  3 11:01:18 2009 thibaut ottemer
*/

#ifndef PUSH_H_
# define PUSH_H_

#include "dlist.h"

int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_isnum(char *str);
int	params_pos(int ac, char **av);
int	my_param_select(char *param, t_dlist *l_a, t_dlist *l_b);
int	my_strcmp(char *s1, char *s2);
char	*my_strdup(char *str);
void	*xmalloc(char *str);
void	push_main(int ac, char **av);
void	my_putchar(char c);
void	my_a_to_b(t_dlist *a, t_dlist *b);
void	my_pb(t_dlist *l_a, t_dlist *l_b);
void	my_pa(t_dlist *l_a, t_dlist *l_b);
void	my_swap_first(t_dlist *list);
void	my_ss(t_dlist *l_a, t_dlist *l_b);
void	my_sa(t_dlist *l_a, t_dlist *l_b);
void	my_sb(t_dlist *l_a, t_dlist *l_b);
void	my_rotate_begin(t_dlist *list);
void	my_rr(t_dlist *l_a, t_dlist *l_b);
void	my_ra(t_dlist *l_a, t_dlist *l_b);
void	my_rb(t_dlist *l_a, t_dlist *l_b);
void	my_rotate_end(t_dlist *list);
void	my_rrr(t_dlist *l_a, t_dlist *l_b);
void	my_rra(t_dlist *l_a, t_dlist *l_b);
void	my_rrb(t_dlist *l_a, t_dlist *l_b);

#endif /* !PUSH_H_ */
