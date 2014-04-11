/*
** find_target.c for lemipc in /u/all/folie_a/cu/public/dedern/lemipc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 21 17:10:16 2010 adrien folie
** Last update Sun May 23 19:37:08 2010 edern bienvenu
*/

#include "lemipc.h"

int	check_card(t_data *data)
{
  if (data->pos % WIDTH != 0)
    if (data->map[data->pos - 1] != data->team + '0'
	&& data->map[data->pos - 1] != '0')
      return (data->pos - 1);
  if ((data->pos + 1) % WIDTH != 0)
    if (data->map[data->pos + 1] != data->team + '0'
	&& data->map[data->pos + 1] != '0')
      return (data->pos + 1);
  if (data->pos - WIDTH > 0)
    if (data->map[data->pos - WIDTH] != data->team + '0'
	&& data->map[data->pos - WIDTH] != '0')
      return (data->pos - WIDTH);
  if (data->pos + WIDTH < (WIDTH * HEIGHT))
    if (data->map[data->pos + WIDTH] != data->team + '0'
	&& data->map[data->pos + WIDTH] != '0')
      return (data->pos + WIDTH);
  return (-1);
}

int	check_diag(t_data *data)
{
  if (data->pos % WIDTH != 0 && data->pos - WIDTH - 1 > 0)
    if (data->map[data->pos - WIDTH - 1] != data->team + '0'
	&& data->map[data->pos - WIDTH - 1] != '0')
      return (data->pos - WIDTH - 1);
  if ((data->pos + 1) % WIDTH != 0
      && data->pos - WIDTH + 1 > 0)
    if (data->map[data->pos - WIDTH + 1] != data->team + '0'
	&& data->map[data->pos - WIDTH + 1] != '0')
      return (data->pos - WIDTH + 1);
  if (data->pos % WIDTH != 0
      && data->pos + WIDTH - 1 < (WIDTH * HEIGHT))
    if (data->map[data->pos + WIDTH - 1] != data->team + '0'
	&& data->map[data->pos + WIDTH - 1] != '0')
      return (data->pos + WIDTH - 1);
  if ((data->pos + 1) % WIDTH != 0
      && data->pos + WIDTH + 1 < (WIDTH * HEIGHT))
    if (data->map[data->pos + WIDTH + 1] != data->team + '0'
	&& data->map[data->pos + WIDTH + 1] != '0')
      return (data->pos + WIDTH + 1);
  return (-1);
}

int	find_target(t_data *data)
{
  int res;

  res = -1;
  if ((res = check_card(data)) == -1)
    res = check_diag(data);
  return (res);
}
