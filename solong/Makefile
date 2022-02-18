# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 18:52:59 by euhong            #+#    #+#              #
#    Updated: 2022/02/18 23:21:20 by euhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = solong

SRCS = init.c mlx.c parsing.c so_long.c get_next_line.c get_next_line_utils.c\
			draw.c util.c
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx_opengl_20191021


.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework Appkit

%.o : %.c
	$(CC) $(CFLAGS) -c $?

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
