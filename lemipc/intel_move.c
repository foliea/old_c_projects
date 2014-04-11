/*
** intel_move.c for lemipc in /u/all/folie_a/public/dedern/lemipc
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun May 23 13:45:53 2010 edern bienvenu
** Last update Sun May 23 21:52:11 2010 edern bienvenu
*/

#include <stdio.h>
#include "lemipc.h"

void	recup_pos(int pos, t_brain *brain, int check)
{
  if (check == 0)
    {
      brain->x_target = pos % WIDTH;
      brain->y_target = pos / WIDTH;
    }
  else if (check == 1)
    {
      brain->x_me = pos % WIDTH;
      brain->y_me = pos / WIDTH;
    }
}

void	end_moving(t_brain *brain, t_data *data, int x, int y)
{
  if (x <= y)
    {
      if (brain->diff_x > 0 && data->pos > WIDTH + 1
	  && data->map[data->pos - WIDTH] == '0')
	do_up(data);
      else if ((data->pos / WIDTH) < HEIGHT - 1 
	       && data->map[data->pos + WIDTH] == '0')
	do_down(data);
    }
  else
    {
      if (brain->diff_y > 0 && data->pos > 0 &&
	  data->map[data->pos - 1] == '0')
	do_left(data);
      else if (data->pos < (WIDTH * HEIGHT) && data->map[data->pos + 1] == '0')
	do_right(data);
    }
}

void	moving(t_brain *brain, t_data *data)
{
  int	tmpx;
  int	tmpy;

  brain->diff_x = brain->x_me - brain->x_target;
  if ((tmpx = brain->diff_x) < 0)
    tmpx *= -1;
  brain->diff_y = brain->y_me - brain->y_target;
  if ((tmpy = brain->diff_y) < 0)
    tmpy *= -1;
  end_moving(brain, data, tmpx, tmpy);
}

void		intel_move(t_data *data)
{
  t_brain	brain;

  if (data->target != -1)
    {
      brain.x_me = 0;
      brain.y_me = 0;
      brain.x_target = 0;
      brain.y_target = 0;
      recup_pos(data->pos, &brain, 1);
      recup_pos(data->target, &brain, 0);
      moving(&brain, data);
      if (data->pos == data->target)
	data->target = -1;
    }
  else
    random_move(data);
}
