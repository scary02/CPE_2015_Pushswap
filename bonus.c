/*
** bonus.c for bonus in /home/barbe_j/rendu/CPE_2015_Pushswap
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Sat Apr 23 15:48:13 2016 jordan barbé
** Last update Sat Apr 23 19:29:36 2016 jordan barbé
*/

#include "pushswap.h"

void	my_print_bonus(t_list *la, t_list *lb,
		       t_push *in)
{
  my_putstr(LIST_A);
  my_print_list(la);
  my_putstr(LIST_B);
  my_print_list(lb);
  my_putchar(ENTER);
}

void	my_print_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (list->next != tmp)
    {
      my_put_nbr(list->next->data);
      my_putchar(SPACE);
      list = list->next;
    }
}
