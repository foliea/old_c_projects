/*
** my_strupcase.c for my_strupcase in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Mar 16 23:03:33 2009 adrien folie
** Last update Tue Mar 17 10:31:38 2009 adrien folie
*/

char	*my_strupcase(char *str)
{
  int	i;
  
  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 'a') && (str[i] <= 'z'))
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
