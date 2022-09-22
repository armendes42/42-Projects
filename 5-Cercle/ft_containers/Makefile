# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:04:22 by armendes          #+#    #+#              #
#    Updated: 2022/09/22 15:27:08 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	vector_test.cpp

OBJS =	${SRCS:.cpp=.o}

INCLUDES =	enable_if.hpp\
			equal.hpp\
			is_integral.hpp\
			lexicographical_compare.hpp\
			pair.hpp\
			iterator_traits.hpp\
			iterator.hpp\
			nullptr.hpp\
			reverse_iterator.hpp\
			vector.hpp\

CC =	c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I includes

NAME = containers

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
