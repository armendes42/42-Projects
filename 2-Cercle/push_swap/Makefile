# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 19:36:46 by armendes          #+#    #+#              #
#    Updated: 2022/01/05 19:59:12 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/push_swap.c\
		srcs/bubble_sort.c

OBJS =	${SRCS:.c=.o};

CC =	cc

CFLAGS =	-Wall -Wextra -Werror -g2 -fsanitize=address -I includes

NAME =	pipex

RM =	rm -rf

all:	${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${SRCS}	

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re