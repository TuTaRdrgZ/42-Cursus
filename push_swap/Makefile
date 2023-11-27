# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 12:15:30 by bautrodr          #+#    #+#              #
#    Updated: 2023/11/27 16:34:16 by bautrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = push_swap.c \
	sort.c \
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
INCLUDE_FT_PRINTF = ./ft_printf/ft_printf.a
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf 

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
