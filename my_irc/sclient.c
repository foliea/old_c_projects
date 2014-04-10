/*
** client.c for my irc in /u/all/bienve_e/rendu/c/my_irc/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 26 14:11:11 2010 edern bienvenu
** Last update Wed Apr 28 19:25:58 2010 edern bienvenu
*/

#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "irc.h"

#define BUFFER 512
void	my_show_dlist(t_dlist *list, int sort);

extern	struct s_serv	sdata;

void		check_option(int fd, char *line)
{
  int		i;
  char		**cmd;

  i = 0;
  cmd = str_to_wordtab(line, ' ');
  while (ind[i].flags != 0)
    {
      if (strcmp(cmd[0], ind[i].flags) == 0)
	{
	  ind[i].f(fd, line);
	  return ;
	}
      i++;
    }
  send_msg(fd, line);
  return ;
}

void		client_read(t_env *e, int fd)
{
  int		res;
  char		*buf;

  buf = malloc(4097);
  res = read(fd, buf, BUFFER);
  if (res > 0)
    check_option(fd, buf);
  else
    {
      my_putnbr(fd);
      my_putstr(": ");
      my_putstr("Connexion closed\n");
      getoff_fd(fd, &(sdata.user));
      getoff_fd_chan(fd);
      close(fd);
      e->fds[fd].type = FD_FREE;
    }
  return ;
}

char	*new_login(char *login, int cs)
{
  login = my_strcat(login, inttostr(cs));
  return (login);
}

void			add_client(t_env *e, int s)
{
  int			cs;
  char			*login;
  struct sockaddr_in	client_sin;
  unsigned int		client_sin_len;

  login = xmalloc(512);
  login = "New_";
  client_sin_len = sizeof(client_sin);
  cs = accept(s, (struct sockaddr *)&client_sin, &client_sin_len);
  login = new_login(login, cs);
  my_put_in_dlist(&(sdata.user), login, cs, 1);
  my_show_dlist(&(sdata.user), 1);
  e->fds[cs].type = FD_CLIENT;
  e->fds[cs].fct_read = client_read;
  e->fds[cs].fct_write = NULL;
}
