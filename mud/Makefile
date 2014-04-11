##
## Makefile for mud in /u/all/folie_a/cu/rendu/c/mud
## 
## Made by adrien folie
## Login   <folie_a@epitech.net>
## 
## Started on  Fri Jul  9 05:13:24 2010 adrien folie
## Last update Thu Jul 15 08:52:15 2010 adrien folie
##

CC	=	gcc
NAME	=	serveur

SRC	=	aff_err.c		\
		aff_map.c		\
		circular_buffer.c	\
		client_utils.c		\
		create_server.c		\
		do_broadcast.c		\
		do_cmd.c		\
		do_move.c		\
		do_voir.c		\
		fd_puts.c		\
		free_cbuff.c		\
		free_rooms.c		\
		get_next_line.c		\
		get_things.c		\
		init_env.c		\
		loop_select.c		\
		main_mud.c		\
		parse_mud.c		\
		print_time.c		\
		put_in_cbuff.c		\
		ret_obj.c		\
		ret_obj_an.c		\
		ret_player.c		\
		str_to_wordtab.c	\
		tab_utils.c		\
		take_drop.c		\
		tlist_utils.c		\
		verif_map.c		\
		xmalloc.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	$(INCLUDE) -W -Wall -ansi -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lm

clean:
	rm -f *.o *~ \#*# *.core

fclean: clean
	rm -f $(NAME)

re: fclean all
