/*
** my_getnbr.c for my_getnbr in /u/all/otteme_t/cu/rendu/piscine/sapin
** 
** Made by thibaut ottemer
** Login   <otteme_t@epitech.net>
** 
** Started on  Sun Mar 15 09:34:06 2009 thibaut ottemer
** Last update Mon Mar 23 15:16:40 2009 thibaut ottemer
*/

int	my_getnbr(char *str)
{
  int	a;
  int	b;

  b = 0;
  a = 0;
  while ((*str == '-') || (*str == '+'))
    {
      if (*str == '-')
        {
          b = b + 1;
          str = str + 1;
        }
      if (*str == '+')
	str = str + 1;
    }
  while ((*str != '\0') && (*str >= '0') && (*str <= '9'))
    {
      a = (*str - '0') + (10 * a);
      str = str + 1;
    }
  if (b % 2 == 1)
    a = a * -1;
  return (a);
}
