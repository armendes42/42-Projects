# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 00:07:24 by armendes          #+#    #+#              #
#    Updated: 2021/10/13 17:20:15 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isdigit.c	\
			ft_isspace.c	\
			ft_itoa_base	\
			ft_strdup.c		\
			ft_strjoin.c	\
			ft_strlen.c

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
