/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:01:43 by euhong            #+#    #+#             */
/*   Updated: 2022/03/04 01:11:49 by euhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

int		get_next_line(int fd, char **line);
int		ft_strlen(char *str);
int		ft_find_newline(char *str);
char	*ft_str_append(char *str, char *buf, int b_len);
char	*ft_strdup(char *s1);
char	*ft_strncpy(char *dst, char *src, int loc);
char	*ft_strncat(char *dst, char *src, int len);

#endif
