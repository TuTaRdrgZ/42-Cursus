# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 12:15:30 by bautrodr          #+#    #+#              #
#    Updated: 2023/11/29 13:13:09 by bautrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = push_swap.c \
	swap_push.c \
	more_utils.c \
	util.c \
	check_args.c \
	instructions_p.c \
	instructions_s.c \
	instructions_r.c \
	instructions_rr.c \
	t_list.c \
	sort_2_to_5.c \
	short_sort.c \
	big_sort.c \
	index.c

INCLUDE_LIBFT = ./libft/libft.a 
LIBFT_DIR = ./libft
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) -c $< -o $@

$(NAME): $(OBJS) Makefile push_swap.h $(LIBFT_DIR)/libft.h
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
