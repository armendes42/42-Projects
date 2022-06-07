# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 14:49:33 by armendes          #+#    #+#              #
#    Updated: 2022/06/07 14:51:45 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =

OBJS =	${SRCS:.c=.o}

INCLUDES =

CC =	gcc

CFLAGS = -Wall -Wextra -Werror -I includes

NAME =

RM =	rm -rf

%.o:	%.c ${INCLUDES}
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
