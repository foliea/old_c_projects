##
## Makefile for Makefile in /u/all/bienve_e/cu/rendu/c/minishell1
## 
## Made by edern bienvenu
## Login   <bienve_e@epitech.net>
## 
## Started on  Wed Jun  3 21:00:19 2009 edern bienvenu
## Last update Tue Mar 30 17:07:51 2010 adrien folie
##

TYPE            =       $(shell uname -s)
TYPE            !=      uname -s
CC              =       gcc

NAME		=	libmy_malloc_${TYPE}.so

RM		=	rm -f

SRC		=	malloc.c	\
			realloc.c	\
			free.c		\
			checklist.c	\
			calc.c		\
			my_strlen.c	\
			my_put_error.c

CFLAGS	=	-ansi -pedantic -W -Wall

OBJ     =       $(SRC:.c=.o)


$(NAME):	$(OBJ)
		$(CC) -shared $(SRC) -o $(NAME)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) *~
fclean:
		$(RM) $(OBJ) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
