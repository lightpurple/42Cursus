# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 18:52:59 by euhong            #+#    #+#              #
#    Updated: 2021/07/02 14:58:56 by euhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILE = 
SRCS = $(addsuffix .c, $(FILE))
OBJS = $(SRCS:.c=.o)

MLX_DIR = ./minilibx
MLX_SRC = mlx

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX_SRC) -freamework OpenGL -framework ApKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $<

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
