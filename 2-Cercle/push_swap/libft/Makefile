# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 00:07:24 by armendes          #+#    #+#              #
#    Updated: 2022/01/10 18:59:53 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_lstadd_back.c	\
			ft_lstadd_front.c	\
			ft_lstclear.c		\
			ft_lstdelone.c		\
			ft_lstiter.c		\
			ft_lstlast.c		\
			ft_lstmap.c			\
			ft_lstnew.c			\
			ft_lstsize.c		\
			ft_putstr_fd.c		\
			ft_split.c			\
			ft_isdigit.c		\
			ft_atoi.c			\
			ft_strjoin.c		\
			ft_strlen.c			\

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
