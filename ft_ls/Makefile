# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 13:53:00 by dbaffier          #+#    #+#              #
#    Updated: 2018/09/19 01:50:11 by dbaffier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS += -Wall -Wextra -Werror -O3

RED			:= $(shell tput setaf 1)
GREEN		:= $(shell tput setaf 2)
YELLOW		:= $(shell tput setaf 3)
BLUE		:= $(shell tput setaf 4)
PURPLE		:= $(shell tput setaf 5)
RESET		:= $(shell tput setaf 7)

LIB_PATH	= libft
LIB			= $(LIB_PATH)/libft.a
LIB_LINK 	= -L$(LIB_PATH) -lft

SRC_PATH	= ./src/
INC_DIR		= includes
INC_LIB		= -I $(LIB_PATH)/$(INC_DIR)
CPP_F		= -I inc

SRC_NAME	=	$(shell ls $(SRC_PATH) | grep -E ".+\.c")

OK = "  \x1b[0;37;40m\033[1;32m♥   \x1b[1;31;31m"

OBJ_PATH 	= obj

OBJ_NAME	= $(SRC_NAME:.c=.o)

SRC	= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ	= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIB_LINK)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@echo $(OK) | tr -d "\n"
	$(CC) $(CFLAGS) $(CPP_F) $(INC_LIB) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH) || true

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)

re: fclean all

nn:
	norminette $(SRC)
	norminette inc/

.PHONY: clean fclean all re
