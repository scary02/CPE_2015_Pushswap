/*
** my_put_nbr.c for my_put_nbr in /home/barbe_j/rendu/Piscine_C_J03
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Wed Mar  2 09:38:25 2016 jordan barbé
** Last update Sat Apr 23 19:33:56 2016 jordan barbé
*/

#include "pushswap.h"

int	my_display_maxint()
{
  my_putstr(MAX_INT);
  return (1);
}

int	my_put_nbr(int nb)
{
  if (nb >= 2147483648)
    return (0);
  if (nb == -2147483648 && nb < 0)
    if (my_display_maxint() == 1)
    return (1);
  if (nb < 0)
    {
      my_putchar(MINUS);
      nb *= -1;
      if (nb <= 9)
	my_putchar(nb + 48);
      else
	my_put_nbr(nb);
    }
  else if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(nb + 48);
  return (0);
}
