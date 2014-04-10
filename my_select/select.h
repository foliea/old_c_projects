/*
** select.h for select in /u/all/folie_a/cu/rendu/c/my_select
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Wed Jun 17 12:47:12 2009 adrien folie
** Last update Wed Jul  8 18:15:54 2009 adrien folie
*/

#ifndef SELECT_H_
# define SELECT_H_

#include "clist.h"

typedef struct	s_caps
{
    char	*clstr; /* Clear */
    char	*sostr; /* StandOut */
    char	*sestr; /* Standout End */
    char	*usstr;
    char	*uestr;
    char	*vistr;
    char	*vestr;
    char	*cmstr; /* Cursor Motion */
    char	*kustr; /* Key Up */
    char	*kdstr; /* Key Down */
    char	*klstr; /* Key Left */
    char	*krstr; /* Key Right */
    int		*mlen;
    int		li;
    int		co;
    int		x;
    int		y;
}		t_caps;

int	my_printt(int c);
int	my_strlen(char *str);
int	my_putstr(char *str);
int	my_str_is_in(char *str, char *to_find);
int	my_int_len(int *t);
char	*my_path_dup(char *str, int i, int j);
char	*my_getenv(char **env, char *data);
char	*xtgetstr(char *cap, char **area);
void	my_subline(t_clist *list, t_caps *caps);
void	my_scroll_list(t_clist *list, t_caps *caps, int sens);
void	my_ioctl_mod(void);
void	my_putchar(char c);
void	my_check_term(char **env);
void	my_caps_def(t_caps *caps);
void	my_while(t_caps *caps, t_clist *list);
void	my_aff_and_select(t_clist *list, t_caps *caps);
void	my_get_keys(t_clist *list, t_caps *caps);
void	my_aff_sub(t_clist *list);
void	my_aff_list(t_clist *list, t_caps *caps);
void	my_scroll_side(t_clist *list, t_caps *caps, int sens);

#endif /* !SELECT_H_ */
