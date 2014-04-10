/*
** my_str_isalpha.c for my_str_isalpha in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar 17 13:27:28 2009 adrien folie
** Last update Tue Mar 17 15:11:04 2009 adrien folie
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if ((str[i] >= 'a' && str[i] <= 'z') ||
	(str[i] >= 'A' && str[i] <= 'Z'))
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
