# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonier <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 14:55:15 by mmonier           #+#    #+#              #
#    Updated: 2020/01/03 14:28:57 by mmonier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FDF			= fdf

CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror
CFLAGS 		+= -g3 -std=c11 -Wmissing-prototypes -pedantic -pedantic-errors

LIBFT_PATH	= libft
LIBFT_LIB	= $(LIBFT_PATH)/libft.a
LIBFT_LINK	= -L$(LIBFT_PATH) -lft

MLX_PATH 	= minilibx
MLX_LINK 	= -lmlx -framework OpenGL -framework AppKit

INC_DIR		= inc
INCS		= -I$(LIBFT_PATH)/ -I$(INC_DIR)

OBJS_DIR 	= objs/
OBJS		+= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

RM			= /bin/rm -rf

SRCS_DIR	= src/

SRCS 		+= main.c		\
			   parse.c		\
			   splitws.c	\
			   keyhook.c	\
			   init.c		\
			   fdf.c		\
			   bresenham.c	\
			   rotate.c		\

PADDING		= 10

all : $(LIBFT_LIB) $(MLX) $(OBJS_DIR) $(FDF)

$(FDF) : $(OBJS)
	@$(CC) -fsanitize=address $^ -o $@ $(LIBFT_LINK) $(MLX_LINK)
	@echo "\n"
	@printf "  \033[90;5m〉 \033[25m\033[92mCompilation DONE\033[90;5m 〈\033[25m\n\n"
	@printf "\033[90m   [ \033[37m./fdf file.fdf ... ]\033m\n"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCS) -I $(INC_DIR) -I $(LIBFT_PATH)/$(INC_DIR) -I $(MLX_PATH)
	@printf "\033[94m♢ \033m"

$(OBJS_DIR) :
	@mkdir -p $@

$(MLX) :
	@make -C $(MLX_PATH)
$(LIBFT_LIB) :
	@make -C $(LIBFT_PATH)

clean :
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT_PATH) clean
	@printf '\033[91m%-$(PADDING)s\033m' "status :" ".o deleted"
	@echo "\n"

fclean :
	@make clean
	@$(RM) $(FDF)
	@printf "\033[90m ⌦  \033[91mAll the mess cleaned up \033[90m⌫\033m\n\n"

re :
	@make fclean
	@make all

.PHONY : clean fclean all re
