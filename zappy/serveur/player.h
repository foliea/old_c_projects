/*
** player.h for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Thu Jun 17 02:12:56 2010 edern bienvenu
** Last update Sun Jun 20 19:18:35 2010 edern bienvenu
*/

#ifndef PLAYER_H
#define PLAYER_H

#define FOOD		0
#define LINEMATE	1
#define DERAUMERE	2
#define SIBUR		3
#define MENDIANE	4
#define PHIRAS		5
#define THYSTAME	6

#define UP		0
#define DOWN		1
#define LEFT		2
#define RIGHT		3

typedef struct		s_player
{
  int			fd;
  int			direct;
  int			posx;
  int			posy;
  int			inv[7];
  int			lvl;
  int			eggx;
  int			eggy;
  struct s_player	*next;
  struct s_player	*prev;
}			t_player;

typedef struct		s_dteam
{
  struct s_player	*begin;
  struct s_player	*end;
  int			taille;
}			t_dteam;

typedef struct	s_teams
{
  char		*name;
  t_dteam	*data;
  int		nb_clients;
}		t_teams;

int	begin_elevation(__attribute__ ((unused)) char *cmd, int fd);
int	connect_nbr(char *cmd, int fd);
void	my_init_dteam(t_dteam *team);
void	my_put_in_dteam(t_dteam *team, int fd, int sort);
void	do_avance(char *cmd, t_player *player, int fd);
void	do_droite(char *cmd, t_player *player, int fd);
void	do_gauche(char *cmd, t_player *player, int fd);
void	do_voir(char *cmd, t_player *player, int fd);
void	do_inventaire(char *cmd, t_player *player, int fd);
void	do_get(char *cmd, t_player *player, int fd);
void	do_set(char *cmd, t_player *player, int fd);
void	do_broadcast(char *cmd, t_player *player, int fd);
void	do_fork(char *cmd, t_player *player, int fd);
void	do_elevation(char *cmd, t_player *player, int fd);
void	do_expulse(char *cmd, t_player *player, int fd);
void	do_mort(char *cmd, t_player *player, int fd);

typedef struct	s_commande
{
  char		*cmd;
  void		(*f)();
}		t_commande;

static const t_commande	action[] =
  {
    {"avance\n", do_avance},
    {"droite\n", do_droite},
    {"gauche\n", do_gauche},
    {"voir\n", do_voir},
    {"inventaire\n", do_inventaire},
    {"prend ", do_get},
    {"pose ", do_set},
    {"expulse\n", do_expulse},
    {"broadcast ", do_broadcast},
    {"incantation\n", do_elevation},
    {"fork\n", do_fork},
    {"mort\n", do_mort},
    {0, 0}
  };

t_player	*get_player(t_teams *teams, int fd);
void		set_func_to_player(int fd, void *data, void (*f)());
void		send_player(t_dteam *team, int fd, void *data, void (*f)());
void		avance_expulse(__attribute__((unused)) int fd, 
			       void *data, t_player *player);

#endif
