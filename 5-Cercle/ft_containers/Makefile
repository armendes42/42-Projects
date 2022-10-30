# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:04:22 by armendes          #+#    #+#              #
#    Updated: 2022/10/30 23:36:03 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp

OBJS =	${SRCS:.cpp=.o}

INCLUDES =	enable_if.hpp\
			equal.hpp\
			is_integral.hpp\
			iterator_traits.hpp\
			lexicographical_compare.hpp\
			make_pair.hpp\
			pair.hpp\
			red_black_iterator.hpp\
			reverse_iterator.hpp\
			vector_iterator.hpp\
			stack.hpp\
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
