/*
** my_revstr.c for my_revstr in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Mar 16 11:37:17 2009 adrien folie
** Last update Thu Mar 19 00:25:15 2009 adrien folie
*/

char	*my_revstr(char *str)
{
  int   i;
  int   end;

  i = 0;
  end = my_strlen(str) - 1;
  while (i <= end)
    {
      my_swap(&str[i], &str[end]);
      i = i + 1;
      end = end - 1;
    }
  return (str);
}
