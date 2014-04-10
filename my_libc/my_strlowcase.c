/*
** my_strlowcase.c for my_strlowcase in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar 17 00:20:11 2009 adrien folie
** Last update Tue Mar 17 14:36:02 2009 adrien folie
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 'A') && (str[i] <= 'Z'))
        str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}

