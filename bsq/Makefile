##
## makefile for makefile in /u/all/folie_a/cu/rendu/lib/my
##
## Made by adrien folie
## Login   <folie_a@epitech.net>
##
## Started on  Mon Mar 23 11:29:55 2009 adrien folie
## Last update Fri May  8 17:16:05 2009 thibaut ottemer
##

CC = gcc
NAME =	bsq
INCLUDE = my.h
SRC =	my_buffer_to_tab.c	\
	my_getnbr.c		\
	my_getnextline.c	\
	my_putchar.c		\
	my_putstr.c		\
	my_show_in_color.c	\
	my_show_tab.c		\
	my_strcmp.c		\
	my_strdup.c		\
	my_strlen.c		\
	my_xmalloc.c		\
	my_error_report.c	\
	my_square.c

LIB = -L. -lmy_printf_`uname -m`-`uname -s`
CFLAGS	= -W -Wall -Wextra -ansi -pedantic

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
