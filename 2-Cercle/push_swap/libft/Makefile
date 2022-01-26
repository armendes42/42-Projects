# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 00:07:24 by armendes          #+#    #+#              #
#    Updated: 2022/01/26 16:58:10 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_putstr_fd.c		\
			ft_split.c			\
			ft_isdigit.c		\
			ft_atoi.c			\
			ft_strjoin.c		\
			ft_strlen.c			\
			ft_itoa.c			\
			ft_strncmp.c		\
			ft_strlcpy.c		\

OBJS	=	${SRCS:.c=.o}

NAME	=	libft.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

all:		${NAME}

$(NAME):	${OBJS}
			ar -rcs ${NAME} ${OBJS}

clean:	
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
