/*
** room.h for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:10:29 2010 adrien folie
** Last update Tue Jul  6 01:53:33 2010 adrien folie
*/

#ifndef ROOM_H
#define ROOM_H

#define OK 0
#define NONE -1

typedef struct	s_room
{
  int		id;
  char		*txt;
  int		nord;
  int		sud;
  int		est;
  int		ouest;
  t_tlist	*obj;
}		t_room;

#endif
