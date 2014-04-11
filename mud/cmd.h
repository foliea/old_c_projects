/*
** cmd.h for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 01:29:32 2010 adrien folie
** Last update Tue Jul 13 03:19:10 2010 adrien folie
*/

#ifndef CMD_H
#define CMD_H

void	do_nord(__attribute__((unused))char *cmd, t_env *e, int fd);
void	do_sud(__attribute__((unused))char *cmd, t_env *e, int fd);
void	do_est(__attribute__((unused))char *cmd, t_env *e, int fd);
void	do_ouest(__attribute__((unused))char *cmd, t_env *e, int fd);
void	do_speak(char *cmd, t_env *e, int fd);
void	do_shout(char *cmd, t_env *e, int fd);
void	do_take(char *cmd, t_env *e, int fd);
void	do_drop(char *cmd, t_env *e, int fd);
void	do_food(__attribute__((unused))char *cmd, t_env *e, int fd);
void	do_voir(__attribute__((unused))char *cmd, t_env *e, int fd);
void	do_inv(__attribute__((unused))char *cmd, t_env *e, int fd);
void	do_room(__attribute__((unused))char *cmd, t_env *e, int fd);
void	do_life(__attribute__((unused))char *cmd, t_env *e, int fd);
#endif
