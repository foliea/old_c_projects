/*
** utils.c for my_irc in /u/all/bienve_e/rendu/c/my_irc/client
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sat Apr 24 21:15:28 2010 edern bienvenu
** Last update Wed Apr 28 02:00:32 2010 adrien folie
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>

void	my_putstr(char *str)
{
  write(1, str, strlen(str));
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
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
