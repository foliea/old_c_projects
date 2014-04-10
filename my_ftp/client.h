/*
** client.h for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr  6 17:11:49 2010 adrien folie
** Last update Sun Apr 18 03:23:06 2010 adrien folie
*/

#ifndef CLIENT_H
#define CLIENT_H

void	client_cd(char **cmd, int s);
void	client_pwd(char **cmd, int s);
void	client_ls(char **cmd, int s);
char	**str_to_wordtab(char *str, char sep);
void	my_freetab(char **tab);
void	client_cmd(char *line, int s);
void	put_files(char **cmd, int s);
void	get_files(char **cmd, int s);
void	aff_error(char *str);
int	my_putstr(char *str);
int	my_tablen(char **tab);
void	*xmalloc(int size);
int	xwrite(int d, const void *buf, size_t nbytes);
int	xread(const int fd, char *buffer, int size);

#endif
