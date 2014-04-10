/*
** bsq.h for  in /u/all/folie_a/cu/rendu/c/my_getnextline
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Thu Apr 30 05:58:40 2009 adrien folie
** Last update Fri May  8 16:59:04 2009 thibaut ottemer
*/

#ifndef BSQ_H_
# define BSQ_H_

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define TRUE 0
# define FALSE 1

void	my_putchar(char c);
void	check_error_file(char **tab, int i);
void	my_error_report(int error);
int	my_strcmp(char *str1, char *str2);
int	my_strlen(char *str);
int	my_putstr(char *str);
int	my_printf(char *str, ...);
int	xread(const int fd, char *buffer, int size);
int	check_square(char **tab, int pos1, int pos2, int size);
int	my_getnbr(char *nb);
int	my_show_tab(char **tab);
int	my_free_tab(char **tab);
int	my_show_in_colors(char **tab);
char	*xmalloc(int size);
char	*get_next_line(const int fd);
char	*my_strdup(char *str);
char	**my_buffer_to_tab(char **av, int i);
char	**my_transform(char **tab, int pos1, int pos2, int size);
char	**my_square(char **tab, int i, int nb_line, int size);

#endif /* !BSQ_H_ */
