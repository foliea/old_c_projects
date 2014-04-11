/*
** direct_move.c for lemipc in /u/all/folie_a/cu/public/dedern/lemipc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 21 17:10:03 2010 adrien folie
** Last update Sun May 23 19:46:10 2010 edern bienvenu
*/

#include <stdio.h>
#include <stdlib.h>
#include "lemipc.h"

int	do_left(t_data *data)
{
  if (data->pos % WIDTH == 0)
    return (1);
  if (data->map[data->pos - 1] == '0')
    {
      data->map[data->pos] = '0';
      data->pos--;
      data->map[data->pos] = data->team + '0';
      return (0);
    }
  return (1);
}

int	do_right(t_data *data)
{
  if ((data->pos + 1) % WIDTH == 0)
    return (1);
  if (data->map[data->pos + 1] == '0')
    {
      data->map[data->pos] = '0';
      data->pos++;
      data->map[data->pos] = data->team + '0';
      return (0);
    }
  return (1);
}

int	do_up(t_data *data)
{
  if (data->pos - WIDTH < 0)
    return (1);
  if (data->map[data->pos - WIDTH] == '0')
    {
      data->map[data->pos] = '0';
      data->pos -= WIDTH;
      data->map[data->pos] = data->team + '0';
      return (0);
    }
  return (1);
}

int	do_down(t_data *data)
{
  if (data->pos + WIDTH > (WIDTH * HEIGHT))
    return (1);
  if (data->map[data->pos + WIDTH] == '0')
    {
      data->map[data->pos] = '0';
      data->pos += WIDTH;
      data->map[data->pos] = data->team + '0';
      return (0);
    }
  return (1);
}

void		random_move(t_data *data)
{
  int		move;
  int		ok;

  ok = 1;
  while (ok)
    {
      move = rand() % 4;
      if (move == 0)
	ok = do_left(data);
      if (move == 1)
	ok = do_right(data);
      if (move == 2)
	ok = do_up(data);
      if (move == 3)
	ok = do_down(data);
    }
}
