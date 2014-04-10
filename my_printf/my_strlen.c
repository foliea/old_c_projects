/*
** my_strlen.c for my_strlen in /u/all/folie_a/cu/rendu/piscine/Jour_04
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar 12 17:18:15 2009 adrien folie
** Last update Tue Mar 17 21:23:07 2009 adrien folie
*/

int	my_strlen(char *strlen)
{
  int	i;

  i = 0;
  while (strlen[i] != '\0')
    i = i + 1;
  return (i);
}



