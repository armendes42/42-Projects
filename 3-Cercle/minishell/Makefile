# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 15:23:12 by armendes          #+#    #+#              #
#    Updated: 2022/03/29 18:28:43 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	parsing/parsing.c						\
		parsing/check_quote.c					\
		parsing/create_cmd_struct.c				\
		parsing/error_and_free.c				\
		parsing/parsing_utils.c					\
		parsing/find_pipe.c						\
		parsing/cut_into_words.c				\
		parsing/create_word_struct.c			\
		parsing/empty_word.c					\
		parsing/concat_words.c					\
		parsing/search_utils.c					\
		parsing/manage_redirection.c			\
		parsing/manage_string.c					\
		parsing/create_cell_for_redirection.c	\
		parsing/get_infile_and_outfile.c		\
		parsing/get_var_env.c					\
		parsing/get_env_utils.c					\
		parsing/trim_space_start_or_end.c		\
		parsing/create_args.c					\
		parsing/parsing_utils2.c				\
		parsing/put_space_env_var.c				\
		parsing/exit_status.c					\
		parsing/get_env.c						\
		parsing/just_dollar.c					\
		builtins/builtins.c						\
		builtins/echo.c							\
		builtins/cd.c							\
		builtins/pwd.c							\
		builtins/export.c						\
		builtins/unset.c						\
		builtins/env.c							\
		builtins/exit.c							\
		parsing/readstructILFAUTENLEVER.c		\

OBJS =	${SRCS:.c=.o}

LIB_DIR =	libs/gnl libs/libft

LIB_NAME =	libs/gnl/gnl.a libs/libft/libft.a

CC =	gcc

CFLAGS = -Wall -Wextra -Werror -g -I includes -I libs/gnl -I libs/libft -fsanitize=address

NAME =	minishell

RM =	rm -rf

all:	${NAME}

${NAME}:	${OBJS}
			make -C libs/libft
			make -C libs/gnl
			${CC} ${CFLAGS} -lreadline ${OBJS} ${LIB_NAME} -o ${NAME}

clean:
	make clean -C libs/libft
	make clean -C libs/gnl
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re