# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 15:23:12 by armendes          #+#    #+#              #
#    Updated: 2022/02/03 20:07:50 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	parsing/parsing.c\

OBJS =	${SRCS:.c=.o}

LIB_DIR =	libs/gnl libs/libft

LIB_NAME =	libs/gnl/gnl.a libs/libft/libft.a

CC =	gcc

CFLAGS = -Wall -Wextra -Werror -pthread -I includes -I libs/gnl -g -fsanitize=address

NAME =	minishell

RM =	rm -rf

all:	${NAME}

${NAME}:	${OBJS}
			make -C libs/libft
			make -C libs/gnl
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB_NAME}

clean:
	make clean -C libs/libft
	make clean -C libs/gnl
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re