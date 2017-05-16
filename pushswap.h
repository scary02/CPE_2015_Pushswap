/*
** pushswap.h for pushswap in /home/barbe_j/rendu/Projet_2015/CPE_2014_Pushswap/radix
** 
** Made by jordan barbé
** Login   <barbe_j@epitech.net>
** 
** Started on  Thu Apr 14 23:12:21 2016 jordan barbé
** Last update Mon Aug  8 18:09:14 2016 jordan barbé
*/

#ifndef PUSHSWAP_H_
# define PUSHSWAP_H_

# define ERROR_ARGV	"Error : illegal character\n"
# define ERROR_MALLOC	"Error : Malloc Failed\n"
# define LIST_A		"\n      list_a :\n        "
# define LIST_B		"\n      list_b :\n        "
# define PA		" pa"
# define PB		" pb"
# define RA		" ra"
# define MAX_INT	"-2147483648"

# define MORE		'+'
# define ZERO		'0'
# define NINE		'9'
# define SPACE		' '
# define MINUS		'-'
# define BONUS		'v'
# define ENTER		'\n'
# define NUL		'\0'

typedef struct		s_list
{
  int			data;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef struct		s_push
{
  int			check_pb;
  int			bonus_v;
  int			i;
  int			c;
  int			count;
  int			save;
  char			*str;
  t_list		*tmp;
  t_list		*temp;
}			t_push;

void			my_put_remaining(t_push *in);
int			enter_list_a(t_list *list_a, char **av,
				     t_push *in);
t_list			*init_list();
int			add_end_element(int data, t_list *list);
void			my_print_bonus(t_list *la,
				       t_list *lb, t_push *in);
void			my_print_list(t_list *list);
int			my_putchar(char c);
int			my_getnbr(char *str);
int			my_strlen(char *str);
void			my_putstr(char *str);
int			ordered_list(t_list *list);
int			my_puterror(char *str);
int			my_put_nbr(int);
int			my_pushswap(t_list *la,
				    t_list *lb, t_push *in);
int			ra(t_list *list, t_push *in);
int			pb(t_list *la, t_list *lb, t_push *);
int			pa(t_list *la, t_list *lb, t_push *);
t_list			*init_list();
int			add_end_element(int data, t_list *list);
int			add_start_element(int data, t_list *list);
void			remove_elem_start(t_list *list);
int			my_putstr_str(char *str, t_push *in);
int			check_argv(char **str);
int			process_pushswap(t_list *, t_list *, t_push *);
int			process_pb(t_list *, t_list *, t_push *, int);
int			process_pb_ra(t_list *, t_list *, t_push *, int);

#endif /* !PUSHSWAP_H_ */
