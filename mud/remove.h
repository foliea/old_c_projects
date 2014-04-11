/*
** remove.h for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul 12 23:08:57 2010 adrien folie
** Last update Mon Jul 12 23:24:01 2010 adrien folie
*/

#ifndef REMOVE_H
#define REMOVE_H

void	remove_mid_end(t_tlist *recup, t_telem *save);
void	remove_mid_mid(t_tlist *recup, t_telem *save);
void	remove_mid_beg(t_tlist *team);
void	ret_obj(t_tlist *inv, char *obj);
void	free_objs(t_tlist *objs);
void	free_cbuff(t_cbuff *cbuff);
void	ret_player(t_tlist *players, int fd);

#endif
