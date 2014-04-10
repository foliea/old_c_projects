/*
** my_swap_str.c for my_swap_str in /u/all/folie_a/cu/rendu/lib/my
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Mon Mar 23 18:23:45 2009 adrien folie
** Last update Mon Mar 23 18:27:01 2009 adrien folie
*/

int	my_swap_str(char **str1, char **str2)
{
  char	*temp;
  
  temp = *str1;
  *str1 = *str2;
  *str2 = temp;
  return (0);
}
