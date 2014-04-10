/*
** my_strstr.c for my_strstr in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Mar 16 14:16:54 2009 adrien folie
** Last update Tue Mar 17 10:32:59 2009 adrien folie
*/

char	*my_strstr(char *str, char *to_find)
{
  int	save;
  int	i;
  int	a;

  a = 0;
  i = 0;
  save = 0;
  while (str[i] != '\0')
    {
      save = i;
      while ((str[i] == to_find[a]) && ((str[i] != '\0') 
					|| (to_find[a] != '\0')))
	{
	  i = i + 1;
	  a = a + 1;
	}
      if (to_find[a] == '\0') 
	return (&str[save]);
      a = 0;
      i = i + 1;
    }
  return (0);
}

