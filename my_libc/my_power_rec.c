/*
** my_power_rec.c for my_power_rec in /u/all/folie_a/cu/rendu/piscine/Jour_05
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Mar 13 18:11:56 2009 adrien folie
** Last update Mon Mar 16 15:52:43 2009 adrien folie
*/

int	my_power_rec(int nb, int power)
{
  if (nb < 0)
    {
      return (0);
    }
  if (power == 0)
    {
      return (1);
    }
  if (power > 0)
    {
      return (nb * my_power_rec(nb, (power - 1)));
    }
  else
    {
      return (1);
    }
}



