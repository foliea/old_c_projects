/*
** my_str_islower.c for my_str_islower in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar 17 15:51:45 2009 adrien folie
** Last update Tue Mar 17 15:58:56 2009 adrien folie
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 'a' && str[i] <= 'z')
        i = i + 1;
      else
        return (0);
    }
  return (1);
}
