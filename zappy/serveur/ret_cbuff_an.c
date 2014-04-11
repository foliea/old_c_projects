/*
** ret_team_an.c for zappy in /u/epitech_2013/bienve_e/cu/public/zappy/1_adrien
** 
** Made by edern bienvenu
** Login   <bienve_e@epitech.net>
** 
** Started on  Sun Jun 20 16:29:32 2010 edern bienvenu
** Last update Sun Jun 20 16:44:48 2010 edern bienvenu
*/

#include <stdlib.h>
#include <stdio.h>
#include "cbuff.h"

extern t_dcircular	*buff_list;

void		cremove_mid_end(t_circular *save)
{
  buff_list->begin->prev->next = NULL;
  buff_list->end = buff_list->begin->prev;
  buff_list->begin = save;
}

void		cremove_mid_mid(t_circular *save)
{
  buff_list->begin->prev->next = buff_list->begin->next;
  buff_list->begin->next->prev = buff_list->begin->prev;
  buff_list->begin = save;
}

void		cremove_mid_beg(void)
{
  buff_list->begin = buff_list->begin->next;
  buff_list->begin->prev = NULL;
}

