##
## makefile for makefile in /u/all/folie_a/cu/rendu/lib/my
## 
## Made by adrien folie
## Login   <folie_a@epitech.net>
## 
## Started on  Mon Mar 23 11:29:55 2009 adrien folie
## Last update Mon Mar 23 19:35:37 2009 adrien folie
##

NAME = mylibc.a
INCLUDE = my_libc.h
SRC =	my_getnbr.c \
	my_is_prime.c \
	my_isneg.c \
	my_op.c \
	my_power_rec.c \
	my_put_nbr.c \
	my_putchar.c \
	my_putstr.c \
	my_revstr.c \
	my_show_to_wordtab.c \
	my_sort_int_tab.c \
	my_square_root.c \
	my_str_isalpha.c \
	my_str_islower.c \
	my_str_isnum.c \
	my_str_isprintable.c \
	my_str_isupper.c \
	my_str_to_wordtab.c \
	my_strcapitalize.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_strdup.c \
	my_strlcat.c \
	my_strlen.c \
	my_strlowcase.c \
	my_strncat.c \
	my_strncmp.c \
	my_strncpy.c \
	my_strstr.c \
	my_strupcase.c \
	my_swap.c \
	my_swap_str.c

OBJ = $(SRC:.c=.o)
RM = rm -f

all: $(OBJ) 	
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)
clean:
	$(RM) $(OBJ)
	$(RM) *~
fclean:
	$(RM) $(NAME)

