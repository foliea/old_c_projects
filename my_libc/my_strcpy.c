/*
** my_strcpy.c for my_strcpy in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Mar 16 10:31:35 2009 adrien folie
** Last update Thu Mar 19 00:26:30 2009 adrien folie
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;
  
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
      dest[my_strlen(src) + 1] = '\0';
    }
  return (dest);
}

