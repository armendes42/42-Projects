# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 15:44:38 by armendes          #+#    #+#              #
#    Updated: 2021/10/11 17:04:44 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	srcs/ft_putstr_fd.c\
		srcs/ft_split.c\
		srcs/ft_strjoin.c\
		srcs/ft_strlcpy.c\
		srcs/ft_strlen.c\
		srcs/ft_strncmp.c\
		srcs/pipex.c\
		srcs/utils.c

OBJS =	${SRC:.=.o};

CC =	gcc

CFLAGS =	-Wall -Wextra -Werror -I includes

NAME =	pipex

RM =	rm -rf

all:	${NAME}

${NAME}:	${OBJS}
			CC -o ${NAME} ${SRCS}	

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
