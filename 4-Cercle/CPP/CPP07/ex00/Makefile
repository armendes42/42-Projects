# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 15:41:15 by armendes          #+#    #+#              #
#    Updated: 2022/05/31 15:41:47 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =

OBJS =	${SRCS:.cpp=.o}

INCLUDES =

CC =	c++

CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -I includes

NAME =	

RM =	rm -rf

%.o:	%.cpp ${INCLUDES}
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME} Makefile

${NAME}:	${OBJS}	Makefile
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
