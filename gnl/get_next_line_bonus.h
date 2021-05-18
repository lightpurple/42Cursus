/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:01:43 by euhong            #+#    #+#             */
/*   Updated: 2021/05/18 18:27:00 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define OPEN_MAX 256

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
int		ft_find_newline(char *str);
char	*ft_strdup(char *s1);
char	*ft_strncpy(char *dst, char *src, int loc);
char	*ft_strncat(char *dst, char *src, int len);

#endif
