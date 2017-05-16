/*
** utils.c for utils in /home/barbe_j/rendu/Projet_2015/CPE_2014_Pushswap/radix
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Thu Apr 14 23:29:32 2016 jordan barbé
** Last update Mon Aug  8 17:53:57 2016 jordan barbé
*/

#include <stdlib.h>
#include <unistd.h>
#include "pushswap.h"

void	my_check(char *str, int *cpt, int *compt)
{
  while (str[*cpt] == MORE || str[*cpt] == MINUS)
    {
      if (str[*cpt] == MINUS)
	*compt = *compt + 1;
      *cpt = *cpt + 1;
    }
}

int	my_getnbr(char *str)
{
  long	result;
  int	cpt;
  int	compt;

  compt = 0;
  result = 0;
  cpt = 0;
  my_check(str, &cpt, &compt);
  while (str[cpt] && str[cpt] >= ZERO && str[cpt] <= NINE)
    {
      result = (result * 10) + (str[cpt] - 48);
      if ((result > 2147483647 && !(compt % 2 == 1)) ||
	  (result > 2147483648 && (compt % 2 == 1)))
	return (0);
      cpt = cpt + 1;
    }
  if (compt % 2 == 1)
    result = result * -1;
  return (result);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int		my_puterror(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      write(2, &str[i], 1);
      i++;
    }
  return (-1);
}
