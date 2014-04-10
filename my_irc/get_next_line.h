/*
** get_next_line.h for filler in /u/all/fanals_s/public/filler/filler
** 
** Made by sebastien fanals-
** Login   <fanals_s@epitech.net>
** 
** Started on  Fri Jun 12 23:12:32 2009 sebastien fanals-
** Last update Sat Nov  7 18:29:13 2009 edern bienvenu
*/

#ifndef _GET_NEXT_LINE_H_
# define _GET_NEXT_LINE_H_

# define BUFF_SIZE 4096
# define BUFF_RETURN 4096
# define GNL_ERROR_FILE "Can't find or open the file.\n"

char	*get_next_line(const int fd);

#endif /* !__GET_NEXT_LINE_H__ */
