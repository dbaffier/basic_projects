# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 13:53:00 by dbaffier          #+#    #+#              #
#    Updated: 2018/11/13 11:19:26 by dbaffier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
NAME1 = minishell_debug

CC = gcc

CFLAGS += -Wall -Wextra -Werror -g
DEBUG = -DDEBUG -g

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
SRC_PATH1	= ./src/
INC_DIR		= includes
INC_LIB		= -I $(LIB_PATH)/$(INC_DIR)
CPP_F		= -I inc

SRC_NAME	=	$(shell ls $(SRC_PATH) | grep -E ".+\.c")

OK = "  \x1b[0;37;40m\033[1;32m   \x1b[1;31;34m"

OBJ_PATH 	= obj
OBJ_PATH1 	= obj_debug

OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ_NAME1	= $(SRC_NAME:.c=.o)

SRC	= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ	= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

SRC1 = $(addprefix $(OBJ_PATH1)/, $(OBJ_NAME1))
OBJ1 = $(addprefix $(OBJ_PATH1)/, $(OBJ_NAME1))

all: $(NAME)
debug: $(NAME1)

$(NAME): $(OBJ)
	@echo ""
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIB_LINK)

$(NAME1): $(OBJ1)
	make -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(DEBUG) $^ -o $@ $(LIB_LINK)
	make clean -C .
	
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@echo $(OK) | tr -d "\n"
	$(CC) $(CFLAGS) $(CPP_F) $(INC_LIB) -o $@ -c $<

$(OBJ_PATH1)/%.o: $(SRC_PATH1)/%.c
	mkdir -p $(OBJ_PATH1) 2> /dev/null || true
	$(CC) $(CFLAGS) $(DEBUG) $(CPP_F) $(INC_LIB) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH1) || true
	@rm -rf $(OBJ_PATH) || true

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(NAME)
	@rm -f $(NAME1)

re: fclean all

re_debug: fclean debug

nn:
	norminette $(SRC)
	norminette inc/

.PHONY: clean fclean all re
