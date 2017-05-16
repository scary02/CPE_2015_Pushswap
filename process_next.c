/*
** process_next.c for process_next in /home/barbe_j/rendu/CPE_2015_Pushswap
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Sat Apr 23 19:34:49 2016 jordan barbé
** Last update Mon Aug  8 18:06:32 2016 jordan barbé
*/

#include <stdlib.h>
#include <unistd.h>
#include "pushswap.h"

void	my_put_remaining(t_push *in)
{
  if (in->save != 0)
    {
      write(1, in->str, in->save);
      free(in->str);
    }
}

int	process_pushswap(t_list *la, t_list *lb, t_push *in)
{
  while (in->c != in->check_pb)
    {
      if (in->i == 31)
	{
	  if ((la->next->data >> in->i & 1) == 1)
	    {
	      if (process_pb(la, lb, in, in->i))
		return (-1);
	      else
		la = la->next;
	    }
	}
      else
	if (process_pb_ra(la, lb, in, in->i))
	  return (-1);
      in->c++;
    }
  return (0);
}
