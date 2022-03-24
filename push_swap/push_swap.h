/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:24 by euhong            #+#    #+#             */
/*   Updated: 2022/03/24 16:26:28 by euhong           ###   ########.fr       */
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
# define AB 2

# define P 0
# define R 1
# define RR 2
# define RRR 3

# define RA 0
# define RB 1
# define PB 2
typedef struct s_llist
{
	int				element;
	struct s_llist	*next;
}					t_llist;

/*
*** op.c ***
*/
void				swap(t_llist **target, int stack);
void				push(t_llist **dst, t_llist **src, int stack);
void				rotate(t_llist **target, int stack);
void				r_rotate(t_llist **target, int stack);

/*
*** op_both.c ***
*/
void				swap_both(t_llist **a, t_llist **b);
void				rotate_both(t_llist **a, t_llist **b);
void				r_rotate_both(t_llist **a, t_llist **b);

/*
*** error.c ***
*/
void				error_check(int arc, char *arv[]);

/*
*** str.c ***
*/
void				print(char *str, int fd);
int					ft_strcmp(char *s1, char *s2);

/*
*** init.c ***
*/
void				init(t_llist **a, t_llist **b, int arc, char *arv[]);

/*
*** util1.c ***
*/
void				freest(t_llist **a, t_llist **b);
int					ft_atoi(char *str, int *flag);
void				quickSort(int *arr, int start, int end);
int					cnt_list(t_llist *list);
void	find_pivot(t_llist *list, int cnt, int *pivot1, int *pivot2);

/*
*** simple_sort.c ***
*/
int					is_sorted(t_llist *a);
int					check_sorted(t_llist *a, int cnt);
void				simple_sort(t_llist **a, t_llist **b, int cnt);

/*
*** sort_util.c ***
*/
void	sort_3_operator(t_llist **target, int type, int stack);
void	rewind_stack(t_llist **a, t_llist **b, int ra, int rb);
void	operator(t_llist **dst, t_llist **src, int *cnt, int op, int stack);

/*
*** sort.c ***
*/
void	sort(t_llist **a, t_llist **b, int cnt, int type);
void	a_to_b(t_llist **a, t_llist **b, int cnt);
void b_to_a(t_llist **a, t_llist **b, int cnt);

#endif
