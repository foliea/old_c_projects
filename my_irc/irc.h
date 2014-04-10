/*
** irc.h for irc in /u/epitech_2013/bienve_e/cu/rendu/c/my_irc
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 19 16:13:09 2010 edern bienvenu
** Last update Sun Dec  5 11:50:07 2010 adrien folie
*/

#ifndef __IRC__
#define __IRC__

#define FD_FREE		0
#define FD_SERVER	1
#define FD_CLIENT	2

#define BUF_SIZE	4096
#define OPEN_MAX	512
#define USAGE		"Usage: %s port\n"
#define MAX(a,b)       ((a > b) ? a : b)

#include <sys/time.h>
#include <sys/types.h>

typedef struct	s_fd
{
  int		type;
  void		(*fct_read)();
  void		(*fct_write)();
  char		buf_read[BUF_SIZE + 1];
  char		buf_write[BUF_SIZE + 1];
}		t_fd;

typedef struct		s_client
{
  char			*login;
  int			fd;
  struct s_client	*next;
  struct s_client	*prev;
}			t_client;

typedef struct		s_dlist
{
    struct s_client	*begin;
    struct s_client	*end;
    int			taille;
}			t_dlist;

void	my_init_dlist(t_dlist *list);
int	my_put_empty_dlist(t_dlist *list, char *login, int fd);
int	my_put_begin_dlist(t_dlist *list, char *login, int fd);
int	my_put_end_dlist(t_dlist *list, char *login, int fd);
int	my_put_in_dlist(t_dlist *list, char *login, int fd, int sort);

typedef struct		s_channel
{
  char			*name;
  t_dlist		users;
  struct s_channel	*next;
  struct s_channel	*prev;
}			t_channel;

typedef struct		s_dchan
{
    struct s_channel	*begin;
    struct s_channel	*end;
    int			taille;
}			t_dchan;

void	my_init_dchan(t_dchan *list);
int	my_put_empty_dchan(t_dchan *list, char *login, int fd);
int	my_put_begin_dchan(t_dchan *list, char *login, int fd);
int	my_put_end_dchan(t_dchan *list, char *login, int fd);
int	my_put_in_dchan(t_dchan *list, char *login, int fd, int sort);
int	verif_chan(char *name, int fd);
int	send_msg(int s, char *cmd);
int	join_chan(int s, char *cmd);
int	who_chan(int s, char *cmd);
int	whisper(int s, char *cmd);
int	nick(int s, char *cmd);

typedef struct	s_flags
{
  char		*flags;
  int		(*f)();
}		t_flags;

static const t_flags ind[] =
{
  {"/join", join_chan},
  {"/who", who_chan},
  {"/nick", nick},
  {0,0}
};

typedef struct		s_serv
{
  struct s_dlist	user;
  struct s_dchan	chan;
}			t_serv;

typedef struct		s_env
{
  t_fd			*fds;
  int			port;
  int			maxfd;
  int			max;
  int			r;
  fd_set		fd_read;
  fd_set		fd_write;
}			t_env;

/*---- Initialisation ----*/

void	init_env(t_env *e);

/*--- Functions Client ----*/

void	client_read(t_env *e, int fd);
void	add_client(t_env *e, int s);

/*---- Functions Server ----*/

void	server_read(t_env *e, int fd);
void	add_server(t_env *e);
void	loop(t_env *e);
char	*inttostr(int nb);
void	getoff_fd(int fd, t_dlist *list);
void	getoff_fd_chan(int fd);
char	**str_to_wordtab(char *line, char sep);
char	*whois(int fd);
void	send_msg_all(char *msg, char *name);

/*---- Xfunctions ----*/

int	xopen(char *path, int flag);
void	*xmalloc(int size);
int	xread(int fd, void *buf, int bytes);

/*---- Utils ----*/

void	my_putstr(char *str);
int	my_strlen(char *str);
int	tablen(char **cmd);
void	my_putchar(char c);
char	*my_strcat(char *str1, char *str2);
void	my_putnbr(int nb);
void	aff_err(char *str);

#endif
