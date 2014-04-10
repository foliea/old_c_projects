/*
** my_strncpy.c for my_strncpy in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Mar 16 11:19:11 2009 adrien folie
** Last update Thu Mar 19 00:27:06 2009 adrien folie
*/

char    *my_strncpy(char *dest, char *src, int n)
{
  int   i;
  int	max_str;

  i = 0;
  max_str = my_strlen(src);
  while ( i <  n)
    {
      dest[i] = src[i];
      i = i + 1;
      if (n >= max_str)
	dest[max_str + 1] = '\0';
    }
  return (dest);
}

