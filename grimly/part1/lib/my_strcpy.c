/*
** my_strcpy.c for my_strcpy in /u/all/lopez_l/cu/rendu/c/minishell1
** 
** Made by leo lopez
** Login   <lopez_l@epitech.net>
** 
** Started on  Thu Jun 11 01:24:29 2009 leo lopez
** Last update Thu Jun 11 01:35:53 2009 leo lopez
*/

char	*my_strcpy(char *src, char *dst)
{
  while (*src)
    *dst++ = *src++;
  return (dst);
}
