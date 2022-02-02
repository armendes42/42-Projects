# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 20:21:54 by armendes          #+#    #+#              #
#    Updated: 2022/02/02 17:14:37 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/error.c				\
		srcs/init_struct1.c			\
		srcs/init_struct2.c			\
		srcs/loops.c				\
		srcs/map1.c					\
		srcs/map2.c					\
		srcs/render_all.c			\
		srcs/render_collectibles.c	\
		srcs/render_exit.c			\
		srcs/render_map.c			\
		srcs/render_player.c		\
		srcs/render_utils.c			\
		srcs/so_long.c

LIB_DIR =	libs/libft libs/gnl libs/minilibx_linux

LIB_FLAGS =	-L libs/libft -L libs/gnl -L libs/minilibx_linux

LIB_NAME =	libs/libft/libft.a libs/gnl/gnl.a libs/minilibx_linux/libmlx_Linux.a

MLX_FLAGS =	-lm -lmlx_Linux -lXext -lX11

OBJS =	${SRCS:.c=.o}

CC =	gcc

CFLAGS =	-Wall -Wextra -Werror -g -I includes -I libs/libft -I libs/gnl -I libs/minilibx_linux

NAME =	so_long

RM =	rm -rf

all:	${NAME}

${NAME}:	${OBJS}
			make -C libs/libft
			make -C libs/gnl
			make -C libs/minilibx_linux
			${CC} ${CFLAGS} ${LIB_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS} ${LIB_NAME}

clean:
		make clean -C libs/libft
		make clean -C libs/gnl
		make clean -C libs/minilibx_linux
		${RM} ${OBJS}

fclean:	clean
		${RM} ${LIB_NAME}
		${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
