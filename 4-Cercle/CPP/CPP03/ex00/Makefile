# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 20:48:40 by armendes          #+#    #+#              #
#    Updated: 2022/05/05 20:51:52 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp\
				Claptrap.cpp

OBJS =	${SRCS:.cpp=.o}

INCLUDES =	Claptrap.hpp

CC =	c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I includes

NAME = ClapTrap

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
