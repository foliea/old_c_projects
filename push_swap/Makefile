##
## Makefile for push-swap in /u/all/otteme_t/cu/rendu/c/push_swap
##
## Made by thibaut ottemer
## Login   <otteme_t@epitech.net>
##
## Started on  Wed Jun 24 12:51:03 2009 thibaut ottemer
## Last update Sat Jul  4 18:14:42 2009 adrien folie
##

TYPE            =       $(shell uname -s)
TYPE            !=      uname -s
CC              =       gcc

NAME		=	push_swap
SRC		=	dlist_utils.c		\
			push_main.c		\
			params_select.c		\
			put_in_dlist.c		\
			my_push_swap.c		\
			my_getnbr.c		\
			my_pab.c		\
			my_rabr.c		\
			my_rrabr.c		\
			my_sabs.c		\
			my_putchar.c		\
			my_putstr.c		\
			my_strdup.c		\
			my_strcmp.c		\
			my_strlen.c		\
			my_xmalloc.c

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
