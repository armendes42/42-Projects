# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armendes <armendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 16:32:19 by armendes          #+#    #+#              #
#    Updated: 2021/12/23 19:08:50 by armendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	=   so_long

CC          	=   gcc

SRC_DIR			= 	$(shell find srcs -type d)
INC_DIR			= 	$(shell find includes -type d) \
					$(shell find libs/libft -type d) \
					$(shell find libs/gnl -type d)
LIB_DIR			=	libs/libft libs/gnl
OBJ_DIR			=	.objs
LIB				=	libs/libft/libft.a libs/gnl/gnl.a

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

UNAME_S			=	$(shell uname -s)
ifeq ($(UNAME_S), Linux)
LIB_DIR			+=	libs/minilibx_linux
LIB				+=	libs/minilibx_linux/libmlx_Linux.a
MLX				=	-lXext -lX11
IFLAGS			=	$(foreach dir, $(INC_DIR), -I $(dir)) \
					-I libs/minilibx_linux
else
LIB_DIR			+=	libs/minilibx_mac
MLX				=	libs/minilibx_mac/libmlx.dylib -framework OpenGL -framework AppKit
IFLAGS			=	$(foreach dir, $(INC_DIR), -I $(dir)) \
					-I libs/minilibx_mac
endif

BUILD			=	$(CC) $(CFLAGS) ${IFLAGS} $(OBJ) $(LFLAGS) $(LIB) -o $(NAME) ${MLX}

# library -----------------------------------------------------------

SRC			= 	error.c\
				init_struct1.c\
				init_struct2.c\
				loops.c\
				map1.c\
				map2.c\
				render_all.c\
				render_collectibles.c\
				render_exit.c\
				render_map.c\
				render_player.c\
				render_utils.c\
				so_long.c

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR_BONUS)/, $(SRC:%.c=%.o))

# Compilation flags -------------------------------------------------

CFLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir))

# Colors ------------------------------------------------------------

_NOCOLOR=\033[0m
_RED=\033[0;31m
_GREEN=\033[0;32m
_ORANGE=\033[0;33m
_BLUE=\033[0;34m
_PURPLE=\033[0;35m
_CYAN=\033[0;36m
_LIGHTGRAY=\033[0;37m
_DARKGRAY=\033[1;30m
_LIGHTRED=\033[1;31m
_LIGHTGREEN=\033[1;32m
_YELLOW=\033[1;33m
_LIGHTBLUE=\033[1;34m
_LIGHTPURPLE=\033[1;35m
_LIGHTCYAN=\033[1;36m
_WHITE=\033[1;37m

# main part ---------------------------------------------------------

all:
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make $(NAME)

bonus: fclean
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make BONUS=$(D_BONUS) $(NAME)

show:
	@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
	@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LIB_DIR :\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)$(_WHITE)"

install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir);)

re-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) re;)

fclean-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) fclean;)

$(NAME): install $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@${BUILD}
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(BONUS) $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

re:	fclean all

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all bonus show install re-install re clean fclean
