/*
** utils1.c for utils in /home/barbe_j/rendu/CPE_2015_Pushswap
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Sat Apr 23 17:17:10 2016 jordan barbé
** Last update Mon Aug  8 17:42:43 2016 jordan barbé
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pushswap.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}

int		my_putstr_str(char *str, t_push *in)
{
  static int	c = 0;
  static int	check = 0;
  int		i;

  i = 0;
  if (c == 0)
    if (!(in->str = malloc(sizeof(char) * 4096)))
      return (-1);
  while (str[i])
    {
      if (check == 0 && i == 0)
	;
      else
	{
	  in->str[in->count] = str[i];
	  in->count++;
	  c++;
	}
      i++;
    }
  in->str[in->count] = 0;
  if (c > 4090)
    {
      write(1, in->str, c);
      in->count = 0;
      c = 0;
      free(in->str);
    }
  in->save = c;
  check++;
  return (0);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      write(1, &str[i], 1);
      i++;
    }
}
