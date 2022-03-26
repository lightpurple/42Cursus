# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/19 18:12:21 by euhong            #+#    #+#              #
#    Updated: 2022/03/26 23:38:06 by euhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = init.c error.c util1.c str.c op.c op_both.c push_swap.c simple_sort.c\
				sort.c sort_util.c a_to_b.c ft_split.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

CHECKER = checker
CHECKER_SRCS = checker.c init.c op.c op_both.c ft_split.c str.c error.c\
							get_next_line.c get_next_line_utils.c util1.c simple_sort.c
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re bonus

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $? -g

clean :
	$(RM) $(OBJS) $(CHECKER_OBJS)

fclean : clean
	$(RM) $(NAME) $(CHECKER)

bonus : $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $^ -o $(CHECKER) -g

re : fclean all
