# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/05 12:10:22 by euhong            #+#    #+#              #
#    Updated: 2021/05/10 14:58:20 by euhong           ###   ########.fr        #
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
	   ft_substr ft_strjoin ft_strtrim ft_itoa ft_split ft_strmapi\
	   ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\

BONUS_FILE = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
			 ft_lstdelone ft_lstclear ft_lstiter ft_lstmap\

SRCS = $(addsuffix .c, $(FILE))

BONUS_SRCS = $(addsuffix .c, $(BONUS_FILE))

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : $(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

.PHONY : all clean fclean re bonus
