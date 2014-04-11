/*
** tab_utils.c for tab_utils in /u/all/folie_a/cu/rendu/c/minishell1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Jun  1 23:13:34 2009 adrien folie
** Last update Mon Oct  5 10:31:08 2009 adrien folie
*/

#include <stdlib.h>
void	my_putchar(char c);
int	my_putstr(char *str);
char	*my_strdup(char *str);

void	my_show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      ++i;
    }
}

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
}

int	my_tab_len(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  return (i);
}

char	**my_tab_dup(char **tab)
{
  int	i;
  char	**cpy;

  i = 0;
  cpy = malloc((my_tab_len(tab) + 1) * sizeof(*tab));
  while (tab[i] != NULL)
    {
      cpy[i] = my_strdup(tab[i]);
      ++i;
    }
  cpy[i] = NULL;
  return (cpy);
}

