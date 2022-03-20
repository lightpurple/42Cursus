/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:24 by euhong            #+#    #+#             */
/*   Updated: 2022/03/20 20:33:48 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# define SS	0
# define SA	1
# define SB	2
# define PA	3
# define PB	4
# define RR	5
# define RA	6
# define RB	7
# define RRR 8
# define RRA 9
# define RRB 10
# define INTMAX 2147483647
# define INTMIN 2147483648


typedef struct	s_llist {
	int				element;
	struct s_llist	*next;
}				t_llist;

void swap(t_llist **target);
void push(t_llist **dst, t_llist **src);
void rotate(t_llist **target);
void r_rotate(t_llist **target);
void	swap_both(t_llist **a, t_llist **b);
void	rotate_both(t_llist **a, t_llist **b);
void	r_rotate_both(t_llist **a, t_llist **b);
void freest(t_llist **a, t_llist **b);
void error_check(int arc, char *arv[]);
void print(char *str, int fd);
int			ft_atoi(char *str);
int ft_strcmp(char *s1, char *s2);
void init(t_llist **a, t_llist **b, int arc, char *arv[]);
void quickSort(int *arr, int start, int end);

#endif
