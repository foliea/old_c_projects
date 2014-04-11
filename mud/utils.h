/*
** utils.h for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:11:27 2010 adrien folie
** Last update Thu Jul  8 05:51:16 2010 adrien folie
*/

#ifndef UTILS_H
#define UTILS_H

void	*xmalloc(int size);
void	aff_error(char *str);
void	free_tab(char **tab);
int	tab_len(char **tab);
int	fd_puts(int fd, char *str);
char	**str_to_wordtab(char *str, char sep);

#endif

