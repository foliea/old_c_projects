/*
** voir.h for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun Jun 20 18:39:50 2010 edern bienvenu
** Last update Sun Jun 20 19:12:05 2010 edern bienvenu
*/

#ifndef VOIR_H
#define VOIR_H

int	aff_case(t_voir *voir, int i, int fd, int dir, int check);
void	verif_pos_voir(t_voir *voir, int z);
void	voir_by_lvl(t_player *player, int nb_spot, int fd);
void	voir(t_player *player, int fd);
void	upgrade_follow(t_voir *voir, int dir);
int	upgrade_value(t_voir *voir, int dir);

#endif
