/*
** my_str_isnum.c for my_str_isnum in /u/all/folie_a/cu/rendu/piscine/Jour_06
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Tue Mar 17 14:04:39 2009 adrien folie
** Last update Wed May 27 15:49:23 2009 adrien folie
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '-')
    ++i;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	i = i + 1;
      else
	return (0);
    }
  return (1);
}
