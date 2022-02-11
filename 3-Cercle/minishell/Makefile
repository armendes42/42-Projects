# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 15:23:12 by armendes          #+#    #+#              #
#    Updated: 2022/02/11 17:31:59 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	parsing/parsing.c				\
		parsing/check_quote.c			\
		parsing/create_cmd_struct.c		\
		parsing/error_and_free.c		\
		parsing/parsing_utils.c			\
		parsing/find_pipe.c				\
		parsing/cut_into_words.c		\
		parsing/create_word_struct.c	\
		parsing/empty_word.c			\

OBJS =	${SRCS:.c=.o}

LIB_DIR =	libs/gnl libs/libft

LIB_NAME =	libs/gnl/gnl.a libs/libft/libft.a

CC =	gcc

CFLAGS = -Wall -Wextra -Werror -pthread -I includes -I libs/gnl -I libs/libft -lreadline -g -fsanitize=address

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