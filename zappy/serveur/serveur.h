/*
** serveur.h for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 28 21:22:00 2010 adrien folie
** Last update Tue Jul  5 16:32:23 2011 adrien folie
*/

#ifndef SERVEUR_H
#define SERVEUR_H

#define FD_FREE		0
#define FD_SERVER	1
#define FD_CLIENT	2

#define BUF_SIZE	4096
#define OPEN_MAX	1024
#define USAGE		"Usage: %s port\n"
#define MAX(a,b)       ((a > b) ? a : b)


typedef struct	s_fd
{
  int		type;
  void		(*fct_read)();
  void		(*fct_write)();
  char		buf_read[BUF_SIZE + 1];
  char		buf_write[BUF_SIZE + 1];
}		t_fd;

typedef struct		s_env
{
  t_fd			*fds;
  int			port;
  int			maxfd;
  int			max;
  int			r;
  int			t;
  fd_set		fd_read;
  fd_set		fd_write;
}			t_env;

/*---- functions ----*/

void	aff_error(char *str);
void	add_client(t_env *e, int s);
void	*xmalloc(int size);
void	find_cmd(char *act, int fd);
void	init_env(t_env *e);
void	loop_select(t_env *e);
void	init_option(t_env *e);
void	aff_parsing(t_env *e);
void	parse_opt(char **av, t_env *e);

#endif
