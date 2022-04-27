# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 18:27:00 by armendes          #+#    #+#              #
#    Updated: 2022/04/27 18:30:59 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp

OBJS =	${SRCS:.cpp=.o}

CC =	c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I includes

NAME =	Address

RM =	rm -rf

%.o:	%.cpp
		${CC} ${FLAGS} -c $< -o $@

all:	${NAME} Makefile

${NAME}:	${OBJS}	Makefile
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
