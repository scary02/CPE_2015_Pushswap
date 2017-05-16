/*
** operator.c for ope in /home/barbe_j/rendu/Projet_2015/CPE_2014_Pushswap/radix
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Thu Apr 14 23:07:26 2016 jordan barbé
** Last update Sat Apr 23 19:30:36 2016 jordan barbé
*/

#include <stdlib.h>
#include "pushswap.h"

t_list		*init_list()
{
  t_list	*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    {
      my_puterror(ERROR_MALLOC);
      return (NULL);
    }
  list->next = list;
  list->prev = list;
  list->data = 0;
  return (list);
}

int		add_end_element(int data, t_list *list)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    {
      my_puterror(ERROR_MALLOC);
      return (0);
    }
  elem->data = data;
  elem->prev = list->prev;
  elem->next = list;
  list->prev->next = elem;
  list->prev = elem;
  return (1);
}

int		add_start_element(int data, t_list *list)
{
  t_list	 *elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    {
      my_puterror(ERROR_MALLOC);
      return (0);
    }
  elem->data = data;
  elem->next = list->next;
  elem->prev = list;
  list->next->prev = elem;
  list->next = elem;
  return (1);
}

void		remove_elem_start(t_list *list)
{
  t_list	*tmp;

  if (list->next == list)
    return ;
  tmp = list->next;
  list->next = list->next->next;
  list->next->prev = list;
  free(tmp);
  return ;
}
