# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 18:19:27 by armendes          #+#    #+#              #
#    Updated: 2022/01/24 19:26:35 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/philo.c		\
		srcs/check_arg.c	\
		srcs/init_struct.c	\
		srcs/philo_thread.c	\
		srcs/utils.c		\
		srcs/utils2.c		\

OBJS =	${SRCS:.c=.o};

CC =	cc

CFLAGS =	-Wall -Wextra -Werror -I includes

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