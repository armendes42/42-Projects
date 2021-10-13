# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 21:24:06 by armendes          #+#    #+#              #
#    Updated: 2021/10/13 17:21:08 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	libft/ft_isdigit.c\
				libft/ft_isspace.c\
				libft/ft_itoa_base.c\
				libft/ft_strdup.c\
				libft/ft_strjoin.c\
				libft/ft_strlen.c\
				converters/convert_cap_hexa.c\
				converters/convert_char.c\
				converters/convert_hexa.c\
				converters/convert_integer.c\
				converters/convert_percent.c\
				converters/convert_pointer.c\
				converters/convert_string.c\
				converters/convert_uinteger.c\
				printers/print_pointer.c\
				printers/print_string.c\
				printers/print_char.c\
				printers/print_cap_hexa.c\
				printers/print_hexa.c\
				printers/print_integer.c\
				printers/print_uinteger.c\
				printers/print_percent.c\
				srcs/ft_printf.c\
				srcs/init_structs.c\
				srcs/parse_format.c\
				srcs/print_format.c\
				srcs/utils.c

OBJS		=	${SRC:.c=.o};

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Werror -I includes

NAME		=	libftprintf.a

RM			=	rm -f

all:		${NAME}

${NAME}:	${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
