/*
** sudoki-bi.h for sudoki-bi in /u/all/folie_a/public/sudoki
**
** Made by thibaut ottemer
** Login   <otteme_t@epitech.net>
**
** Started on  Sat Sep 12 11:05:26 2009 thibaut ottemer
** Last update Sun Sep 13 20:14:50 2009 adrien folie
*/

#ifndef SUDOKI_H_
# define SUDOKI_H_

#define TRUE 0
#define FALSE -1

typedef struct		s_elem
{
  char			**data;
  struct s_elem		*next;
}			t_elem;

typedef struct		s_list
{
  struct s_elem		*begin;
  struct s_elem		*end;
  int			taille;
}			t_list;

typedef struct		s_pos
{
    char		*str;
}			t_pos;

t_pos	**pos_init(void);
void	init_case(t_pos *line);
void	loop_check_nb(char **tab, t_pos **pos, int x, int y);
void	loop_check(char **tab, t_pos **pos);
void	my_putchar(char c);
void	*xmalloc(int size);
void	test_loop(char **tab);
void	my_put_error(char *str);
int	loop_main(char **tab, int x, int y);
void	my_init_list(t_list *list);
void	my_add_tab(t_list *list, char **tab);
void	my_show_list_tab(t_list *list);
void	my_free_list_tab(t_list *list);
int	loop_search(char **tab, t_pos **pos);
int	do_checks(char **tab, int x, int y, char nb);
int	loop_nb(char **tab, int x, int y, char *str);
int	my_putstr(char *str);
int	my_putnstr(char *str, int n);
int	my_show_tab(char **tab);
int	my_strlen(char *str);
int	my_free_tab(char **tab);
int	check_case(char **tab, char nb, int x, int y);
int	loop_human(char **tab, t_pos **pos);
char	*my_strdup(char *str);
char	**recup_grille(int *ok);

#endif /* !SUDOKI_H_ */
