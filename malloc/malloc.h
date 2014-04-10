/*
** malloc.h for malloc in /u/all/folie_a/cu/rendu/proj/malloc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Tue Mar  2 02:13:27 2010 adrien folie
** Last update Fri Apr  2 01:34:02 2010 adrien folie
*/

#ifndef MALLOC_H
#define MALLOC_H

#define MAGIC 73146

typedef struct			s_block_descriptor
{
  unsigned int			p; /* puissance de 2 de la taille du bloc*/
  struct s_block_descriptor	*next; /* pointeur sur un autre bloc*/
  int				magic;
}				t_block_descriptor;

void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	free(void *ptr);
void	show_alloc_mem(void);
void	*find_in_freelist(int p);
int	is_already_free(t_block_descriptor *list, t_block_descriptor *ptr);
int	check_chunk(t_block_descriptor *ptr);
int	is_malloc(t_block_descriptor *ptr, int to_free);
int	ret_from_list(t_block_descriptor *ptr);
int	two_by_power(int n);
int	power_of_two(int n);
int	multiple_of_two(int n);
int	my_put_error(char *str);

#endif
