/*
** my_strlen.c for my_strlen in /u/all/folie_a/cu/rendu/piscine/Jour_04
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Thu Mar 12 17:18:15 2009 adrien folie
** Last update Fri May  8 16:46:32 2009 thibaut ottemer
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
