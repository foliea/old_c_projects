/*
** colors.h for colors.h in /u/all/folie_a/cu/rendu/c/bsq
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Thu Apr 30 08:17:44 2009 adrien folie
** Last update Fri May  8 16:37:57 2009 thibaut ottemer
*/

#ifndef COLORS_H_
# define COLORS_H_

# include <stdlib.h>

# define clrscr() my_printf("\033[H\033[2J")
# define couleur(param) my_printf("\033[%sm", param)

void	my_putchar(char c);
int	my_printf(char *str, ...);
int	my_print_yellow(char c);
int	my_print_magenta(char c);
int	my_print_green(char c);
int	my_put_incolor(char *tab);
int	my_show_in_colors(char **tab);

#endif /* !COLORS_H_ */
