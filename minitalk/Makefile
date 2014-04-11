##
## Makefile for Makefile in /u/all/folie_a/cu/rendu/c/my_ls
##
## Made by adrien folie
## Login   <folie_a@epitech.net>
##
## Started on  Wed May 20 22:11:10 2009 adrien folie
## Last update Sat Oct 17 17:14:55 2009 adrien folie
##

TYPE            =       $(shell uname -s)
TYPE            !=      uname -s
CC              =       gcc

NAME		=	serveur
NAME2		=	client
SRC		=	my_put_error.c	\
			my_putchar.c	\
			my_putstr.c	\
			my_strlen.c	\
			my_put_nbr.c	\
			main_serveur.c	\
			serveur.c


SRC2		=	my_putstr.c	\
			my_put_error.c	\
			my_putchar.c	\
			my_strlen.c	\
			my_getnbr.c	\
			client.c

CFLAGS		+=	-W -Wall -Wextra -ansi -pedantic

OBJ		=	$(SRC:.c=.o)
OBJ2		=	$(SRC2:.c=.o)
RM		=	rm -f

all:			$(OBJ) $(OBJ2)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
			$(CC) -o $(NAME2) $(OBJ2) $(CFLAGS)
clean:
			$(RM) $(OBJ)
			$(RM) $(OBJ2)
			$(RM) *~
			$(RM) \#*\#
			$(RM) a.out

fclean: 		clean
			$(RM) $(NAME)
			$(RM) $(NAME2)

re:			fclean all

.PHONY:			clean all fclean re
