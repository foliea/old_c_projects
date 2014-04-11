/*
** aff_func.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun Jun 20 19:10:37 2010 edern bienvenu
** Last update Sun Jun 20 19:11:09 2010 edern bienvenu
*/

#include "map.h"
#include "parsing.h"
#include "player.h"
#include "fd_puts.h"
#include "voir.h"

extern t_map	**map;
extern t_parse	parse;

void	aff_player(t_voir *voir, int fd)
{
  int	i;

  i = map[voir->tmpx][voir->tmpy].nb_player;
  while (i)
    {
      my_putstr("joueur");
      fd_puts(fd, "joueur");
      i--;
      if (i > 0)
	{
	  my_putstr(" ");
	  fd_puts(fd, " ");
	}
      else if (i == 0)
	return ;
    }
}

void	aff_item(t_voir *voir, int fd, int type, char *item)
{
  int	i;

  i = map[voir->tmpx][voir->tmpy].spot[type];
  if (i > 0)
    {
      my_putstr(" ");
      fd_puts(fd, " ");
    }
  while (i)
    {
      my_putstr(item);
      fd_puts(fd, item);
      i--;
      if (i > 0)
	{
	  my_putstr(" ");
	  fd_puts(fd, " ");
	}
    }
}

void	aff_all_item(t_voir *voir, int fd)
{
  aff_item(voir, fd, 0, "nourriture");
  aff_item(voir, fd, 1, "linemate");
  aff_item(voir, fd, 2, "deraumere");
  aff_item(voir, fd, 3, "sibur");
  aff_item(voir, fd, 4, "mendiane");
  aff_item(voir, fd, 5, "phiras");
  aff_item(voir, fd, 6, "thystame");

}

int	aff_case(t_voir *voir, int i, int fd, int dir, int check)
{
  if (i == 1)
    check = 2;
  while (i)
    {
      aff_player(voir, fd);
      aff_all_item(voir, fd);
      if (upgrade_value(voir, dir) == 0)
	upgrade_follow(voir, dir);
      if (i == 1 && check == 1)
	return (0);
      if (i == 1 && check == 2)
	{
	  my_putstr(" ,");
	  fd_puts(fd, " ,");
	  return (0);
	}
      if (i > 1)
	{
	  my_putstr(" ,");
	  fd_puts(fd, " ,");
	}
      i--;
    }
  return (0);
}
