/*
** ntn.h for ntn in /u/all/folie_a/cu/rendu/c/proj/ntn
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri May 22 22:54:55 2009 adrien folie
** Last update Sun May 24 23:31:09 2009 adrien folie
*/

#ifndef NTN_H_
# define NTN_H_

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_index
{
  char		pos;
  char		*nb;
}		t_index;

int	my_strlen(char *str);
int	my_putstr(char *str);
int	my_getnbr(char *str);
int	my_nblen(unsigned int nb);
int	count_nbr(char *str);
int	ntn_special(char nb1, char nb2);
int	check_limit(char *str, int i, int j);
int	calc(char *str);
char	*xmalloc(int size);
char	*int_to_str(int nombre);
char	**infos_memory(char *str);
char	**recup_infos(char *str);
void	my_error(void);
void	my_error_int(void);
void	check_num(char *str, int i);
void	my_putchar(char c);
void	ntn_display(char *str, int i, int pos);
void	print_dizaine(char c);
int	print_unit(char c);
void	print_special(char c);
void	print_link(char nb1, char nb2);
void	ntn_quatre_vingt(char nb2);
int	ntn_dizaine(char nb1, char nb2);
int	ntn_centaine(char nb0, char nb1, char nb2);
void	ntn_milliards(char c, int j, char *str);
void	ntn_millions(char c, int j, char *str);
int	check_str(int i, char *str);
int	check2_str(int i, char *str);
int	check_str_limit(int i, char *str);
void	etape_int(char *str, int *i, int *pos);
void	ntn_milliers(int i, char *str);
void	check_zero(int pos, char *str, int i);
void	check_maxint(int i, char *str);

#endif /* !NTN_H_ */
