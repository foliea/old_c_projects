##
## Makefile for my irc in /u/all/folie_a/cu/rendu/c/my_irc
##
## Made by adrien folie
## Login   <folie_a@epitech.net>
##
## Started on  Wed Apr 28 22:25:09 2010 adrien folie
## Last update Wed Apr 28 22:33:56 2010 adrien folie
##


TYPE            =       $(shell uname -s)
TYPE            !=      uname -s
CC              =       gcc

NAME		=	serveur
NAME2		=	client

RM		=	rm -f

SRC		=	get_next_line.c		\
			send_msg_all.c		\
			sxfunction.c		\
			retire_fd.c		\
			modif_nick.c		\
			inttostr.c		\
			verif_chan.c		\
			my_show_dchan.c		\
			sstr_to_word_tab.c	\
			chan_in_dlist.c		\
			my_show_dlist.c		\
			my_strcat.c		\
			put_in_dlist.c		\
			saff_err.c		\
			soption.c		\
			sutils.c		\
			parser.c		\
			sclient.c		\
			init.c			\
			whois.c			\
			loop.c			\
			crt_server.c		\
			serv_irc.c

SRC2		=	get_next_line.c		\
			xfunctions.c		\
			str_to_word_tab.c	\
			connection.c		\
			option.c		\
			option2.c		\
			aff_err.c		\
			server_read.c		\
			utils.c			\
			window.c		\
			check_client.c		\
			main_client.c		\
			write_on_screen.c	\
			my_strcat.c		\
			client.c

INCLUDE		=	-D_THREAD_SAFE -I/usr/local/include/gtk-2.0 			\
			-I/usr/local/lib/gtk-2.0/include -I/usr/local/include/atk-1.0 	\
			-I/usr/local/include/cairo -I/usr/local/include/pango-1.0 	\
			-I/usr/local/include -I/usr/local/include/glib-2.0 		\
			-I/usr/local/lib/glib-2.0/include 				\
			-I/usr/local/include/freetype2

LIB		=	-L/usr/local/lib -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lpangocairo-1.0 -lXext -lXrender -lXinerama -lXi -lXrandr -lXcursor -lXfixes -lcairo -lpangoft2-1.0 -lfontconfig -lfreetype -lz -lpango-1.0 -lm -lX11 -lgobject-2.0 -lgmodule-2.0 -lglib-2.0 -liconv

CFLAGS	=	-ansi -pedantic -W -Wall

OBJ     =       $(SRC:.c=.o)

OBJ2	=	$(SRC2:.c=.o)

$(NAME):	$(OBJ) $(OBJ2)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
		$(CC) $(INCLUDE) $(LIB) $(OBJ2) -o $(NAME2)
.c.o:
		$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $(<:.c=.o)

all:		$(NAME)

clean:
		$(RM) $(OBJ) $(OBJ2)
		$(RM) *~
		$(RM) \#*\#
		$(RM) a.out
fclean:
		$(RM) $(OBJ) $(NAME)
		$(RM) $(OBJ2) $(NAME2)
re: 		fclean all

.PHONY:		all clean fclean re
