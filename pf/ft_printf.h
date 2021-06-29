/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:35:13 by euhong            #+#    #+#             */
/*   Updated: 2021/06/30 01:45:31 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define ONLY 0
# define LEFT 1
# define RIGHT 2

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	char		star[2];
	char		type;
}				t_info;

int				ft_printf(const char *str, ...);
int				is_type(char c);
void			init_info(t_info *info);
int				print_info(va_list *ap, t_info info);
int				print_id(va_list *ap, t_info info);
int				print_c(va_list *ap, t_info info);
int				print_s(va_list *ap, t_info info);
int				print_u(va_list *ap, t_info info);
int				print_p(va_list *ap, t_info info);
int				print_x(va_list *ap, t_info info);
int				print_ux(va_list *ap, t_info info);
int				print_n(va_list *ap, t_info info);
int				print_space(int width, int s_len, char *num, int flag);
int				print_zero(int width, int s_len, char *num);
int				print_perc(t_info info);
int				ft_strlen(char *str);
char			*ft_itoa(int n);
char			*ft_utoa(unsigned int n);
char			*ft_xtoa(unsigned int num);
int				treat_star(va_list *ap, t_info *info);
void			setting_p(char **str, unsigned long p, t_info info);
char			*ft_strdup(char *s1);
int				cnt_hex(unsigned int num);
int				cnt_num(int n);
int				cnt_unum(unsigned int n);
void			change_up(char **num);
char			hex_num(int num);

#endif
