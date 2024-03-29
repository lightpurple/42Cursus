/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:35:56 by euhong            #+#    #+#             */
/*   Updated: 2021/07/12 11:49:33 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

void	put_err(char *errstr);
void	put_str(char *str);
int		ft_strlen(char *str);
char	*ft_itoa(int n);
int		ft_atoi(char *str);
int		send_sig(int pid, char *str);

#endif
