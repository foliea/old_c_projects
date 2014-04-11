/*
** ntn_index.c for ntn_index in /u/all/folie_a/cu/rendu/c/proj/ntn
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun May 24 15:34:43 2009 adrien folie
** Last update Sun May 24 20:26:36 2009 adrien folie
*/

#include "ntn.h"

static const t_index   	dizaine[]=
{
  {'1', "dix"},
  {'2', "vingt"},
  {'3', "trente"},
  {'4', "quarante"},
  {'5', "cinquante"},
  {'6', "soixante"},
  {'7', "soixante-"},
  {'8', "quatre-vingts"},
  {'9', "quatre-vingt"},
  {0, NULL}
};

static const t_index	unit[]=
{
  {'0', ""},
  {'1', "un"},
  {'2', "deux"},
  {'3', "trois"},
  {'4', "quatre"},
  {'5', "cinq"},
  {'6', "six"},
  {'7', "sept"},
  {'8', "huit"},
  {'9', "neuf"},
  {0, NULL}
};

static const t_index	special[]=
{
  {'0', "dix"},
  {'1', "onze"},
  {'2', "douze"},
  {'3', "treize"},
  {'4', "quatorze"},
  {'5', "quinze"},
  {'6', "seize"},
  {'7', "dix-sept"},
  {'8', "dix-huit"},
  {'9', "dix-neuf"},
  {0, NULL}
};

void	print_special(char c)
{
  int	i;

  i = 0;
  while (special[i].pos != 0)
    {
      if (c == special[i].pos)
	my_putstr(special[i].nb);
      ++i;
    }
}

int	print_unit(char c)
{
  int	i;

  i = 0;
  while (unit[i].pos != 0)
    {
      if (c == unit[i].pos)
	my_putstr(unit[i].nb);
      ++i;
    }
  return (1);
}

void	print_dizaine(char c)
{
  int   i;

  i = 0;
  while (dizaine[i].pos != 0)
    {
      if (c == dizaine[i].pos)
	my_putstr(dizaine[i].nb);
      ++i;
    }
}

void	print_link(char nb1, char nb2)
{
  if (nb1 != '0' && nb2 != '0')
    {
      if (nb2 == '1')
	my_putstr("-et-");
      else if (nb2 != '1')
	my_putchar('-');
    }
  else if (nb1 == '7' && nb2 == '0')
    my_putchar('-');
}
