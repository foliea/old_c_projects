/*
** mud.h for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul 12 23:37:45 2010 adrien folie
** Last update Mon Jul 12 23:40:29 2010 adrien folie
*/

#ifndef MUD_H
#define MUD_H

void	parse_map(t_tlist *map, char *file);
void	verif_map(t_tlist *map);
void	free_list_rooms(t_tlist *rooms);
void	free_list_players(t_tlist *players);

#endif
