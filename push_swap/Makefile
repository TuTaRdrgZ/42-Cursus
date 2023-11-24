# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bautrodr <bautrodr@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 12:15:30 by bautrodr          #+#    #+#              #
#    Updated: 2023/11/24 12:57:32 by bautrodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME: push_swap
SRCS: main.c \
	sort.c \
	more_utils.c \
	util.c \
	check_args.c \
	instructions_p.c \
	instructions_s.c \
	instructions_r.c \
	t_stack.c

INCLUDE_LIBFT = -L ./libft -lft
INCLUDE_FT_PRINTF = -L ./ft_printf -lft
LIBFT_DIR = libft/
OBJS: $(SRCS:.c=.o)
CC: gcc
CFLAGS: -Wall -Wextra -Werror

all: $(NAME)

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C $(LIBFTDIR)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${INCLUDE_LIBF} ${INCLUDE_FT_PRINTF}

clean:
	${MAKE} -C ./libft fclean
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
