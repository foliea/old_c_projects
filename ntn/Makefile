##
## makefile for makefile in /u/all/folie_a/cu/rendu/lib/my
##
## Made by adrien folie
## Login   <folie_a@epitech.net>
##
## Started on  Mon Mar 23 11:29:55 2009 adrien folie
## Last update Sun May 24 23:22:34 2009 adrien folie
##

CC	=	gcc

NAME	=	ntn

INCLUDE	=	ntn.h

SRC	=	my_putchar.c		\
		my_strlen.c		\
		int_to_str.c		\
		my_getnbr.c		\
		my_xmalloc.c		\
		my_error.c		\
		ntn_main.c		\
		ntn_recup.c		\
		ntn_index.c		\
		ntn_checks.c		\
		ntn_display.c		\
		ntn_display2.c		\
		my_putstr.c

CFLAGS	=	-W -Wall -Wextra -ansi -pedantic

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) \#*\#
	$(RM) a.out

fclean: clean
	$(RM) $(NAME)

re:	fclean all
