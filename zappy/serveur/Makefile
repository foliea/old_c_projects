##
## Makefile for 205inter in /u/all/bienve_e/cu/rendu/math/205inter
## 
## Made by edern bienvenu
## Login   <bienve_e@epitech.net>
## 
## Started on  Sun May  2 10:30:28 2010 edern bienvenu
## Last update Sun Jun 20 19:28:39 2010 adrien folie
##

CC	=	gcc
NAME	=	serveur

SRC	=	add_client.c		\
		aff_err.c		\
		aff_func.c		\
		add_planning.c		\
		check_team.c		\
		check_elevation.c	\
		circular_buffer.c	\
		cmd_queue.c		\
		cmd_object.c		\
		create_serveur.c	\
		do_broad.c		\
		do_deplacement.c	\
		do_elevation.c		\
		do_move.c		\
		do_voir.c		\
		direct_exec.c		\
		fd_puts.c		\
		fd_putnbr.c		\
		find_cmd.c		\
		free_list_planning.c	\
		free_list_buffer.c	\
		free_list_teams.c	\
		gere_death.c		\
		gere_food.c		\
		get_food.c		\
		get_player.c		\
		init_select.c		\
		init_map.c		\
		inttostr.c		\
		list_cbuffer.c		\
		list_team.c		\
		list_planning.c		\
		loop_select.c		\
		main_serveur.c		\
		manage_cmd.c		\
		manage_planning.c	\
		my_putstr.c		\
		pars_opt.c		\
		print_time.c		\
		put_in_cbuff.c		\
		quit_client.c		\
		ret_cbuff.c		\
		ret_cbuff_an.c		\
		ret_team.c		\
		ret_team_an.c		\
		recup_player_pos.c	\
		recup_k_value.c		\
		send_ko.c		\
		voir_dir.c		\
		xgettimeofday.c		\
		xmalloc.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	$(INCLUDE) -W -Wall

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lm

clean:
	rm -f *.o *~ \#*# *.core

fclean: clean
	rm -f $(NAME)

re: fclean all
