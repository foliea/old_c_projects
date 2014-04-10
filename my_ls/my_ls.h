/*
** my_ls.h for my_ls in /u/all/folie_a/cu/rendu/c/my_ls
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon May 18 17:53:24 2009 adrien folie
** Last update Tue May 26 07:25:59 2009 adrien folie
*/

#ifndef MY_LS_H_
# define MY_LS_H_

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct		s_list
{
    char		*name;
    struct stat		stats;
    struct s_list	*next;
}			t_list;

typedef struct	s_options
{
  int	       	l;
  int	       	a;
  int	       	r;
  int	       	R;
  int	       	d;
  int	       	t;
  int		yes;
  char		*home;
}	       	t_options;

char	*my_strdup_select(char *str, int d, int f);
int	my_list_size(t_list *begin);
void	my_print_type(mode_t st_mode);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_strcmp(char *str1, char *str2);
int	isnot_hidden(char *file);
int	my_printf(char *str, ...);
int	count_blocks(t_list *begin);
int	my_str_is_in(char *str, char *to_find);
char	*my_pwd_dup(char *str, int i, int j);
char	*my_getpwd(char **env);
void	my_swat_str(char *a, char *b);
void	my_putchar(char c);
t_list	*start_read(DIR *dir, t_options option);
int	my_options(t_options *option, char **av, int ac, char **env);
void	my_check_option(char flag, t_options *option);
void	init_option(t_options *option);
void	my_put_in_list(t_list **begin, char *data);
void	insert_by_name(t_list **begin, char *data, struct stat sb);
void	insert_by_time(t_list **begin, char *data, struct stat sb);
void	my_show_list(t_list *begin);
void	my_rev_list(t_list **begin);
void	my_error_report(int error);
void	ls_display(t_list *begin, t_options option);
void	my_free_list(t_list **begin);
t_list	*option_dlist(int ac, char **av, int pos, t_options option);
void	my_print_chmod(mode_t st_mode);
t_list	*my_getlast(t_list *begin);
void	option_d(int ac, char **av, int pos, t_options option);

#endif /* !MY_LS_H_ */
