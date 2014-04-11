/*
** client.h for  in /u/all/gouesl_a/cu/rendu/my_ftp/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Apr 18 20:45:51 2010 antoine goueslard
** Last update Sun Jun 20 21:13:08 2010 antoine goueslard
*/


#ifndef CLIENT_H
#define CLIENT_H

#include <sys/time.h>

typedef struct s_act
{
  int	fnbr;
  char	*paramc;
  struct timeval timeout;
  struct  s_act *next;
}	t_act;

typedef struct s_fct
{
  char *name;
  t_act	*(*f)(int s, char *to_send, int fnbr, t_act *commands);
} t_fct;

typedef struct s_inv
{
  int	life;
  int	l;
  int	d;
  int	s;
  int   m;
  int	p;
  int	t;
  int	joueurs;
}	t_inv;

typedef struct s_mess
{
  int	from;
  int	dir;
  int	level;
  struct timeval since;
}		t_mess;

typedef struct s_play
{
  char *team;
  int	niveau;
  int	pos;
  int	dir;
  t_inv	inv;
  t_mess mess;
  t_inv	map[82];
}	t_play;


/* included from strlib.c */
void	my_puts(int fd,char *str);
void	my_putstr(char *str);
void	my_putnbr(int i);
void	put_error(char *str);
char	**expand(char **lines, int end, char c);
int	check_word(char *src, char c);
char	*my_copy(char *src, int i);
char	**stotab(char *path, char c);

/* included from mini_next.c */
char *get_next_line(int fd);

/* included from str_tab.c */
char **str_to_tab(char *str);

/* included from timeout.c */
void	check_timeout(int s, struct timeval timeout);
struct timeval		uptimeout(int sec, struct timeval timeout);
int	can_do(int s, t_act *commands);
t_act	*add_commands(int fnbr, char *paramc, int cooldown, t_act *commands);

/* included from move.c */
t_act	*do_avance(int s, char *to_send, int fnbr, t_act *commands);
t_act	*do_droite(int s, char *to_send, int fnbr, t_act *commands);
t_act	*do_gauche(int s, char *to_send, int fnbr, t_act *commands);
t_act	*do_expulse(int s, char *to_send, int fnbr, t_act *commands);
t_act	*do_voir(int s, char *to_send, int fnbr, t_act *commands);

/* included from obj.c */
t_act   *do_prend(int s, char *to_send, int fnbr, t_act *commands);
t_act   *do_pose(int s, char *to_send, int fnbr, t_act *commands);
t_act   *do_inv(int s, char *to_send, int fnbr, t_act *commands);
t_act   *do_fork(int s, char *to_send, int fnbr, t_act *commands);
t_act   *do_inc(int s, char *to_send, int fnbr, t_act *commands);

/* included from get_ans.c */
t_act	*check_ans(char *ans, t_act *commands);

/* included from gere_inv.c */
void	ff_inv(char *ans);
void	ff_los(char *ans);

/*included from broadcast.c */
void	get_message(char *ans);
char	*gen_message(void);
t_act   *do_broad(int s, char *to_send, int fnbr, t_act *commands);

/* included from gnr.c */
char		*gnr(int s);

/* included from ia.c */
char **to_do(int can, t_act *commands);

/* included from do_invoc */
char	**send_elev(int can, char **to_send, int *linv, t_act *commands);

/* included from iamath.c */
int	calc_avance(int pos);
char	**docan(int can, char **to_send, char **tab_do);
char	**new_tab(t_act *commands);
int	is_enough(void);
char	**new_see(int can, int *linv, t_act *commands);

/* included from ia_pierre.c */
char	**caline(char **to_send, int can, int *linv);
char	**cadera(char **to_send, int can, int *linv);
char	**casibu(char **to_send, int can, int *linv);
char	**caphir(char **to_send, int can, int *linv);
char	**catch_pierre(char **to_send, int can, int *linv);

#endif /* CLIENT_H */
