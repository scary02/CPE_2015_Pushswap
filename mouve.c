/*
** p.c for p in /home/barbe_j/rendu/Projet_2015/CPE_2014_Pushswap/radix
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Thu Apr 14 23:07:20 2016 jordan barbé
** Last update Mon Aug  8 17:59:47 2016 jordan barbé
*/

#include "pushswap.h"

int	pa(t_list *la, t_list *lb,
	   t_push *in)
{
  int	temp;

  if (lb->next == lb)
    return (-1);
  temp = lb->next->data;
  remove_elem_start(lb);
  if (!add_start_element(temp, la))
    return (-1);
  if (my_putstr_str(PA, in))
    return (-1);
  return (0);
}

int	pb(t_list *la, t_list *lb,
	   t_push *in)
{
  int	temp;

  if (la->next == la)
    return (-1);
  temp = la->next->data;
  remove_elem_start(la);
  if (!add_start_element(temp, lb))
    return (-1);
  if (my_putstr_str(PB, in))
    return (-1);
  return (0);
}

int	ra(t_list *list, t_push *in)
{
  int	temp;

  temp = list->next->data;
  remove_elem_start(list);
  if (!add_end_element(temp, list))
    return (-1);
  if (my_putstr_str(RA, in))
    return (-1);
  return (0);
}
