/*
** client.h for my irc in /u/all/bienve_e/rendu/c/my_irc/client
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 26 15:26:13 2010 edern bienvenu
** Last update Wed Apr 28 20:00:36 2010 adrien folie
*/

#ifndef CLIENT_H
#define CLIENT_H

typedef struct	s_client
{
  char		*login;
  char		*line;
}		t_client;

int	join_chan(int s, char *cmd);
int	connection(int s, char *cmd);
int	aconnec(int s, char *cmd);
int	who_chan(int s, char *cmd);
int	res_who(int s, char *cmd);
int	nick(int s, char *cmd);
int	receive_msg(int s, char *cmd);

typedef struct	s_flags
{
  char		*flags;
  int		(*f)();
}		t_flags;

static const t_flags ind[] =
{
  {"/join", join_chan},
  {"/who", who_chan},
  {"/rwho", res_who},
  {"/nick", nick},
  {"/connect", aconnec},
  {"/msg", receive_msg},
  {0,0}
};

/*---- Xfunctions ----*/

int	xopen(char *path, int flag);
void	*xmalloc(int size);
int	xread(int fd, void *buf, int bytes);
int	xread(int fd, void *buf, int bytes);

/*---- Utils ----*/

void	my_putstr(char *str);
int	my_strlen(char *str);
void	my_putchar(char c);
void	my_putnbr(int nb);
int	aff_error(char *str);
char	*get_next_line(const int fd);

#endif
