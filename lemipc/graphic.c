/*
** graphic.c for lemipc in /u/all/folie_a/cu/public/dedern/lemipc
** 
** Made by adrien folie
** Login   <folie_a@epitech.net>
** 
** Started on  Fri May 21 17:11:22 2010 adrien folie
** Last update Sun May 23 21:58:58 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include <termcap.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <termios.h>
#include "lemipc.h"
#include "caps.h"

int	check_game(char *map)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (map[i])
    {
      if (map[i] != '0')
	j++;
      ++i;
    }
  return (j);
}

void	show_map(char *map)
{
  int	i;

  i = 0;
  while (map[i] != '\0')
    {
      putchar(map[i]);
      ++i;
      if (i % WIDTH == 0)
        putchar('\n');
    }
}

char	*load_map(void)
{
  char	*map;
  key_t	key;
  int	shm_id;

  if ((key = ftok(".", 0)) == -1)
    aff_error("Ftok failed");
  if ((shm_id = shmget(key, WIDTH * HEIGHT + 1, SHM_R | SHM_W)) == -1)
    aff_error("Shmget failed");
  if ((map = shmat(shm_id, NULL, 0)) == NULL)
    aff_error("Shmat failed");
  return (map);
}

void		aff_loop(void)
{
  char		*map;
  t_caps	caps;

  map = load_map();
  init_caps(&caps);
  start_terminal(&caps);
  while (42)
    {
      tputs(tgoto(caps.cmstr, 0, 0), 1, my_outc);
      if (check_game(map) == 0)
	{
	  tputs(caps.clstr, 1, my_outc);
	  puts("Game Over");
	  exit(EXIT_SUCCESS);
	}
      show_map(map);
    }
}

int	main()
{
  aff_loop();
  return (0);
}
