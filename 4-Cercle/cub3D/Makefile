# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 14:49:33 by armendes          #+#    #+#              #
#    Updated: 2022/06/09 19:21:11 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/main.c\
				srcs/error.c\
				srcs/init_struct.c\
				srcs/loops.c\
				srcs/game_loop.c\
				srcs/utils.c\

LIB_DIR =	libs/libft libs/gnl libs/mlx

LIB_FLAGS =	-L libs/libft -L libs/gnl -L libs/mlx

LIB_NAME =	libs/libft/libft.a libs/gnl/gnl.a libs/mlx/libmlx_Linux.a

MLX_FLAGS =	-lm -lmlx_Linux -lXext -lX11

OBJS =	${SRCS:.c=.o}

CC =	gcc

CFLAGS =	-Wall -Wextra -Werror -g -I includes -I libs/libft -I libs/gnl -I libs/mlx

NAME =	cub3D

RM =	rm -rf

all:	${NAME}

${NAME}:	${OBJS}
			make -C libs/libft
			make -C libs/gnl
			make -C libs/mlx
			${CC} ${CFLAGS} ${LIB_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS} ${LIB_NAME}

clean:
		make clean -C libs/libft
		make clean -C libs/gnl
		make clean -C libs/mlx
		${RM} ${OBJS}

fclean:	clean
		${RM} ${LIB_NAME}
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
