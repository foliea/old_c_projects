/*
** minishell.h for minishell.h in /u/all/folie_a/cu/rendu/c/minishell1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Jun  1 17:15:34 2009 adrien folie
** Last update Mon Oct  5 01:54:27 2009 adrien folie
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

#include "dlist.h"

char	*do_epur(char *str, int separator, int opt);
char	*my_strepur2(char *str, int a, int separator);
int	check_bin_list(t_dlist *list, char **env);
int	my_put_error(char *str);
int	do_pipes(t_dlist *list, char ***env);
void	do_alone(t_elem *p, char ***env);
int	one_builtin(char **cmd, char ***env);
void	do_cmd(t_elem *p, char ***env, int cas);
int	check_list(t_dlist *list);
int	redirection_right(t_elem *p, int *i);
int	redirection_left(t_dlist *list, int *i, int *j);
int	old_pwd(char ***env);
int	shlvl_plus(char **env, char *data);
int	my_modenv(char **env, char *line, char *data);
int	my_wordsnbr(char *str, char separator);
int	my_strcmp(char *s1, char *s2);
int	my_strlen(char *str);
int	my_putstr(char *str);
int	my_putnstr(char *str, int n);
int	count_path(char *str);
int	my_str_is_in(char *str, char *to_find);
int	builtins_select(char **cmd, char ***env, int fd_in, int fd_out);
int	my_check_str(char *str);
int	where_is(char *data, char **env);
int	my_tab_len(char **tab);
int	my_setenv(char ***env, char **cmd);
int	my_line_is_in(char ***env, char *line, char **cmd);
char	*my_str_join(char *l1, char *l2);
char	*my_env_var(char *data);
char	*my_line_env(char *l1, char *l2);
char	*xmalloc(int size);
char	*my_path_dup(char *str, int i, int j);
char	*my_getenv(char **env, char *data);
char	*my_strepur(char *str, int a);
char	*my_strdup(char *str);
char	**my_tab_dup(char **tab);
char	**memory(char *str);
char	**mns_recup_bin(char **env);
char	**my_str_to_wordtab(char *str, char separator, int opt);
char	**mns_do_absolute(void);
int	my_unsetenv(char ***env, char **cmd);
void	my_addenv(char ***env, char **cmd, char *line);
void	my_error_report(int error);
int	mns_main(char ***env);
void	my_show_tab(char **tab);
void	my_putchar(char c);
void	my_free_tab(char **tab);
int	my_env(char ***env, char **cmd);
int	my_cd(char ***env, char **cmd);
int	do_cd(char ***env, char **cmd);
void	mns_recup_cmd(char *line, char ***env);
int	mns_sort_cmd(t_dlist *list, char *line);
void	new_pwd(char ***env, char *new);

#endif /* !MINISHELL_H_ */
