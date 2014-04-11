/*
** my_strcat.c for my_strcat in /u/all/folie_a/cu/rendu/piscine/Jour_07
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Mar 18 11:51:32 2009 adrien folie
** Last update Wed Mar 18 12:02:35 2009 adrien folie
*/

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str1[i] != '\0')
    i = i + 1;
  while (str2[j] != '\0')
    {
      str1[i] = str2[j];
      i = i + 1;
      j = j + 1;
    }
  return (str1); 
}
