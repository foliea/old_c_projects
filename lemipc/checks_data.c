/*
** checks_data.c for lemipc in /u/all/folie_a/cu/public/dedern/lemipc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 21 17:08:25 2010 adrien folie
** Last update Sun May 23 19:43:46 2010 edern bienvenu
*/

#include <stdio.h>
#include "lemipc.h"

int	lcheck_card(t_data *data)
{
  int	res;

  res = 0;
  if (data->pos % WIDTH != 0)
    if (data->map[data->pos - 1] != data->team + '0'
	&& data->map[data->pos - 1] != '0')
      res++;
  if ((data->pos + 1) % WIDTH != 0)
    if (data->map[data->pos + 1] != data->team + '0'
	&& data->map[data->pos + 1] != '0')
      res++;
  if (data->pos - WIDTH > 0)
    if (data->map[data->pos - WIDTH] != data->team + '0'
	&& data->map[data->pos - WIDTH] != '0')
      res++;
  if (data->pos + WIDTH < (WIDTH * HEIGHT))
    if (data->map[data->pos + WIDTH] != data->team + '0'
	&& data->map[data->pos + WIDTH] != '0')
      res++;
  return (res);
}

int	lcheck_diag(t_data *data)
{
  int	res;

  res = 0;
  if (data->pos % WIDTH != 0 && data->pos - WIDTH - 1 > 0)
    if (data->map[data->pos - WIDTH - 1] != data->team + '0'
	&& data->map[data->pos - WIDTH - 1] != '0')
      res++;
  if ((data->pos + 1) % WIDTH != 0
      && data->pos - WIDTH + 1 > 0)
    if (data->map[data->pos - WIDTH + 1] != data->team + '0'
	&& data->map[data->pos - WIDTH + 1] != '0')
      res++;
  if (data->pos % WIDTH != 0
      && data->pos + WIDTH - 1 < (WIDTH * HEIGHT))
    if (data->map[data->pos + WIDTH - 1] != data->team + '0'
	&& data->map[data->pos + WIDTH - 1] != '0')
      res++;
  if ((data->pos + 1) % WIDTH != 0
      && data->pos + WIDTH + 1 < (WIDTH * HEIGHT))
    if (data->map[data->pos + WIDTH + 1] != data->team + '0'
	&& data->map[data->pos + WIDTH + 1] != '0')
      res++;
  return (res);
}

void	check_lose(t_data *data)
{
  int res;

  res = 0;
  res += lcheck_card(data);
  res += lcheck_diag(data);
  if (res >= 2)
    {
      puts("You lose");
      handler(0);
    }
  return ;
}

int	check_if_last(char *map)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (map[i] != '\0')
    {
      if (map[i] != '0')
	j++;
      ++i;
    }
  return (j);
}
