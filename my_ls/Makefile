##
## Makefile for Makefile in /u/all/folie_a/cu/rendu/c/my_ls
##
## Made by adrien folie
## Login   <folie_a@epitech.net>
##
## Started on  Wed May 20 22:11:10 2009 adrien folie
## Last update Tue May 26 07:11:42 2009 adrien folie
##

CC = gcc
NAME =	my_ls
INCLUDE = my.h
SRC =	parser_ls.c		\
	list_utils.c		\
	ls_options.c		\
	ls_display.c		\
	ls_mod.c		\
	ls_dlist.c		\
	count_blocks.c		\
	my_putchar.c		\
	my_list_size.c		\
	my_putstr.c		\
	my_strcmp.c		\
	my_strlen.c		\
	my_strdup_select.c	\
	my_getpwd.c		\
	my_error_report.c

LIB = -L. -lmy_printf_`uname -m`-`uname -s`
CFLAGS	= -W -g3 -Wall -Wextra -ansi -pedantic

OBJ = $(SRC:.c=.o)
RM = rm -f

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)
clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) \#*\#
	$(RM) a.out

fclean: clean
	$(RM) $(NAME)

re:	fclean all
