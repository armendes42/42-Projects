# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 18:39:50 by armendes          #+#    #+#              #
#    Updated: 2021/10/12 19:29:51 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -I includes

RM		= rm -rf

all:	${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${SRCS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
