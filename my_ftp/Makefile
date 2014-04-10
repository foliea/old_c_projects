##
## Makefile for my_ftp in /u/all/folie_a/cu/rendu/c/my_ftp
## 
## Made by adrien folie
## Login   <folie_a@epitech.net>
## 
## Started on  Thu Apr  8 01:21:31 2010 adrien folie
## Last update Wed Apr 28 22:26:58 2010 adrien folie
##

TYPE            =       $(shell uname -s)
TYPE            !=      uname -s
CC              =       gcc

NAME		=	serveur
NAME2		=	client

RM		=	rm -f

SRC		=	serveur_main.c		\
			serveur_select.c	\
			get_next_line.c		\
			aff_err.c		\
			my_putstr.c		\
			my_freetab.c		\
			serveur_ls.c		\
			serveur_files.c		\
			my_tablen.c		\
			xfunctions.c		\
			my_str_to_wordtab.c	\

SRC2		=	client_main.c		\
			client_select.c		\
			get_next_line.c		\
			my_tablen.c		\
			my_str_to_wordtab.c	\
			my_putstr.c		\
			client_files.c		\
			xfunctions.c		\
			aff_err.c		\
			my_freetab.c

CFLAGS	=	-ansi -pedantic -W -Wall

OBJ     =       $(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

$(NAME):	$(OBJ) $(OBJ2)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
		$(CC) -o $(NAME2) $(OBJ2) $(CFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ) $(OBJ2)
		$(RM) *~
		$(RM) \#*\#
		$(RM) a.out
fclean:
		$(RM) $(OBJ) $(NAME)
		$(RM) $(OBJ2) $(NAME2)
re: 		fclean all

.PHONY:		all clean fclean re
