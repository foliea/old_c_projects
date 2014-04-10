/*
** my_strcapitalize.c for my_strcapitalize in /u/all/folie_a/cu/rendu/piscine/Jour_06
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar 17 10:41:14 2009 adrien folie
** Last update Tue Mar 17 15:50:05 2009 adrien folie
*/

char	*my_strcapitalize(char *str)
{
  int	i;
  int	no;

  i = 0;
  no = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= 'a') && (str[i] <= 'z'))
	{
	if (no != 1)
	  {
	    str[i] = str[i] - 32;
	    no = 1;
	  }
	}
      else
	no = 0;
      if ((str[i] >= '0') && (str[i] <= '9'))
	no = 1;
      i = i + 1;
      if ((str[i] >= 'A') && (str[i] <= 'Z'))
	str[i] = str [i] + 32; 
    }
  return (str);
}
