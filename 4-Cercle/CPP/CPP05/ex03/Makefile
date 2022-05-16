# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 18:30:18 by armendes          #+#    #+#              #
#    Updated: 2022/05/16 16:48:30 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp\
				Bureaucrat.cpp\
				Form.cpp\
				ShrubberyCreationForm.cpp\
				RobotomyRequestForm.cpp\
				PresidentialPardonForm.cpp\
				Intern.cpp

OBJS =	${SRCS:.cpp=.o}

INCLUDES =	Bureaucrat.hpp\
						Form.hpp\
						ShrubberyCreationForm.hpp\
						RobotomyRequestForm.hpp\
						PresidentialPardonForm.hpp\
						Intern.hpp

CC =	c++

CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -I includes

NAME =	Intern

RM =	rm -rf

%.o:	%.cpp ${INCLUDES}
		${CC} ${FLAGS} -c $< -o $@

all:	${NAME} Makefile

${NAME}:	${OBJS}	Makefile
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
