/*
** my_strlcat.c for my_strlcat in /u/all/folie_a/cu/rendu/piscine/Jour_07
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Wed Mar 18 12:06:41 2009 adrien folie
** Last update Wed Mar 18 12:15:32 2009 adrien folie
*/

char	*my_strlcat(char *str1, char *str2, int l)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while ((str1[i] != '\0') && (l > 0))
    {
      i = i + 1;
      l = l - 1;
    }
  while ((str2[j] != '\0') && (l > 0))
    {
      str1[i] = str2[j];
      i = i + 1;
      j = j + 1;
      l = l - 1;
    }
  str1[i] = '\0'; 
  return (str1);
}
