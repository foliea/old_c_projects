##
## Makefile for push-swap in /u/all/otteme_t/cu/rendu/c/push_swap
##
## Made by thibaut ottemer
## Login   <otteme_t@epitech.net>
##
## Started on  Wed Jun 24 12:51:03 2009 thibaut ottemer
## Last update Sun Sep 13 18:32:21 2009 adrien folie
##

CC = gcc

NAME		=	sudoki-bi
SRC		=	my_putchar.c	\
			my_putstr.c	\
			main_sudoki.c	\
			my_show_tab.c	\
			algor.c		\
			case_pos.c	\
			get_next_line.c	\
			list_sudoki.c	\
			search_pos.c	\
			my_strdup.c	\
			my_put_error.c	\
			my_strlen.c

CFLAGS		=	-W -Wall -Wextra -ansi -pedantic

OBJ		=	$(SRC:.c=.o)
RM		=	rm -f

all:			$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
clean:
			$(RM) $(OBJ)
			$(RM) *~
			$(RM) \#*\#
			$(RM) a.out

fclean: 		clean
			$(RM) $(NAME)

re:			fclean all
