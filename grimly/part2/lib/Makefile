##
## makefile for makefile in /u/all/folie_a/cu/rendu/lib/my
##
## Made by adrien folie
## Login   <folie_a@epitech.net>
##
## Started on  Mon Mar 23 11:29:55 2009 adrien folie
## Last update Sat Nov  7 01:02:30 2009 adrien folie
##

NAME 		= 	librush_`uname -m`-`uname -s`.a

INCLUDE 	= 	librush.h

SRCS 		= 	my_freetab.c		\
			my_putchar.c		\
			my_getnbr.c		\
			my_putstr.c		\
			my_showtab.c		\
			my_strcat.c		\
			my_strcmp.c		\
			my_strncmp.c		\
			my_strcpy.c		\
			my_strdup.c		\
			my_strlen.c		\
			my_swapstr.c		\
			my_tabdup.c		\
			my_tablen.c		\

CFLAGS		= 	-Wall -Wextra -ansi -pedantic

OBJS		=	$(SRCS:.c=.o)

RM		=	rm -f

all: $(OBJS)
	ar r $(NAME) $(OBJS)
	ranlib $(NAME)
clean:
	$(RM) $(OBJS)
	$(RM) *~
	$(RM) \#*\#
	$(RM) a.out
fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re $(NAME)
