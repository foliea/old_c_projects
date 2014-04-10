/*
** my_print_zero for my_print_zero.c in /u/all/folie_a/cu/rendu/c/my_printf
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Apr 28 17:00:41 2009 adrien folie
** Last update Tue Apr 28 17:09:49 2009 adrien folie
*/

int	my_putchar(char c);

int	my_print_zero(int prec, int j)
{
  int	i;

  i = 0;
  while (i < (prec - j))
    i += my_putchar('0');
  return (i);
}
