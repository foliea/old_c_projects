/*
** my_str_isprintable.c for my_str_isprintable in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar 17 16:03:12 2009 adrien folie
** Last update Fri Mar 20 10:29:57 2009 adrien folie
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= ' ' && str[i] <= '~')
        i = i + 1;
      else
        return (0);
    }
  return (1);
}

