# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uviana-a <uviana-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/23 18:57:07 by uviana-a          #+#    #+#              #
#    Updated: 2023/12/23 18:57:09 by uviana-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

# Colors
RESET 		=	\033[0m	
BLACK 		=	\033[1;30m
RED 		=	\033[1;31m
GREEN 		=	\033[1;32m
YELLOW 		=	\033[1;33m
BLUE 		=	\033[1;34m
PURPLE 		=	\033[1;35m
CYAN 		=	\033[1;36m
WHITE 		=	\033[1;37m

NAME = fdf

# Commands
CC			=	cc
RM			=	rm -rf

# Folders
SRCS_DIR	=	./srcs
OBJS_DIR	=	./objs
MLX_DIR		=	./mlx 


# Flags
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-lmlx -lX11 -lXext -lm

# Files
SRCS			=	$(addprefix $(SRCS_DIR)/,main.c)
OBJS		=	$(SRCS:.=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(MLX_DIR) -L $(MLX_DIR) $(OBJS) $(MLXFLAGS) -o $(NAME)
	printf "Compiling		$(GREEN)[OK]$(RESET)\n"

#clean:
#	$(RM) $(OBJS)
#	printf "clean			$(CYAN)[OK]$(RESET)\n"

fclean:
	$(RM) $(NAME)
	printf "fclean			$(CYAN)[OK]$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re norm