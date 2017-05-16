/*
** process.c for process in /home/barbe_j/rendu/CPE_2015_Pushswap
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Sat Apr 23 15:49:15 2016 jordan barbé
** Last update Mon Aug  8 18:07:05 2016 jordan barbé
*/

#include <stdlib.h>
#include "pushswap.h"

void	init_struct(t_list *la, t_list *lb, t_push *in)
{
  in->i = 0;
  in->c = 0;
  in->tmp = la;
  in->temp = lb;
  in->str = NULL;
  in->count = 0;
}

int	process_pb_ra(t_list *la, t_list *lb,
		      t_push *in, int i)
{
  if ((la->next->data >> i & 1) == 0)
    {
      if (pb(la, lb, in))
	return (-1);
      if (in->bonus_v == 1)
	my_print_bonus(la, lb, in);
    }
  else
    {
      if (ra(la, in))
	return (-1);
      if (in->bonus_v == 1)
	my_print_bonus(la, lb, in);
    }
  return (0);
}

int	process_pb(t_list *la, t_list *lb,
		   t_push *in, int i)
{
  if (pb(la, lb, in))
    return (-1);
  if (in->bonus_v == 1)
    my_print_bonus(la, lb, in);
  return (0);
}

int	process_pa(t_list *la, t_list *lb,
		   t_list *temp, t_push *in)
{
  while (lb->next != temp)
    {
      if (pa(la, lb, in))
	return (-1);
      if (in->bonus_v == 1)
	my_print_bonus(la, lb, in);
    }
  return (0);
}

int		my_pushswap(t_list *la,
			   t_list *lb, t_push *in)
{
  init_struct(la, lb, in);
  if ((ordered_list(la)) == 1)
    return (my_putchar(ENTER));
  while (ordered_list(la) != 1)
    {
      if (process_pushswap(la, lb, in))
	return (-1);
      in->c = 0;
      la = in->tmp;
      if (process_pa(la, lb, in->temp, in))
	return (-1);
      in->i++;
    }
  my_put_remaining(in);
  return (0);
}
