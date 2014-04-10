/*
** calc.c for malloc in /u/all/folie_a/cu/rendu/proj/malloc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar 23 05:23:36 2010 adrien folie
** Last update Fri Mar 26 03:56:09 2010 edern bienvenu
*/

int	two_by_power(int n)
{
  int	i;
  int	res;

  i = 0;
  res = 1;
  while (i < n)
    {
      res *= 2;
      ++i;
    }
  return (res);
}

int	power_of_two(int n)
{
  int	i;

  i = 1;
  while (i < n)
    {
      i *= 2;
    }
  return (i);
}

int	multiple_of_two(int n)
{
  int	i;
  int	res;

  i = 1;
  res = 0;
  while (i < n)
    {
      i *= 2;
      res++;
    }
  return (res);
}
