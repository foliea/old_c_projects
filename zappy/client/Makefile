##
## Makefile for Makefile 
## 
## Made by antoine goueslard
## Login   <gouesl_a@epitech.net>
## 
## Started on  Sat Jun 13 10:53:17 2009 antoine goueslard
## Last update Sun Jun 20 21:42:52 2010 antoine goueslard
##

CLIENT	=	client/
COMMON = common/

CC		=	gcc

SRC1		=	$(CLIENT)client.c	\
			$(CLIENT)timeout.c	\
			$(CLIENT)get_ans.c	\
			$(CLIENT)move.c		\
		 	$(CLIENT)gere_inv.c	\
			$(CLIENT)obj.c		\
			$(CLIENT)gnr.c		\
			$(CLIENT)ia.c		\
			$(CLIENT)iamath.c	\
			$(CLIENT)ia_pierre.c	\
			$(CLIENT)do_invoc.c	\
			$(CLIENT)broadcast.c

SRCC      = $(COMMON)strlib.c \
            $(COMMON)str_tab.c \
	    $(COMMON)mini_next.c 

NAME1		=	zap_client


OBJ1		=	$(SRC1:.c=.o)
OBJC		=	$(SRCC:.c=.o)

CFLAGS		=	-W -Wall -ansi -pedantic -o $@

RM		=	rm -f

all		:	$(OBJ1) $(OBJC)
			$(CC) $(OBJ1) $(OBJC) $(CFLAGS) -o $(NAME1) -lm


clean		:
			$(RM) $(OBJ1) $(OBJC)

fclean:			clean
			$(RM) $(NAME1)

re		:	fclean all