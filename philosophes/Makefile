##
## Makefile for corewar in /u/all/otteme_t/cu/rendu/c/proj/corewar
## 
## Made by thibaut ottemer
## Login   <otteme_t@epitech.net>
## 
## Started on  Thu Aug  6 15:19:03 2009 thibaut ottemer
## Last update Tue May 11 17:48:43 2010 adrien folie
##

TYPE            =       $(shell uname -s)
TYPE            !=      uname -s
CC              =       gcc

NAME		=	philosophes

SRC		=	send_receive.c	\
			state.c		\
			end.c		\
			main.c

LIBS		=	-lpthread

CFLAGS		=	-W -Wall -Wextra -ansi -pedantic -ggdb

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

$(NAME):		$(OBJ)
			$(CC) $(LIBS) $(OBJ) -o $(NAME)

all:			$(NAME)

clean:
			$(RM) $(OBJ)
			$(RM) *~
			$(RM) \#*\#
			$(RM) a.out
			$(RM) *.core

fclean: 		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:			all clean fclean re
