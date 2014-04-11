/*
** mns_recup_bin.c for mns_recup_bin in /u/all/folie_a/cu/rendu/c/minishell1
**
** Made by adrien folie
** Login   <folie_a@epitech.net>
**
** Started on  Mon Jun  1 03:52:41 2009 adrien folie
** Last update Sat Oct  3 02:43:47 2009 adrien folie
*/

#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char	**mns_recup_bin(char **env)
{
  char	**tab;
  char	*path;

  tab = NULL;
  if (env == NULL)
    tab = mns_do_absolute();
  else
    {
      path = my_getenv(env, "PATH=");
      if (path == NULL)
	tab = mns_do_absolute();
      else
	tab = my_str_to_wordtab(path, ':', 0);
    }
  free(path);
  return (tab);
}

char	**mns_do_absolute(void)
{
  char	**tab;

  tab = malloc(17 * sizeof(*tab));
  if (tab == NULL)
    my_error_report(7);
  tab[0] = my_strdup("/usr/site/sbin");
  tab[1] = my_strdup("/usr/site/bin");
  tab[2] = my_strdup("/usr/netsoul/sbin");
  tab[3] = my_strdup("/usr/netsoul/bin");
  tab[4] = my_strdup("/usr/heimdal/sbin");
  tab[5] = my_strdup("/usr/heimdal/bin");
  tab[6] = my_strdup("/usr/arla/sbin");
  tab[7] = my_strdup("/usr/arla/bin");
  tab[8] = my_strdup("/usr/local/sbin");
  tab[9] = my_strdup("/usr/local/bin");
  tab[10] = my_strdup("/usr/sbin");
  tab[11] = my_strdup("/usr/bin");
  tab[12] = my_strdup("/sbin");
  tab[13] = my_strdup("/bin");
  tab[14] = my_strdup("/usr/sfw/bin");
  tab[15] = my_strdup("/usr/ccs/bin");
  tab[16] = NULL;
  return (tab);
}
