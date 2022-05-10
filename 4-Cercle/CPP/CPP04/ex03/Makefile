# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 16:34:55 by armendes          #+#    #+#              #
#    Updated: 2022/05/10 16:39:34 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp\
				AMateria.cpp

OBJS =	${SRCS:.cpp=.o}

INCLUDES =	AMateria.hpp

CC =	c++

CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -I includes

NAME =	AMateria

RM =	rm -rf

%.o:	%.cpp ${INCLUDES}
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
