/*
** my_show_to_wordbad.c for my_show_to_wordtab in /u/all/folie_a/cu/rendu/piscine/Jour_08
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar 19 20:58:23 2009 adrien folie
** Last update Sat Mar 21 00:15:41 2009 adrien folie
*/

int	my_putstr_in(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

int	my_show_to_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr_in(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
