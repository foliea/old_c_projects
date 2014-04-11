/*
** get_next_line.h for get_next_line.h in /u/all/folie_a/cu/rendu/c/get_next_line
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun May 31 22:22:36 2009 adrien folie
** Last update Sun May 31 22:25:19 2009 adrien folie
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

int	xread(const int fd, char *buffer, int size);
char	*line_malloc(int size);
char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
