##
## Makefile for make in /home/barbe_j/rendu/Projet_2015/CPE_2014_Pushswap/radix
## 
## Made by jordan barbé
## Login   <barbe_j@epitech.net>
## 
## Started on  Fri Apr 15 19:55:08 2016 jordan barbé
## Last update Mon Aug  8 18:10:10 2016 jordan barbé
##

NAME		= push_swap

CC		= gcc

RM		= rm -rf

SRC		= main.c		\
		  utils.c		\
		  utils1.c		\
		  list.c		\
		  my_put_nbr.c		\
		  process_next.c	\
		  process.c		\
		  bonus.c		\
		  argv.c		\
		  mouve.c

OBJ		= $(SRC:.c=.o)

CFLAGS		= -Wall -Werror -ansi -pedantic

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
