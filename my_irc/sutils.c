/*
** utils.c for irc in /u/epitech_2013/bienve_e/cu/rendu/c/my_irc
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Mon Apr 19 16:20:50 2010 edern bienvenu
** Last update Wed Apr 28 02:00:24 2010 edern bienvenu
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putchar(char c)
{
  write(1, &c, 1);

}

void	my_putnbr(int nb)
{
  int	debut;
  int	fin;

  if (nb < 0)
    {
      my_putchar('-');
      my_putnbr(-nb);
    }
  else
    {
      fin = nb % 10;
      debut = nb / 10;
      if (debut != 0)
	my_putnbr(debut);
      my_putchar(fin + '0');
    }
  return ;
}

int	tablen(char **cmd)
{
  int	i;

  i = 0;
  while (cmd[i])
    i++;
  return (i);
}
