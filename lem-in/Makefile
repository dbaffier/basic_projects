# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 05:26:06 by dbaffier          #+#    #+#              #
#    Updated: 2019/07/12 01:01:32 by mmonier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM_IN		= lem-in

CC			= gcc 
CFLAGS		=  -Wall -Werror -Wextra
CFLAGS		+= -std=c11 -Wmissing-prototypes -pedantic -pedantic-errors

ifeq ($(DEBUG),yes)
	CFLAGS += -O0 -fno-inline -DDEBUG
endif

LIBFT_PATH	= libft
LIBFT_LIB	= $(LIBFT_PATH)/libft.a
LIBFT_LINK	= -L$(LIBFT_PATH) -lft

DEBUG = -DJOBS_DEBUG

INC_DIR		= inc
INCS		= -I$(LIBFT_PATH)/ -I$(INC_DIR)

OBJS_DIR	= objs/

OBJS		+= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

RM			= /bin/rm -rf

SRCS_DIR	= src/

SRCS		+=	lem_in.c						\
				create_road.c					\

PRS_DIR		= $(SRCS_DIR)parsing/
SRCS		+= parse_hash.c						\
			  parse_links.c						\
			  parse_room.c						\
			  parsing.c							\
			  parse_ant.c						\
			  init_parsing.c					\
			  is_treatable.c					\

TOOLS_DIR	= $(SRCS_DIR)tools/
SRCS		+= displays_quit.c					\
				ft_strcdup.c					\
				node_room.c						\
				mat.c							\
				dup_path.c						\
				move_ant.c						\

YELLOW 		= \x1b[1;33m
RED			= \x1b[1;31m
GREEN		= \x1b[1;32m
RESET		= \x1b[0m

all: $(OBJS_DIR) $(LEM_IN)

$(LEM_IN): $(OBJS)
	$(CC) $^ -o $@ $(LIBFT_LINK) $(DEBUG)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCS) $(DEBUG)  -I $(INC_DIR) -I $(LIBFT_PATH)/$(INC_DIR)

$(OBJS_DIR)%.o: $(PRS_DIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCS) -I $(INC_DIR) -I $(LIBFT_PATH)/$(INC_DIR)

$(OBJS_DIR)%.o: $(TOOLS_DIR)%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(INCS) -I $(INC_DIR) -I $(LIBFT_PATH)/$(INC_DIR)

$(OBJS_DIR):
	@mkdir -p $@

$(LIBFT_LIB):
	make -C $(LIBFT_PATH)

clean:
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@$(RM) $(LEM_IN)

re: fclean all

debug: DEBUG += -g3 -fsanitize=address -DDEBUG -g
debug: re

.PHONY: clean fclean all re
