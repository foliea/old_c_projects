/*
** common.h for  in /u/all/gouesl_a/cu/rendu/my_ftp/common
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Sun Apr 18 21:06:04 2010 antoine goueslard
** Last update Sun Apr 18 21:06:06 2010 antoine goueslard
*/

/* included from strlib.c */
void	my_puts(int fd,char *str);
void	my_putstr(char *str);
void	my_putnbr(int i);

/* included from mini_next.c */
char *get_next_line(int fd);

/* included from str_tab.c */
char **str_to_tab(char *str);

/*included from get_open.c */
int get_open(char *sent);
int put_open(char *sent);
