# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 12:15:30 by bautrodr          #+#    #+#              #
#    Updated: 2023/11/22 18:47:42 by bautrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME: push_swap
SRCS: main.c \
	sort.c \
	more_utils.c \
	util.c \
	check_args.c
	
OBJS: $(SRCS:.c=.o)
CC: gcc
CFLAGS: -Wall -Wextra -Werror

all: $(NAME)

%.o:%.c Makefile
	$(CC) $(FLAGS) -I ./ -c $(OBJS) -o $@

$(NAME): $(OBJS)
	${MAKE} -C ./libft
	$(CC) $(CFLAGS) $(OBJS) push_swap.h ./libft/libft.a -o $(NAME)

clean:
	${MAKE} -C ./libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
