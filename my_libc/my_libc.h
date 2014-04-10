/*
** my.h for my_header in /u/all/folie_a/cu/rendu/lib/my
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Mar 20 11:19:09 2009 adrien folie
** Last update Fri Mar 20 22:01:28 2009 adrien folie
*/

#ifndef __MY_H__
#define __MY_H__
void	my_putchar(char c);
int	my_isneg(int n);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int     my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_revstr(char *str);  
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
char	*my_strcat(char *str1, char *str2);
char	*my_strncat(char *str1, char *str2, int n);
int	my_strlcat(char *str1, char *str2, int n);
int	my_square_root(int nb);
char	*my_strdup(char *str);
char	**my_str_to_wordtab(char *str);
#endif
