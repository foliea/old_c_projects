/*
** do_cmd.c for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 01:13:01 2010 adrien folie
** Last update Tue Jul 13 03:20:24 2010 adrien folie
*/

#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
#include "tlist.h"
#include "cbuff.h"
#include "player.h"
#include "serveur.h"
#include "cmd.h"
#include "utils.h"
#include "room.h"
#include "things.h"
#include "remove.h"

typedef struct	s_commande
{
  char		*cmd;
  void		(*f)();
}		t_commande;

static const t_commande	action[] =
  {
    {"north\n", do_nord},
    {"south\n", do_sud},
    {"east\n", do_est},
    {"west\n", do_ouest},
    {"speak ", do_speak},
    {"shout ", do_shout},
    {"take food\n", do_food},
    {"take ", do_take},
    {"drop ", do_drop},
    {"voir\n", do_voir},
    {"inv\n", do_inv},
    {"room\n", do_room},
    {"life\n", do_life},
    {0,0}
  };

void	do_death(t_env *e, int fd)
{
  e->fds[fd].type = FD_FREE;
  close(fd);
  ret_player(e->players, fd);
  printf("\033[0;33m** Deconnexion from %d (mort) **\033[0;0m\n", fd);
}

void	do_life(__attribute__((unused))char *cmd, t_env *e, int fd)
{
  t_player	*player;
  t_cbuff	*cwrite;
  int		i;

  if ((player = get_player(e->players, fd)) == NULL)
    return ;
  if ((cwrite = choose_buffer(e->players, fd, CWRITE)) == NULL)
    return ;
  stack_write(cwrite, "Points d'action restants : ");
  i = 0;
  while (i < (player->life - 1))
    {
      stack_write(cwrite, "|");
      ++i;
    }
  stack_write(cwrite, "\n");
  FD_SET(fd, &e->fd_write);
  FD_CLR(fd, &e->fd_read);
}

void		do_invalid(t_env *e, int fd)
{
  t_player	*player;
  t_cbuff	*cwrite;

  if ((player = get_player(e->players, fd)) == NULL)
    return ;
  if ((cwrite = choose_buffer(e->players, fd, CWRITE)) == NULL)
    return ;
  stack_write(cwrite, "Cette requete n'existe pas\n");
  FD_SET(fd, &e->fd_write);
  FD_CLR(fd, &e->fd_read);
}

void		do_cmd(char *cmd, t_env *e, int fd)
{
  int		j;
  t_player	*player;

  j = 0;
  while (action[j].cmd != 0)
    {
      if ((strncmp(cmd, action[j].cmd, strlen(action[j].cmd))) == 0)
        {
          action[j].f(cmd, e, fd);
	  player = get_player(e->players, fd);
	  if (player != NULL)
	    {
	      player->life--;
	      if (player->life == 0)
		do_death(e, fd);
	    }
          return ;
        }
      j++;
    }
  do_invalid(e, fd);
}
