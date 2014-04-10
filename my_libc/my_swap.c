/*
** my_swap.c for my_swap in /u/all/folie_a/cu/rendu/piscine
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar 12 09:58:28 2009 adrien folie
** Last update Fri Mar 20 10:32:17 2009 adrien folie
*/

int	my_swap(int *a, int *b)
{
  int	temp;

  temp = *a;
  *a = *b;
  *b = temp;
  return (0);
}


