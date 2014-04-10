/*
** my_strncat.c for my_strncat in /u/all/folie_a/cu/rendu/piscine/Jour_07
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Mar 18 12:00:59 2009 adrien folie
** Last update Wed Mar 18 12:08:44 2009 adrien folie
*/

char	*my_strncat(char *str1, char *str2, int n)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str1[i] != '\0')
    i = i + 1;
  while ((str2[j] != '\0') && (n > 0)) 
    {
      str1[i] = str2[j];
      i = i + 1;
      j = j + 1;
      n = n - 1;
    }
  return (str1);
}
