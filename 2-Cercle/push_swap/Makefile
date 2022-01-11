# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 19:36:46 by armendes          #+#    #+#              #
#    Updated: 2022/01/11 17:04:59 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/push_swap.c		\
		srcs/check_arg.c 		\
		srcs/bubble_sort.c		\
		srcs/error.c			\
		srcs/sort_small_stack.c	\
		srcs/free.c 			\
		
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