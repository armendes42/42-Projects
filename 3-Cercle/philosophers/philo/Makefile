# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 18:19:27 by armendes          #+#    #+#              #
#    Updated: 2022/02/09 16:47:47 by armendes         ###   ########.fr        #
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

OBJS =	${SRCS:.c=.o};

CC =	gcc

CFLAGS =	-Wall -Wextra -Werror -pthread -I includes -g -fsanitize=thread

NAME =	philo

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