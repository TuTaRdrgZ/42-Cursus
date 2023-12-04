# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 12:19:05 by bautrodr          #+#    #+#              #
#    Updated: 2023/12/04 13:22:10 by bautrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
SRCS = main.c \
	   utils.c
INCLUDE_LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) -c $< -o $@

$(NAME): $(OBJS) Makefile pipex.h $(LIBFT_DIR)/libft.h 
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
