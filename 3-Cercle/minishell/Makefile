# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 15:23:12 by armendes          #+#    #+#              #
#    Updated: 2022/02/03 17:54:33 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	parsing/parsing.c\

OBJS =	${SRCS:.c=.o}

LIB_DIR =	libs/gnl 

LIB_NAME =	libs/gnl/gnl.a

CC =	gcc

CFLAGS =	-Wall -Wextra -Werror -pthread -I includes -I libs/gnl -g -fsanitize=address

NAME =	minishell

RM =	rm -rf

all:	${NAME}

${NAME}:	${OBJS}
			make -C ${LIB_DIR}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB_NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re