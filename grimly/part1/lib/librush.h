/*
** librush.h for librush in /u/all/folie_a/cu/rendu/rush/grimly/part1/lib
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Fri Nov  6 23:12:06 2009 adrien folie
** Last update Sat Nov  7 01:02:56 2009 adrien folie
*/

#ifndef LIBRUSH_H_
# define LIBRUSH_H_

char		*my_strdup(char *);
char		*my_strcat(char *str1, char *str2);
int		my_getnbr(char *nb);
int		my_strcmp(char *, char *);
int		my_strncmp(char *, char *, int n);
int		my_strlen(char *);
char		*my_strcpy(char *, char *);
int		my_putchar(char);
int		my_putstr(char *);
int		my_swapstr(char **, char **);
void		my_freetab(char **);
void		my_showtab(char **);
int		my_tablen(char **);
char		**my_tabdup(char **);

#endif /* !LIBRUSH_H_ */
