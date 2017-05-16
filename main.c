/*
** main.c for main.c in /home/barbe_j/rendu/Projet_2015/CPE_2014_Pushswap/radix
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Thu Apr 14 23:10:51 2016 jordan barbé
** Last update Sat Apr 23 20:10:19 2016 jordan barbé
*/

#include <stdlib.h>
#include "pushswap.h"

int		enter_list_a(t_list *list_a, char **av,
			     t_push *in)
{
  int		i;

  i = 1;
  in->check_pb = 0;
  in->bonus_v = 0;
  while (av[i])
    {
      if ((av[1][0] == MINUS &&
	   av[1][1] == BONUS) &&
	  in->bonus_v == 0)
	{
	  in->bonus_v = 1;
	  i++;
	}
      if ((add_end_element(my_getnbr(av[i]),
			   list_a)) == 0)
	return (0);
      i++;
      in->check_pb++;
    }
  return (1);
}

int		ordered_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp->next->next != list)
    {
      if (tmp->next->data >
	  tmp->next->next->data)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}

void		my_free(t_list *list)
{
  t_list	*tmp;
  t_list	*chain;

  tmp = list->next;
  chain = list->next;
  while (list != chain)
    {
      tmp = chain->next;
      free(chain);
      chain = tmp;
    }
  free(list);
}

int		main(int ac, char **av)
{
  t_list	*list_a;
  t_list	*list_b;
  t_push	in;

  if (ac < 3)
    {
      my_putchar(ENTER);
      return (1);
    }
  else if (check_argv(av) == 1)
    return (1);
  list_a = NULL;
  list_b = NULL;
  if ((list_a = init_list()) == NULL)
    return (1);
  if ((list_b = init_list()) == NULL)
    return (1);
  if ((enter_list_a(list_a, av, &in)) == 0)
    return (1);
  if ((my_pushswap(list_a, list_b, &in)) == 1)
    return (1);
  my_putchar(ENTER);
  my_free(list_a);
  return (0);
}
