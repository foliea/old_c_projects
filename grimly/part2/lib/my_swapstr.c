/*
** my_swapstr.c for my_swapstr in /u/all/folie_a/cu/rendu/lib/my
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Mar 23 18:23:45 2009 adrien folie
** Last update Tue Nov  3 14:50:55 2009 leo lopez
*/

int	my_swapstr(char **str1, char **str2)
{
  char	*temp;
  
  temp = *str1;
  *str1 = *str2;
  *str2 = temp;
  return (0);
}
