# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 20:48:40 by armendes          #+#    #+#              #
#    Updated: 2022/05/09 15:28:36 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp\
				ClapTrap.cpp\
				ScavTrap.cpp

OBJS =	${SRCS:.cpp=.o}

INCLUDES =	Claptrap.hpp\
						ScavTrap.hpp

CC =	c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I includes

NAME = Serena

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
