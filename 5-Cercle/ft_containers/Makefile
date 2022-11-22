# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:04:22 by armendes          #+#    #+#              #
#    Updated: 2022/11/23 18:32:29 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp

OBJS =	${SRCS:.cpp=.o}

INCLUDES =	iterator.hpp\
						map.hpp\
						stack.hpp\
						tree_algo.hpp\
						tree.hpp\
						tree_iterator.hpp\
						tree_types.hpp\
						type_traits.hpp\
						utility.hpp\
						vector_iterator.hpp\
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
