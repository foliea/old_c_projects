/*
** my_strncmp.c for my_strncmp in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Mar 16 22:55:58 2009 adrien folie
** Last update Tue Mar 17 16:51:28 2009 adrien folie
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;
  int	diff;

  i = 0;
  diff = 0;
  while ((s1[i] == s2[i]) && (n != 0) 
	 && ((s1[i] != '\0') || (s2[i] != '\0')))
    {
      i = i + 1;
      n = n - 1;
    }
  if (s1[i] == s2[i])
    return (0);
  diff = s1[i] - s2[i];
  return (diff);
}
