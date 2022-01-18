# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 19:36:46 by armendes          #+#    #+#              #
#    Updated: 2022/01/18 20:08:23 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/push_swap.c			\
		srcs/check_arg.c 			\
		srcs/error.c				\
		srcs/free.c 				\
		srcs/set_stack_a.c			\
		srcs/check_sorted.c			\
		srcs/get_pos_stack.c 		\
		srcs/utils.c				\
		srcs/sort_big_stack.c		\
		srcs/stack_operation.c		\
		srcs/sort_small_stack.c		\
		srcs/sort_stack_two.c		\
		srcs/sort_stack_three.c		\
		srcs/sort_stack_four.c		\
		srcs/sort_stack_five.c		\
		srcs/extract_zero_pos_four.c\
		srcs/extract_zero_pos_five.c\
		srcs/extract_one_pos_five.c\
		
LIB_DIR =	libft

LIB_NAME =	libft/libft.a

OBJS =	${SRCS:.c=.o};

CC =	cc

CFLAGS =	-Wall -Wextra -Werror -I includes

NAME =	push_swap

RM =	rm -rf

all:	${NAME}

${NAME}:	${OBJS}
			make -C ${LIB_DIR}
			${CC} ${CFLAGS} -o ${NAME} ${SRCS} ${LIB_NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re