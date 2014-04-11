/*
** my_strcmp.c for my strcmp in /u/all/bienve_e/cu/rendu/piscine/Jour_06
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Tue Mar 17 10:00:14 2009 edern bienvenu
** Last update Tue Nov  3 19:10:48 2009 edern bienvenu
*/

int	my_strlen(char *str);

int	my_strcmp(char *str1, char *str2)
{
  int	i;
  int	len1;
  int	len2;

  if (str1 == 0)
    return (1);
  if (str2 == 0)
    return (-1);
  len1 = my_strlen(str1);
  len2 = my_strlen(str2);
  i = 0;
  while (str1 && str2 && str1[i] && str2[i])
    {
      if (str1[i] != str2[i])
        return (str1[i] - str2[i]);
      i++;
    }
  if (i == len1 && i < len2)
    return (-1);
  if (i < len1 && i == len2)
    return (1);
  return (0);
}
