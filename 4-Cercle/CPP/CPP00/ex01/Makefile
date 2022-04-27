# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 16:11:01 by armendes          #+#    #+#              #
#    Updated: 2022/03/30 16:48:04 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp		\
		PhoneBook.cpp	\
		Contact.cpp		\

OBJS =	${SRCS:.cpp=.o}

CC =	c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -I includes

NAME =	PhoneBook

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