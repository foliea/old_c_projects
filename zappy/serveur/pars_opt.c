/*
** main.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/4_edern
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Fri May 28 21:28:58 2010 edern bienvenu
** Last update Sun Jun 20 16:35:36 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "serveur.h"
#include "parsing.h"
#include "player.h"

extern t_parse	parse;
t_teams		*teams;

void	init_option(t_env *e)
{
  e->port = -1;
  parse.width = 20;
  parse.height = 20;
  parse.nb_client = 10;
  parse.nb_team = -1;
  e->t = 100;
  parse.t = 100;
}

void	aff_parsing(t_env *e)
{
  int	i;

  i = 0;
  printf("\033[0;32mWorld Width : %d\tWorld Height : %d\n\
Max Clients : %d\tt : %d\n",
	 parse.width, parse.height, parse.nb_client, e->t);
  puts("Teams : ");
  while (i < parse.nb_team)
    {
      printf("Name : %s\tMax : %d\n", teams[i].name, parse.nb_client);
      i++;
    }
  puts("\033[0;0m");
  return ;
}


int	calc_nb_team(char **team)
{
  int	res;
  int	i;

  i = 0;
  res = 0;
  while (team[i])
    {
      if (strncmp(team[i], "-", 1) == 0)
	{
	  if (res <= 1)
	    aff_error("Minimum two teams");
	  return (res);
	}
      i++;
      res++;
    }
  if (res <= 1)
    aff_error("Minimum two teams");
  return (res);
}

t_teams		*recup_team(char **team)
{
  t_teams	*tmp;
  int		i;

  parse.nb_team = calc_nb_team(team);
  i = 0;
  tmp = xmalloc((parse.nb_team) * sizeof(struct s_teams));
  while (i < parse.nb_team)
    {
      tmp[i].name = team[i];
      tmp[i].data = xmalloc(sizeof(struct s_dteam));
      my_init_dteam(tmp[i].data);
      tmp[i].nb_clients = parse.nb_client;
      i++;
    }
  return (tmp);
}

void		verif_team(int i)
{
  char		*tmp;
  int		j;
  int		test;

  j = 0;
  tmp = teams[i].name;
  if (tmp == NULL)
    return ;
  test = -1;
  while (teams[j].name)
    {
      if (strcmp(tmp, teams[j].name) == 0)
	test++;
      j++;
    }
  if (test >= 1)
    aff_error("Team name already exist");
  else if (parse.nb_team == i + 1)
    return ;
  else
    verif_team(i + 1);
  return ;
}

void	verif_value(t_env *e)
{
  if (parse.nb_team < 2)
    aff_error("Minimum two teams");
  if (parse.width < 5)
    aff_error("Bad Map Size");
  if (parse.height < 5)
    aff_error("Bad Map Size");
  if (e->port < 0)
    aff_error("Bad port value");
  if (e->t < 1 || e->t >= 1000000)
    aff_error("Bad time argue");
  if (parse.nb_client < 1)
    aff_error("Bad Argue");
}

void	parse_opt(char **av, t_env *e)
{
  int	i;

  i = 0;
  while (av[i])
    {
      if (strcmp(av[i], "-p") == 0 && av[i + 1])
	e->port = atoi(av[i + 1]);
      else if (strcmp(av[i], "-x") == 0 && av[i + 1])
	parse.width = atoi(av[i + 1]);
      else if (strcmp(av[i], "-y") == 0 && av[i + 1])
	parse.height = atoi(av[i + 1]);
      else if (strcmp(av[i], "-n") == 0 && av[i + 1])
	teams = recup_team(&av[i + 1]);
      else if (strcmp(av[i], "-c") == 0 && av[i + 1])
	parse.nb_client = atoi(av[i + 1]);
      else if (strcmp(av[i], "-t") == 0 && av[i + 1])
	{
	  e->t = atoi(av[i + 1]);
	  parse.t = e->t;
	}
      i++;
    }
  verif_value(e);
  verif_team(0);
}
