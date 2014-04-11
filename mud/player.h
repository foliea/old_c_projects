/*
** player.h for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:09:49 2010 adrien folie
** Last update Thu Jul 15 01:43:21 2010 adrien folie
*/

#ifndef PLAYER_H
#define PLAYER_H

#define LIFE_START 20
#define FOOD 20

typedef struct	s_player
{
  int		fd;
  int		pos;
  int		life;
  t_tlist	*obj;
  t_cbuff	*cread;
  t_cbuff	*cwrite;
}		t_player;

#endif
