# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 18:52:59 by euhong            #+#    #+#              #
#    Updated: 2021/07/02 19:22:46 by euhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILE = main 
SRCS = $(addsuffix .c, $(FILE))
OBJS = $(SRCS:.c=.o)

MLX = $(addprefix lib, $(addsuffix .a, $(MLX)))
MLX_DIR = ./minilibx
MLX_SRC = mlx

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX_SRC) -framework OpenGL -framework ApKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $<

clean :
	$(RM) $(OBJS)
	make -C $(MLX_DIR) clean

fclean : clean
	$(RM) $(NAME)

re : fclean all
