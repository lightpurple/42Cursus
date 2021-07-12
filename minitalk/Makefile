# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euhong <euhong@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 18:52:59 by euhong            #+#    #+#              #
#    Updated: 2021/07/12 11:46:51 by euhong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server
SERVER_SRCS = server.c str.c utils.c
SERVER_OBJS= $(SERVER_SRCS:.c=.o)

CLIENT = client
CLIENT_SRCS = client.c str.c utils.c signal.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJS)
	$(CC) $(CFLAGS) -o $@ $?

$(CLIENT) : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) -o $@ $?

%.o : %.c
	$(CC) $(CFLAGS) -c $?

clean :
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean : clean
	$(RM) $(SERVER) $(CLIENT)

re : fclean all
