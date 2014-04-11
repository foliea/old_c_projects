/*
** caps.h for lemipc in /u/all/folie_a/cu/public/dedern/lemipc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 21 17:09:13 2010 adrien folie
** Last update Sun May 23 19:54:41 2010 edern bienvenu
*/

#ifndef CAPS_H
#define CAPS_H

#define ECHAP 27

typedef struct		s_caps
{
  char			*cmstr;
  char			*clstr;
  int			li;
  int			co;
  struct termios	save;
}			t_caps;

/*---- Functions ----*/

void	start_terminal(t_caps *caps);
void	init_caps(t_caps *caps);
int	my_outc(int c);
void	replace_on_screen(t_caps *caps);
void	verif_term(void);

#endif
