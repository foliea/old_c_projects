/*
** client.c for  in /u/all/gouesl_a/cu/rendu/my_ftp/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Apr 18 20:43:24 2010 antoine goueslard
** Last update Sun Jun 20 21:58:32 2010 antoine goueslard
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "client.h"

t_fct  gl_fct[] =
  {
    {"avance", do_avance},
    {"droite", do_droite},
    {"gauche", do_gauche},
    {"expulse", do_expulse},
    {"prend", do_prend},
    {"pose", do_pose},
    {"fork", do_fork},
    {"inv", do_inv},
    {"voir", do_voir},
    {"inc", do_inc},
    {"bro", do_broad},
    {0, 0}
  };

t_play player;

t_act	*client_exec(int s, char *to_send, t_act *commands)
{
  int	i;
  char  **tab;

  i = 0;
  tab = str_to_tab(to_send);
  while ((gl_fct[i].name != 0) && (strcmp(gl_fct[i].name, tab[0])))
    i++;
  if (gl_fct[i].name)
    {
      commands = gl_fct[i].f(s, tab[1], i, commands);
    }
  else
    my_puts(2,"ERROR : UNKNOW COMMAND\n");
  free(tab);
  return (commands);
}

t_act	*check_answers(int s, t_act *commands)
{
  char	**tab;
  int	i;
  char	*buff;

  i = 0;
  if ((buff = gnr(s)) != 0 && strlen(buff) != 0)
    {
      tab = stotab(buff, '\n');
      i = 0;
      while (tab[i] != 0)
	{
	  commands = check_ans(tab[i], commands);
	  i++;
	}
      free(tab);
    }
  free (buff);
  return (commands);
}

void	client_work(int s, t_act *commands)
{
  int	i;
  char *ret;
  char **to_send;

  ret = 0;
  while (42)
    {
      commands = check_answers(s, commands);
      i = can_do(s,commands);
      if (i < 10)
	{
	  to_send = to_do(i, commands);
	  i = 0;
	  while (to_send != 0 && to_send[i] != 0)
	    {
	      my_puts(1, to_send[i]);
	      commands = check_answers(s, commands);
	      commands = client_exec(s, to_send[i], commands);
	      i++;
	    }
	  if (to_send != 0)
	    free(to_send);
	}
    }
}

void	init_player(char *team)
{
  player.team = strdup(team);
  player.inv.life = -1;
  player.niveau = 1;
  player.mess.from = -1;
}

void	init_client(int s, char **av)
{
  char	buff[4096];
  char	**tab;
  char	**tab2;

  init_player(av[3]);
  memset(buff, 0, 4096);
  if ((recv(s, buff, 4096, 0) > 0) &&
      (strcmp(buff,"BIENVENUE\n") == 0))
    my_puts(s, strcat(strdup(player.team),"\n"));
  else
    put_error("Serveur Non Reconnu\n");
  my_puts(2,"Connected\n");
  sleep(1);
  memset(buff, 0, 4096);
  if (!(recv(s, buff, 4096, 0) > 0))
    put_error("Nothing happens\n");
  puts(buff);
  tab = stotab(buff,'\n');
  if (strcmp("ko", tab[0]) == 0 || atoi(tab[0]) < 0 || tab[1] == 0)
    put_error("Serveur problem\n");
  tab2 = stotab(tab[1],' ');
  if (tab2[0] == 0 || atoi(tab2[0]) <= 0 || atoi(tab2[1]) <= 0)
    put_error("Taille de map incoreccte\n");
  my_puts(2,"acces granted\n");
  free(tab);
  free(tab2);
}

int			main(int argc, char **argv)
{
  int                   s;
  struct sockaddr_in    sin;
  struct in_addr        addr;
  struct hostent        *h;
  t_act *commands;
  int                   port;

  commands = NULL;
  if (argc != 4)
    put_error("Usage : ./zap_client [host] [port] [team]\n");
  s = socket(PF_INET, SOCK_STREAM, 0);
  port = atoi(argv[2]);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if (!(h = gethostbyname(argv[1])))
    exit(1);
  bcopy(h->h_addr, &addr, sizeof(addr));
  sin.sin_addr = addr;
  if (connect(s, (struct sockaddr *)&sin, sizeof(struct sockaddr_in)) == -1)
    my_putstr("Connexion problem\n");
  init_client(s, argv);
  client_work(s, commands);
  close(s);
  return (0);
}
