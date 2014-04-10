/*
** my_is_prime.c for my_is_prime in /u/all/folie_a/cu/rendu/piscine/Jour_05
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri Mar 13 22:34:01 2009 adrien folie
** Last update Mon Mar 16 20:40:51 2009 adrien folie
*/

int	my_is_prime(int nombre)
{
  int	i;
  int	j;

  i = 2;
  while (i < nombre)
    {
      j = nombre % i; 
      if (j == 0)
	{
	  return (0); 
	}
      i = i + 1;
    }
  return (1);
}

