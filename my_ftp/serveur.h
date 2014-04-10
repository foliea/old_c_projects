/*
** client.h for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr  6 17:11:49 2010 adrien folie
** Last update Sun Apr 18 03:23:12 2010 adrien folie
*/

#ifndef SERVEUR_H
#define SERVEUR_H

void	serveur_cd(char **cmd, int cs);
void	serveur_pwd(char **cmd, int cs);
void	serveur_ls(char **cmd, int cs);
char	**str_to_wordtab(char *str, char sep);
void	my_freetab(char **tab);
void	serveur_cmd(char *line, int cs, char *path);
void	put_file(char **cmd, int cs);
void	get_file(char **cmd, int cs);
void	aff_error(char *str);
int	my_putstr(char *str);
int	my_tablen(char **tab);
void	*xmalloc(int size);
int	xwrite(int d, const void *buf, size_t nbytes);
int	xread(const int fd, char *buffer, int size);

#endif
