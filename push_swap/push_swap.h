/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:37:24 by euhong            #+#    #+#             */
/*   Updated: 2022/03/26 23:32:00 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

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
# define PA 2
# define PB 2
typedef struct s_llist
{
	int				element;
	struct s_llist	*next;
}					t_llist;

void				swap(t_llist **target, int stack);
void				push(t_llist **dst, t_llist **src, int stack);
void				rotate(t_llist **target, int stack);
void				r_rotate(t_llist **target, int stack);
void				swap_both(t_llist **a, t_llist **b, int flag);
void				rotate_both(t_llist **a, t_llist **b, int flag);
void				r_rotate_both(t_llist **a, t_llist **b, int flag);
void				error_check(int *arc, char ***arv);
void				print(char *str, int fd);
int					ft_strcmp(char *s1, char *s2);
void				init(t_llist **a, t_llist **b, int arc, char *arv[]);
int					ft_atoi(char *str, int *flag);
void				freest(t_llist **a, t_llist **b);
void				quickSort(int *arr, int start, int end);
int					cnt_list(t_llist *list);
void				find_pivot(t_llist *list, int cnt, int *pivot1, \
int *pivot2);
int					check_sorted(t_llist *a, int cnt);
void				simple_sort(t_llist **a, t_llist **b, int cnt);
void				operator(t_llist **dst, t_llist **src, int op, int stack);
void				sort_3_operator(t_llist **target, int type, int stack);
void				rewind_stack(t_llist **a, t_llist **b, int ra, int rb);
void				sort(t_llist **a, t_llist **b, int cnt, int type);
void				a_to_b(t_llist **a, t_llist **b, int cnt);
void				b_to_a(t_llist **a, t_llist **b, int cnt);
char				**ft_split(char const *s, char c, int *arc);
void				parse_arv(int *arc, char ***arv);
void				sort_2(t_llist **a, t_llist **b, int type);
void				push_n(t_llist **dst, t_llist **src, int stack, int n);
#endif
