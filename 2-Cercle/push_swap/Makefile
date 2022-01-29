# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 19:36:46 by armendes          #+#    #+#              #
#    Updated: 2022/01/29 17:18:12 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/push_swap.c					\
		srcs/stack_operation.c				\
		srcs/utils.c						\
		srcs/arg_check/check_arg.c			\
		srcs/arg_check/check_sorted.c		\
		srcs/error_and_free/error.c			\
		srcs/error_and_free/free.c			\
		srcs/set_stack/get_pos_stack.c		\
		srcs/set_stack/set_stack_a.c		\
		srcs/sort/extract_one_pos_five.c	\
		srcs/sort/extract_zero_pos_five.c	\
		srcs/sort/extract_zero_pos_four.c	\
		srcs/sort/sort_big_stack.c			\
		srcs/sort/sort_small_stack.c		\
		srcs/sort/sort_stack_five.c			\
		srcs/sort/sort_stack_four.c			\
		srcs/sort/sort_stack_three.c		\
		srcs/sort/sort_stack_two.c			\

LIB_DIR =	libft

LIB_NAME =	libft/libft.a

OBJS =	${SRCS:.c=.o}

CC =	cc

CFLAGS =	-Wall -Wextra -Werror -g -I includes

NAME =	push_swap

RM =	rm -rf

all:	${NAME}

${NAME}:	${OBJS}
			make -C ${LIB_DIR}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB_NAME}

clean:
		make clean -C ${LIB_DIR}
		${RM} ${OBJS}

fclean:	clean
		${RM} ${LIB_NAME}
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re