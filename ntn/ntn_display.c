/*
** ntn_display.c for ntn_display.c in /u/all/folie_a/cu/rendu/c/proj/ntn
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun May 24 15:28:07 2009 adrien folie
** Last update Sun May 24 23:34:36 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include "ntn.h"

void	ntn_quatre_vingt(char nb2)
{
  if (nb2 == '0')
    print_dizaine('8');
  else
    print_dizaine('9');
  if (nb2 > '0')
    my_putchar('-');
  print_unit(nb2);
}

int	ntn_dizaine(char nb1, char nb2)
{
  if (nb1 == '1')
    print_special(nb2);
  else if (nb1 == '7')
    {
      print_dizaine('6');
      print_link(nb1, nb2);
      print_special(nb2);
    }
  else if (nb1 == '9')
    {
      print_dizaine('9');
      my_putchar('-');
      print_special(nb2);
    }
  else if (nb1 == '8')
    ntn_quatre_vingt(nb2);
  else
    {
      print_dizaine(nb1);
      print_link(nb1, nb2);
      print_unit(nb2);
    }
  return (2);
}

int	ntn_centaine(char nb0, char nb1, char nb2)
{
  if (nb0 == '1')
    my_putstr("cent");
  else if (nb0 > '1')
    {
      print_unit(nb0);
      if (nb1 == '0' && nb2 == '0')
        my_putstr(" cents");
      else
        my_putstr(" cent");
    }
  if (nb1 > '0' || nb2 > '0')
    my_putchar(' ');
  ntn_dizaine(nb1, nb2);
  return (3);
}

void	ntn_milliards(char c, int j, char *str)
{
  if (check_str_limit(j - 4, str) == 1)
    {
      if (c == '1' && j == 1)
        my_putstr("un milliard");
      else
        {
          if (j == 1)
            my_putchar(' ');
          my_putstr("milliards");
        }
      if (str[j] != '0')
        my_putchar(' ');
      if (check_str(j - 1, str) == 0)
        {
          my_putchar('\n');
          exit(EXIT_SUCCESS);
        }
    }
}

void	ntn_millions(char c, int j, char *str)
{
  if (check_str_limit(j - 4, str) == 1)
    {
      if (check2_str(j, str) == 1)
        my_putchar(' ');
      if (c == '1' && j == 1)
        my_putstr("un million");
      else
	my_putstr("millions");
      if (str[j] != '0')
        my_putchar(' ');
      if (check_str(j - 1, str) == 0)
        {
          my_putchar('\n');
          exit(EXIT_SUCCESS);
        }
    }
}
