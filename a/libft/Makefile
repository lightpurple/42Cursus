# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 12:10:22 by euhong            #+#    #+#              #
#    Updated: 2021/05/06 22:37:25 by euhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs
FILE = ft_memset ft_strlen ft_bzero ft_memcpy ft_memccpy ft_memmove\
	   ft_memchr ft_memcmp ft_strchr ft_strrchr ft_strncmp ft_calloc\
		ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper\
		ft_tolower ft_strlcpy ft_strlcat ft_atoi ft_strnstr ft_strdup\
		ft_substr 
SRCS = $(addsuffix .c, $(FILE))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
