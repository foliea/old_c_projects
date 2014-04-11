/*
** serveur.h for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:09:29 2010 adrien folie
** Last update Mon Jul 12 23:36:17 2010 adrien folie
*/

#ifndef SERVEUR_H
#define SERVEUR_H

#define FD_FREE		0
#define FD_SERVER	1
#define FD_CLIENT	2
#define OPEN_MAX	FD_SETSIZE
#define BUF_SIZE	4096
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
  int			maxfd;
  int			max;
  int			s;
  int			r;
  fd_set		fd_read;
  fd_set		fd_write;
  t_tlist		*map;
  t_tlist		*players;
}			t_env;

void	my_room(t_env *e, int fd);
void	init_env(t_env *e);
void	create_server(t_env *e, int port);
void	loop_select(t_env *e);
void	add_client(t_env *e, int s);
void	do_cmd(char *cmd, t_env *e, int fd);

#endif
