/*
** check.h for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Wed Jun 16 00:33:47 2010 edern bienvenu
** Last update Sun Jun 20 18:01:41 2010 edern bienvenu
*/

#ifndef FD_PUTS_H
#define FD_PUTS_H

int	fd_puts(int fd, char *str);
void	fd_putnbr(int fd, int nb);
char	*inttostr(int nb);
void	print_time(void);
void	my_putstr(char *str);
void	send_ko(int fd);

#endif
