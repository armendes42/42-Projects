# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 19:36:46 by armendes          #+#    #+#              #
#    Updated: 2022/01/13 15:33:55 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/push_swap.c		\
		srcs/check_arg.c 		\
		srcs/error.c			\
		srcs/free.c 			\
		srcs/set_stack_a.c		\
		srcs/check_sorted.c		\
		srcs/get_pos_stack.c 	\
		srcs/utils.c			\
		srcs/sort_big_stack.c	\
		srcs/stack_operation.c	\
		
LIB_DIR =	libft

LIB_NAME =	libft/libft.a

OBJS =	${SRCS:.c=.o};

CC =	cc

CFLAGS =	-Wall -Wextra -Werror -g2 -fsanitize=address -I includes

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