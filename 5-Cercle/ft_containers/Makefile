# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:04:22 by armendes          #+#    #+#              #
#    Updated: 2022/11/25 00:14:51 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FT =	main_ft.cpp

SRCS_STD =	main_std.cpp

OBJS_FT =	${SRCS_FT:.cpp=.o}

OBJS_STD =	${SRCS_STD:.cpp=.o}

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

NAME_FT = containers_ft

NAME_STD =	containers_std

RM =	rm -rf

%.o:	%.cpp ${INCLUDES}
		${CC} ${CFLAGS} -c $< -o $@

all:	${NAME_FT} ${NAME_STD} Makefile

${NAME_FT}:	${OBJS_FT} Makefile
			${CC} ${CFLAGS} ${OBJS_FT} -o ${NAME_FT}

${NAME_STD}:	${OBJS_STD} Makefile
			${CC} ${CFLAGS} ${OBJS_STD} -o ${NAME_STD}

clean:
	${RM} ${OBJS_FT} ${OBJS_STD}

fclean:		clean
	${RM} ${NAME_FT} ${NAME_STD}

re:			fclean all

.PHONY:		all clean fclean re
