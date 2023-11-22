# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 12:15:30 by bautrodr          #+#    #+#              #
#    Updated: 2023/11/21 12:54:40 by bautrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME: push_swap
SRCS: push_swap.c sort.c util.c check_args.c
OBJS: $(SRCS:.c=.o)
CC: gcc
CFLAGS: -Wall -Wextra -Werror

%.o:%.c Makefile push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) push_swap.h -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
