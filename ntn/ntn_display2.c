/*
** ntn_display2.c for ntn_display2.c in /u/all/folie_a/cu/rendu/c/proj/ntn
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Sun May 24 15:32:20 2009 adrien folie
** Last update Sun May 24 23:30:46 2009 adrien folie
*/

#include "ntn.h"

void    ntn_milliers(int i, char *str)
{
  if (check_str_limit(i - 4, str) == 1)
    {
      if (check2_str(i, str) == 1)
        my_putchar(' ');
      if (str[i + 3] == '\0')
        my_putstr("mille");
      if (str[i] != '0')
        my_putchar(' ');
    }
}

void	etape_int(char *str, int *i, int *pos)
{
  int	j;

  j = *i;
  if (!(str[j] == '0' && str[j + 1] == '0' && str[j + 2] == '1' && *pos == 6))
    ntn_centaine(str[j], str[j + 1], str[j + 2]);
  *pos = *pos - 3;
  *i = *i + 3;
}

void	ntn_display(char *str, int i, int pos)
{
  while (pos != 0)
    {
      if (pos == 3 || pos == 6 || pos == 9 || pos == 12)
	etape_int(str, &i, &pos);
      else if (pos == 2 || pos == 5 || pos == 8 || pos == 11)
        {
          ntn_dizaine(str[i], str[i + 1]);
	  pos = pos - 2;
          i = i + 2;
        }
      else if (pos == 1 || pos == 4 || pos == 7 || pos == 10)
        {
          if (pos == 1 || ((pos == 4 || pos == 7 || pos == 10) && str[i] != '1'))
            print_unit(str[i]);
	  --pos;
          ++i;
        }
      if (str[i] != '\0' && (pos >= 3 && pos <= 5))
	ntn_milliers(i, str);
      if (str[i] != '\0' && (pos >= 6 && pos <= 8))
	ntn_millions(str[i - 1], i, str);
      if (str[i] != '\0' && (pos >= 9 && pos <= 11))
	ntn_milliards(str[i - 1], i, str);
    }
}
