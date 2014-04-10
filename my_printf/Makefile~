##
## makefile for makefile in /u/all/folie_a/cu/rendu/lib/my
##
## Made by adrien folie
## Login   <folie_a@epitech.net>
##
## Started on  Mon Mar 23 11:29:55 2009 adrien folie
## Last update Mon Jan 10 14:59:10 2011 adrien folie
##

NAME = libmy_printf_`uname -m`-`uname -s`.a
INCLUDE = my.h
SRC =	my_printf.c				\
	my_strlen.c				\
	my_putchar.c				\
	my_putstr.c				\
	my_printnbr_base.c			\
	my_string_np.c				\
	my_flags1.c				\
	my_flags2.c				\
	my_getnbr.c				\
	my_printstr.c				\
	my_print_zero.c

CFLAGS	= -Wall -Wextra -ansi -pedantic

OBJ = $(SRC:.c=.o)
RM = rm -f

all: $(OBJ)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
