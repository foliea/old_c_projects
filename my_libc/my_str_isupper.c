/*
** my_str_isupper.c for my_str_isupper in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar 17 15:56:59 2009 adrien folie
** Last update Tue Mar 17 16:01:07 2009 adrien folie
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
        i = i + 1;
      else
        return (0);
    }
  return (1);
}
