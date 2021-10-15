# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 18:39:50 by armendes          #+#    #+#              #
#    Updated: 2021/10/15 17:58:37 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/so_long.c\
		  srcs/parsing_map.c\
		  srcs/get_next_line.c\
		  srcs/get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

NAME	= so_long

CC		= cc -I /usr/local/include -fsanitize=address

CFLAGS	= -Wall -Wextra -Werror -I includes

MLX		= -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

RM		= rm -rf

all:	${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${MLX} -o ${NAME} ${SRCS}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
