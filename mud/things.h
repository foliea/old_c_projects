/*
** things.h for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Jul  9 05:16:13 2010 adrien folie
** Last update Mon Jul 12 23:31:54 2010 adrien folie
*/

#ifndef THINGS_H
#define THINGS_H

t_cbuff		*choose_buffer(t_tlist *players, int fd, int mode);
t_player	*get_player(t_tlist *players, int fd);
t_room		*get_room(t_tlist *map, int id);

#endif
