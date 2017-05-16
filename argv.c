/*
** argv.c for argvv in /home/barbe_j/rendu/CPE_2015_Pushswap
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Sat Apr 23 19:46:57 2016 jordan barbé
** Last update Mon Aug  8 16:42:57 2016 jordan barbé
*/

#include "pushswap.h"

int	check_argv(char **str)
{
  int	i;
  int	c;

  c = 0;
  i = 1;
  while (str[i])
    {
      while (str[i][c])
	{
	  if ((str[i][c] >= '0' && str[i][c] <= '9') ||
	      (str[i][c] == '-' && str[i][c + 1] >= '0' &&
	       str[i][c + 1] <= '9') || (str[1][0] == '-' &&
					 str[1][1] == 'v' &&
					 str[1][2] == 0))
	    c++;
	  else
	    {
	      my_puterror(ERROR_ARGV);
	      return (1);
	    }
	}
      c = 0;
      i++;
    }
  return (0);
}
