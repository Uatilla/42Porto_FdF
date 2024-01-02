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

NAME		=	fdf

# Commands
CC			= cc
RM			= rm -rf

# Diretories
SRCS_DIR	=	srcs
OBJS_DIR	=	objs
MLX_DIR		=	./libraries/mlx
FT_PRINTF_DIR	=	./libraries/ft_printf
LIBFT_DIR	=	./libraries/libft
INCLUDES	=	includes


# Flags
CFLAGS		= -Wall -Wextra -Werror -g 
MLXFLAGS	= -lmlx -lXext -lX11 -lm
MK_FLAG		= --no-print-directory

# Files
SRCS		=	main.c
OBJS		=	$(SRCS:%.c=$(OBJS_DIR)/%.o)
LIBMLX		=	./libraries/mlx/libmlx.a
FT_PRINTF	=	./libraries/ft_printf/libftprintf.a
LIBFT		=	./libraries/libft/libft.a

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX) $(FT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_DIR) $(MLXFLAGS) $(FT_PRINTF) $(LIBFT) -o $(NAME)
	printf "\nCompiling		$(GREEN)[OK]$(RESET)\n"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	printf "Making binary files	$(YELLOW)[OK]$(RESET)\n"
	mkdir -p $(@D)
	$(CC) -I $(INCLUDES) $(CFLAGS) -c $< -o $@

$(LIBMLX):
	printf "Making Libmlx		$(YELLOW)[OK]$(RESET)\n\n"
	$(MAKE) $(MK_FLAG) -sC $(MLX_DIR)

$(FT_PRINTF):
	printf "Making Ft_printf		$(YELLOW)[OK]$(RESET)\n\n"
	$(MAKE) $(MK_FLAG) -sC $(FT_PRINTF_DIR)

$(LIBFT):
	printf "Making Libft		$(YELLOW)[OK]$(RESET)\n\n"
	$(MAKE) $(MK_FLAG) -sC $(LIBFT_DIR)

clean:
	$(RM) $(OBJS_DIR)
	printf "clean FdF files			$(CYAN)[OK]$(RESET)\n"
	$(MAKE) $(MK_FLAG) clean -sC $(MLX_DIR)
	$(MAKE) $(MK_FLAG) clean -sC $(FT_PRINTF_DIR)
	$(MAKE) $(MK_FLAG) clean -sC $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) $(MK_FLAG) fclean -sC $(FT_PRINTF_DIR)
	$(MAKE) $(MK_FLAG) fclean -sC $(LIBFT_DIR)
	printf "fclean			$(CYAN)[OK]$(RESET)\n"
	
re: fclean all

.PHONY: all clean fclean re
