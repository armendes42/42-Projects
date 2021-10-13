# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 18:39:50 by armendes          #+#    #+#              #
#    Updated: 2021/10/13 18:05:03 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/so_long.c

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

CC		= cc -I /usr/local/include

CFLAGS	= -Wall -Wextra -Werror -I includes

MLX		= -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

RM		= rm -rf

all:	${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${SRCS} ${MLX}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
