# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 18:19:27 by armendes          #+#    #+#              #
#    Updated: 2022/03/07 16:36:44 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/philo.c			\
		srcs/check_arg.c		\
		srcs/init_struct.c		\
		srcs/init_struct_utils.c\
		srcs/manage_fork.c		\
		srcs/manage_time.c		\
		srcs/philo_operations.c	\
		srcs/philo_thread.c		\
		srcs/print_message.c	\
		srcs/utils.c			\
		srcs/utils2.c			\

OBJS =	${SRCS:.c=.o}

CC =	gcc

CFLAGS = -Wall -Wextra -Werror -I includes -g -pthread -fsanitize=address

NAME =	philo

RM =	rm -rf

all:	${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re