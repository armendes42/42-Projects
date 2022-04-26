# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 19:53:49 by armendes          #+#    #+#              #
#    Updated: 2022/04/26 20:48:14 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	Account.cpp	\
		tests.cpp	\

OBJS =	${SRCS:.cpp=.o}

CC =	c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I includes

NAME =	Account

RM =	rm -rf

all:	${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re