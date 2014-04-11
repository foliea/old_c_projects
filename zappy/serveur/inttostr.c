/*
** inttostr.c for zappy in /u/all/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Thu Jun 17 17:16:47 2010 edern bienvenu
** Last update Sun Jun 20 17:42:00 2010 edern bienvenu
*/

#include <string.h>

void	*xmalloc(int size);

char	*inttostr(int nb)
{
  int	div;
  int	i;
  char	*str;

  str = xmalloc(32);
  memset(str, 0, 32);
  div = 1;
  i = 0;
  if (nb == 0)
    str[i] = '0';
  if (nb < 0)
    {
      str[i++] = '-';
      nb = -nb;
    }
  while (nb / div > 9)
    div = div * 10;
  while (div != 0)
    {
      str[i] = nb / div + '0';
      nb = nb % div;
      div = div / 10;
      i++;
    }
  return (str);
}
