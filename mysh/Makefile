##
## Makefile for Makefile in /u/all/folie_a/cu/rendu/c/my_ls
##
## Made by adrien folie
## Login   <folie_a@epitech.net>
##
## Started on  Wed May 20 22:11:10 2009 adrien folie
## Last update Mon Oct  5 10:30:29 2009 adrien folie
##

TYPE            =       $(shell uname -s)
TYPE            !=      uname -s
CC              =       gcc

NAME		=	mysh
SRC		=	get_next_line.c		\
			mns_main.c		\
			mns_recup_bin.c		\
			mns_recup_cmd.c		\
			mns_sort_cmd.c		\
			check_bin_list.c	\
			mns_builtins.c		\
			put_in_dlist.c		\
			do_pipes.c		\
			my_cd.c			\
			check_list.c		\
			do_redirections.c	\
			dlist_utils.c		\
			old_pwd.c		\
			my_error_report.c	\
			my_put_error.c		\
			my_getenv.c		\
			my_setenv.c		\
			my_unsetenv.c		\
			my_putchar.c		\
			my_putstr.c		\
			my_str_to_wordtab.c	\
			my_strcmp.c		\
			my_strlen.c		\
			my_strdup.c		\
			my_xmalloc.c		\
			my_modenv.c		\
			tab_utils.c

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
