/*
** free_obj.h for zappy in /u/all/folie_a/cu/zappy
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Sun Jun 20 19:17:54 2010 adrien folie
** Last update Sun Jun 20 19:20:25 2010 adrien folie
*/

#ifndef FREE_OBJ_H
#define FREE_OBJ_H

void	free_list_teams(void);
void	free_list_buffer(void);
void	free_list_planning(void);
void	free_cbuffer(t_cbuff *cbuffer, int end);

#endif
