/*
** my_getnbr.c for my_getnbr in /u/all/folie_a/cu/rendu/piscine/Jour_04
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar 12 21:59:35 2009 adrien folie
** Last update Tue Apr 28 11:20:12 2009 adrien folie
*/

int	my_getnbr(char *str)
{
  int	i;
  int	sign;
  int	final;
  
  i = 0;
  sign = 1;
  final = 0;
  while ((str[i] == '-') || (str[i] == '+'))
    {
      if (str[i] == '-')
	{	
	  sign = - sign;
	}
      i = i + 1;
    }
  while ((str[i] >= '0') && (str[i] <= '9'))
    {
      final = (final * 10 - '0' + str[i]);
      i = i + 1;
    }
  return (sign * final);
}
