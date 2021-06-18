# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 18:52:59 by euhong            #+#    #+#              #
#    Updated: 2021/06/18 09:24:52 by euhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs

FILE = ft_printf utils type1 type2
SRCS = $(addsuffix .c, $(FILE))
OBJS = $(SRCS:.c=.o)

LIB_DIR = ./libft/
LIB_NAME = ft
LIB = $(LIB_DIR)lib$(LIB_NAME).a

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS) 
	make -C $(LIB_DIR)
	$(AR) $(ARFLAGS) $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< 

clean :
	$(RM) $(OBJS)
	make -C $(LIB_DIR) fclean

fclean : clean
	$(RM) $(NAME)

re : fclean all
