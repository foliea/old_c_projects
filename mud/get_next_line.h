/*
** get_next_line.h for mud in /u/all/folie_a/cu/rendu/c/mud
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Jul  5 03:07:41 2010 adrien folie
** Last update Mon Jul  5 03:07:42 2010 adrien folie
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

int	xread(const int fd, char *buffer, int size);
char	*line_malloc(int size);
char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
