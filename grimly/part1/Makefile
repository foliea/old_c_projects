##
## Makefile for Makefile in /u/all/folie_a/cu/rendu/rush/grimly/part1
##
## Made by adrien folie
## Login   <folie_a@epitech.net>
##
## Started on  Sun Nov  8 03:41:24 2009 adrien folie
## Last update Sun Nov  8 19:48:02 2009 adrien folie
##

NAME	=	grimly

SRC	=	algo_utils.c		\
		astar.c			\
		checks_map.c		\
		finish_way.c		\
		dlist_utils.c		\
		find_size.c		\
		get_next_line.c		\
		main_grimly.c		\
		my_put_error.c		\
		put_in_dlist.c		\
		xmalloc.c		\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	+=	-W -Wall -ansi -pedantic

LIB	=	-L./lib ./lib/librush_`uname -m`-`uname -s`.a -lm

RM	=	rm -f

all	: $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME)

clean	:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) \#*\#
	$(RM) a.out

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
