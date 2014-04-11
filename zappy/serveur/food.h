/*
** food.h for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun Jun 20 17:46:59 2010 edern bienvenu
** Last update Sun Jun 20 18:14:03 2010 edern bienvenu
*/

#ifndef FOOD_H
#define FOOD_H

int			get_food(int fd, int type);
void			add_food(int fd, int x, int y);
void			ret_food(int fd, int x, int y);
struct timeval		*get_timeval_planning(int fd);

#endif
