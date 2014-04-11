CC              =       /usr/bin/gcc

NAME		=	lemipc

NAME1		=	graphics

RM		=	rm -f

SRC		=	checks_data.c	\
			direct_move.c	\
			find_target.c	\
			aff_err.c	\
			intel_move.c	\
			init.c		\
			xmalloc.c	\
			main_lemipc.c	\
			send_receive.c

SRC1		=	graphic.c	\
			aff_err.c	\
			termcaps.c

CFLAGS	=	-ansi -pedantic -W -Wall

LIB	=	-ltermcap

OBJ     =       $(SRC:.c=.o)


all:		
		$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LIB)
		$(CC) -o $(NAME1) $(CFLAGS) $(SRC1) $(LIB)

clean:
		$(RM) $(OBJ)
		$(RM) *~
		$(RM) \#*\#
		$(RM) a.out
fclean:
		$(RM) $(OBJ) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re