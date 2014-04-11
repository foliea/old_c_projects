/*
** gere_inv.c for  in /u/all/bienve_e/public/zappy/2_antoine/client
** 
** Made by antoine goueslard
** Login   <gouesl_a@epitech.net>
** 
** Started on  Tue Jun 15 04:06:54 2010 antoine goueslard
** Last update Sun Jun 20 14:35:52 2010 antoine goueslard
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "client.h"

extern	t_play	player;

void	print_inv(t_inv inv)
{
  printf("Life : %i\n",inv.life);
  printf("Linemate : %i\n",inv.l);
  printf("deraumere : %i\n",inv.d);
  printf("sibur : %i\n",inv.s);
  printf("mendiane : %i\n",inv.m);
  printf("phiras : %i\n",inv.p);
  printf("thistame : %i\n",inv.t);
}

void	ff_inv(char *ans)
{
  char	**tab;

  ans[strlen(ans) -1] = 0;
  tab = stotab(ans, ',');
  player.inv.life = atoi(&tab[0][10]);
  player.inv.l = atoi(&tab[1][8]);
  player.inv.d = atoi(&tab[2][9]);
  player.inv.s = atoi(&tab[3][5]);
  player.inv.m = atoi(&tab[4][8]);
  player.inv.p = atoi(&tab[5][6]);
  player.inv.t = atoi(&tab[6][8]);
  player.inv.joueurs = 0;
  free(tab);
}

t_inv	newcase(void)
{
  t_inv cas;

  cas.life = 0;
  cas.l = 0;
  cas.d = 0;
  cas.s = 0;
  cas.m = 0;
  cas.p = 0;
  cas.t = 0;
  cas.joueurs = 0;
  return (cas);
}

t_inv	get_case(char **tab)
{
  t_inv	cas;
  int	i;
  
  cas = newcase();
  i = 0;
  while (tab[i] != 0)
    {
      if (strcmp(tab[i],"nourriture") == 0)
	cas.life += 1;
      else if (strcmp(tab[i],"linemate") == 0)
	cas.l += 1;
      else if (strcmp(tab[i],"deraumere") == 0)
	cas.d += 1;
      else if (strcmp(tab[i],"sibur") == 0)
	cas.s += 1;
      else if (strcmp(tab[i],"mendiane") == 0)
	cas.m += 1;
      else if (strcmp(tab[i],"phiras") == 0)
	cas.p += 1;
      else if (strcmp(tab[i],"thystame") == 0)
	cas.t += 1;
      else if (strcmp(tab[i],"joueur") == 0)
	cas.joueurs += 1;
      i++;
    }
  return (cas);
}

void	print_map(void)
{
  int	i;

  i = 0;
  while (i < (player.niveau + 1) * (player.niveau + 1))
    {
      printf("Case :%i, \n",i + 1);
      print_inv(player.map[i]);
      i++;
    }
  
}

void	ff_los(char *ans)
{
  char **tab;
  int	i;

  tab = stotab(ans, ',');
  i = 0;
  while (tab[i] != 0)
    {
      player.map[i] = get_case(stotab(tab[i], ' '));
      i++;
    }
  if (player.niveau < sqrt(i) - 1)
    player.niveau = sqrt(i) - 1;
  player.pos = 0;
  player.dir = -1;
  free(tab);
} 
