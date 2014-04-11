/*
** gen.h for gen in /u/all/folie_a/cu/rendu/rush/grimly/part2
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun Nov  8 15:07:30 2009 adrien folie
** Last update Sun Nov  8 22:55:25 2009 adrien folie
*/

#ifndef GEN_H_
# define GEN_H_

typedef struct	s_option
{
    int		w;
    int		h;
    char	dd;
    char	wall;
    char	enter;
    char	exit;
    char	vide;
    int		nb_exit;
    int		min_w;
    int		max_w;
    int		mcn;
}		t_option;

void	opt_height(t_option *opt, int *i, int ac, char **av);
void	opt_width(t_option *opt, int *i, int ac, char **av);
void	do_options(t_option *opt, int ac, char **av);
void	opt_marie(t_option *opt, int *i, int ac, char **av);
void	opt_celine(t_option *opt, int *i, int ac, char **av);
void	opt_noelie(t_option *opt, int *i, int ac, char **av);
void	opt_gate(t_option *opt, int *i, int ac, char **av);
void	do_lab(t_option *opt);
void	way_ext(t_option *opt, char **map);
void	place_random(t_option *opt, char **map);
void	finish_map(t_option *opt, char **map);
void	opt_wall(t_option *opt, int *i, int ac, char **av);
int	my_put_error(char *str);
int	my_put_nbr(int nb);
char	**str_to_wordtab(char *str, char sep);

#endif /* !GEN_H_ */
