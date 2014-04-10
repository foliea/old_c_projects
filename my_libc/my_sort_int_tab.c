/*
** my_sort_int_tab.c for my_sort_int_tab in /u/all/folie_a/cu/rendu/piscine/Jour_04
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar 17 17:17:13 2009 adrien folie
** Last update Thu Mar 19 00:33:09 2009 adrien folie
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (j < 1000)
    {
      while (i < size)
	{
	  if (i == size - 1)
	    {
	      if (tab[i] < tab[i - 1])
		my_swap(&tab[i], &tab[i - 1]);
	    }
	  else if (tab[i] > tab[i + 1])
	    my_swap(&tab[i], &tab[i + 1]);
	  i = i + 1;
	}
      i = 0;
      j = j + 1;
    }
}
