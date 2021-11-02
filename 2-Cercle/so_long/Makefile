# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 18:39:50 by armendes          #+#    #+#              #
#    Updated: 2021/10/25 15:49:16 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/so_long.c\
		srcs/parsing_map.c\
		srcs/get_next_line.c\
		srcs/get_next_line_utils.c\
		srcs/ft_strdup.c

OBJS 		= ${SRCS:.c=.o}

UNAME		:= $(shell uname)

PATH_MLX	= mlx_linux
CC 			= cc -g2 -fsanitize=address
CFLAGS		= -Wall -Wextra -Werror -I includes
RM			= rm -rf
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -Wl,-rpath=./bass/,-rpath=./mlx/,-rpath=./delay/

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(FLAGS) ${SRCS}

clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		all clean fclean re
