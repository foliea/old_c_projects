/*
** inttostr.c for my irc in /u/all/folie_a/public/dedern/server
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Tue Apr 27 21:06:27 2010 edern bienvenu
** Last update Tue Apr 27 21:06:28 2010 edern bienvenu
*/

void	*xmalloc(int size);

char	*inttostr(int nb)
{
  int	div;
  int	i;
  char	*str;

  str = xmalloc(4);
  div = 1;
  i = 0;
  if (nb == 0)
    str[i] = '0';
  if (nb < 0)
    {
      str[i] = '-';
      i++;
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
