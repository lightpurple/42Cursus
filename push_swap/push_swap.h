/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:24 by euhong            #+#    #+#             */
/*   Updated: 2022/03/21 23:53:53 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

# define SUCCESS 0
# define FAIL 1

# define INTMAX 2147483647
# define INTMIN 2147483648

# define A 0
# define B 1

typedef struct	s_llist {
	int				element;
	struct s_llist	*next;
}				t_llist;

/*
*** op.c ***
*/
void swap(t_llist **target, int stack);
void push(t_llist **dst, t_llist **src, int stack);
void rotate(t_llist **target, int stack);
void r_rotate(t_llist **target, int stack);

/*
*** op_both.c ***
*/
void	swap_both(t_llist **a, t_llist **b);
void	rotate_both(t_llist **a, t_llist **b);
void	r_rotate_both(t_llist **a, t_llist **b);

/*
*** error.c ***
*/
void error_check(int arc, char *arv[]);

/*
*** str.c ***
*/
void print(char *str, int fd);
int ft_strcmp(char *s1, char *s2);

/*
*** init.c ***
*/
void init(t_llist **a, t_llist **b, int arc, char *arv[]);

/*
*** util1.c ***
*/
void freest(t_llist **a, t_llist **b);
int ft_atoi(char *str);
void quickSort(int *arr, int start, int end);
int cnt_list(t_llist *list);

/*
*** simple_sort.c ***
*/
int is_sorted(t_llist *a);
int check_sorted(t_llist *a, int cnt);
void simple_sort(t_llist **a, t_llist **b, int cnt);


#endif
