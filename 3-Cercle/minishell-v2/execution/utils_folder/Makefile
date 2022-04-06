# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imaalem <imaalem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 14:24:37 by imaalem           #+#    #+#              #
#    Updated: 2022/03/28 17:11:55 by imaalem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = execution

CFLAGS = -Wall -Werror -Wextra -pthread -I execution.h

SRC =	execution.c

OBJ = $(SRC:.c=.o) 

all : $(NAME)

$(NAME) : $(OBJ)
			clang -o $(NAME) $(OBJ) $(CFLAGS)

clean :
			rm -rf $(OBJ)

fclean : clean
			rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
