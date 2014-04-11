/*
** my_put_nbr.c for my put nbr in /u/all/bienve_e/cu/rendu/piscine/Jour_03
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri Mar 13 09:07:33 2009 edern bienvenu
** Last update Mon Oct 12 16:22:32 2009 edern bienvenu
*/

void	my_put_nbr(int nb)
{
  int	debut;
  int	fin;

  if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr(-nb);
    }
  else
    {
      fin = nb % 10;
      debut = nb / 10;
      if (debut != 0)
	my_put_nbr(debut);
      my_putchar(fin + '0');
    }
  return ;
}
