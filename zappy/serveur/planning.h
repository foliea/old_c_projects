/*
** planning.h for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Sat May 29 00:59:04 2010 adrien folie
** Last update Sun Jun 20 18:46:18 2010 edern bienvenu
*/

#ifndef PLANNING_H
#define PLANNING_H

typedef struct		s_telem
{
  struct timeval	*end;
  int			fd;
  char			*cmd;
  struct s_telem	*next;
}			t_telem;

typedef struct		s_tlist
{
  int			taille;
  struct s_telem	*begin;
}			t_tlist;

/*---- functions ----*/

int			direct_exec(char *cmd, int fd);
int			add_planning(int t, char *cmd, int fd);
void			init_tlist(t_tlist *list);
void			insert_tlist(t_tlist *list, char *cmd, int fd, struct timeval *end);
void			show_tlist(t_tlist *list);
struct timeval		*manage_planning(t_tlist *planning);
void			ret_cbuffer(int fd);
void			ret_planning(t_tlist *planning, int fd);
int			add_planning(int t, char *cmd, int fd);

#endif
