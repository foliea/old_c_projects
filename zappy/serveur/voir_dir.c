/*
** voir_dir.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun Jun 20 18:38:37 2010 edern bienvenu
** Last update Sun Jun 20 18:42:45 2010 edern bienvenu
*/

#include "map.h"
#include "parsing.h"
#include "player.h"
#include "fd_puts.h"
#include "voir.h"

extern t_map	**map;
extern t_parse	parse;

void		voir_up(t_player *player, int nb_spot, int fd, int dir)
{
  int		i;
  int		z;
  int		tmp;
  t_voir	voir;

  i = 1;
  tmp = 1;
  z = 0;
  voir.posx = player->posx;
  voir.posy = player->posy;
  voir.tmpx = player->posx;
  voir.tmpy = player->posy;
  my_putstr("{ ");
  fd_puts(fd, "{ ");
  while (i <= nb_spot)
    {
      verif_pos_voir(&voir, -z);
      tmp = aff_case(&voir, i, fd, dir, tmp);
      i = i + 2;
      z++;
    }
  my_putstr(" }\n");
  fd_puts(fd, " }\n");
}

void	voir_down(t_player *player, int nb_spot, int fd, int dir)
{
  int		i;
  int		z;
  int		tmp;
  t_voir	voir;

  i = 1;
  tmp = 1;
  z = 0;
  voir.posx = player->posx;
  voir.posy = player->posy;
  voir.tmpx = player->posx;
  voir.tmpy = player->posy;
  my_putstr("{ ");
  fd_puts(fd, "{ ");
  while (i <= nb_spot)
    {
      verif_pos_voir(&voir, z);
      tmp = aff_case(&voir, i, fd, dir, tmp);
      i = i + 2;
      z++;
    }
  my_putstr(" }\n");
  fd_puts(fd, " }\n");
}

void	voir_right(t_player *player, int nb_spot, int fd, int dir)
{
  int		i;
  int		z;
  int		tmp;
  t_voir	voir;

  i = 1;
  tmp = 1;
  z = 0;
  voir.posx = player->posx;
  voir.posy = player->posy;
  voir.tmpx = player->posx;
  voir.tmpy = player->posy;
  my_putstr("{ ");
  fd_puts(fd, "{ ");
  while (i <= nb_spot)
    {
      verif_pos_voir(&voir, z);
      tmp = aff_case(&voir, i, fd, dir, tmp);
      i += 2;
      z++;
    }
  my_putstr(" }\n");
  fd_puts(fd, " }\n");
}

void	voir_left(t_player *player, int nb_spot, int fd, int dir)
{
  int		i;
  int		z;
  int		tmp;
  t_voir	voir;

  i = 1;
  tmp = 1;
  z = 0;
  voir.posx = player->posx;
  voir.posy = player->posy;
  voir.tmpx = player->posx;
  voir.tmpy = player->posy;
  my_putstr("{ ");
  fd_puts(fd, "{ ");
  while (i <= nb_spot)
    {
      verif_pos_voir(&voir, -z);
      tmp = aff_case(&voir, i, fd, dir, tmp);
      i = i + 2;
      z++;
    }
  my_putstr(" }\n");
  fd_puts(fd, " }\n");
}

void	voir_by_lvl(t_player *player, int nb_spot, int fd)
{
  if (player->direct == UP)
    voir_up(player, nb_spot, fd, UP);
  else if (player->lvl == DOWN)
    voir_down(player, nb_spot, fd, DOWN);
  else if (player->lvl == LEFT)
    voir_left(player, nb_spot, fd, LEFT);
  else if (player->lvl == RIGHT)
    voir_right(player, nb_spot, fd, RIGHT);
}
