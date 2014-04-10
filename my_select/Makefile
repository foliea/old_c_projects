##
## Makefile for Makefile in /u/all/folie_a/cu/rendu/c/my_ls
##
## Made by adrien folie
## Login   <folie_a@epitech.net>
##
## Started on  Wed May 20 22:11:10 2009 adrien folie
## Last update Wed Jul  8 18:18:15 2009 adrien folie
##

TYPE            =       $(shell uname -s)
TYPE            !=      uname -s
CC              =       gcc

NAME		=	my_select
SRC		=	clist_utils.c		\
			put_in_clist.c		\
			get_keys.c		\
			my_caps.c		\
			main.c			\
			my_aff_list.c		\
			my_aff_sub.c		\
			my_getenv.c		\
			my_ioctl_mod.c		\
			my_scroll_list.c	\
			my_putchar.c		\
			my_putstr.c		\
			my_strlen.c		\
			my_strdup.c

LIB		=	-ltermcap
CFLAGS		=	-W -Wall -Wextra -ansi -pedantic

OBJ		=	$(SRC:.c=.o)
RM		=	rm -f

all:			$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)
clean:
			$(RM) $(OBJ)
			$(RM) *~
			$(RM) \#*\#
			$(RM) a.out

fclean: 		clean
			$(RM) $(NAME)

re:			fclean all
