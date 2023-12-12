# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 11:36:06 by bautrodr          #+#    #+#              #
#    Updated: 2023/12/12 12:45:29 by bautrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRV = server
CLI = client
SRCS = server.c client.c utils.c 
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror 

all: $(SRV) $(CLI)

$(SRV): server.o utils.o Makefile minitalk.h 
	$(CC) $(CFLAGS) server.o utils.o -o $(SRV) 

$(CLI): client.o utils.o Makefile minitalk.h
	$(CC) $(CFLAGS) client.o utils.o -o $(CLI) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(SRV)
	rm -f $(CLI)

re: fclean all

.PHONY: all clean fclean re
