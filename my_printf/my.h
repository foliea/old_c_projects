/*
** my.h for my.h in /u/all/folie_a/cu/rendu/c/my_printf
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr 14 17:30:48 2009 adrien folie
** Last update Wed Apr 29 16:30:32 2009 adrien folie
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
int	my_decimal(va_list *ap, int prec);
int	my_udecimal(va_list *ap, int prec);
int	my_string(va_list *ap, int prec);
int	my_string_np(va_list *ap, int prec);
int	my_string_null(int prec);
int	my_getnbr(char *nbr);
int	my_character(va_list *ap, int prec);
int	my_hex_maj(va_list *ap, int prec);
int	my_hex_min(va_list *ap, int prec);
int	my_binaire(va_list *ap, int prec);
int	my_put_purcent(va_list *ap, int prec);
int	my_put_octal(unsigned char np);
int	my_octal(va_list *ap, int prec);
int	my_pointer(va_list *ap, int prec);
int	my_flags(char flg, va_list *ap, int prec);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_printstr(char *str, int prec);
int	my_put_nbr(int nb);
int	my_putnbr_base_u(unsigned int nbr, char *base, int *i);
int	my_putnbr_base_s(int nbr, char *base, int *i);
int	my_putnbr_base_maj(unsigned int nbr, char *base, int *i);
int	my_strlen(char *str);
int	my_printf(char *str, ...);
int	my_precision(char *str, int i, int *prec);
int	my_print_zero(int prec, int i);
int	my_check_nbr_u(unsigned int nbr, int base_div, int *i);
int	my_check_nbr_s(int nbr, int base_div, int *i);
int	my_parseur(char *str, va_list *ap);
#endif
