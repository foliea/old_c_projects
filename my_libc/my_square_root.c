/*
** my_square_root.c for my_square_root in /u/all/folie_a/cu/rendu/piscine/Jour_05
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Mar 13 21:40:27 2009 adrien folie
** Last update Thu Mar 19 17:52:00 2009 adrien folie
*/

int	my_square_root(int nb)
{
  int	i;

  i = 0;
  while (i*i < nb)
    {
      i = i + 1;
      if (i*i == nb)
	{
	  return (i);
	}
    }
  return (0);
}
