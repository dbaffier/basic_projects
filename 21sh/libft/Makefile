# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 13:53:00 by dbaffier          #+#    #+#              #
#    Updated: 2019/01/30 14:35:11 by dbaffier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

RM = rm -rf

LIB_PATH = libft
LIB = $(LIB_PATH)/libft.a
LIB_LINK = -L $(LIB_PATH) -lft

INC_DIR = includes
INCS = -I $(LIB_PATH)/ -I $(INC_DIR)

SRCS =	srcs/ft_printf.c	\
		srcs/tools/flags_handling.c		\
		srcs/conversions/convert_char.c		\
		srcs/conversions/convert_wchar.c	\
		srcs/conversions/convert_string.c	\
		srcs/conversions/convert_wstring.c	\
		srcs/conversions/convert_binary.c	\
		srcs/conversions/convert_modulo.c	\
		srcs/conversions/convert_unsign.c	\
		srcs/conversions/convert_hexa.c		\
		srcs/conversions/convert_octal.c	\
		srcs/conversions/convert_address.c	\
		srcs/conversions/convert_l.c		\
		srcs/conversions/convert_int.c		\
		srcs/conversions/convert_color.c	\
		srcs/tools/padding.c				\
		srcs/tools/init_struct.c			\
		srcs/tools/shuffle.c				\
		srcs/tools/ft_putunsign.c			\
		srcs/tools/ft_nstrlen.c				\
		srcs/tools/handle_prefix_max.c		\
		srcs/tools/handle_length.c			\
		srcs/converter.c

OK = "  \033[1;37m→$(RESET)\x1b[35m"
OK2 = "  \033[1;32m⏎  $(RESET)"

CFLAGS +=  -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_PATH)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@echo $(OK) "  ran lib" $(NAME) $(OK2)
	@echo "\n"

%.o: %.c
	$(CC) -o $@ $(CFLAGS) $(INCS) -c $<

clean:
	@$(RM) $(OBJS)
	@make -C $(LIB_PATH) clean
	@echo $(OK) "  Remove" $(NAME) | tr -d "\n"
	@echo $(OK2)

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo $(OK) "  Delete" $(NAME) | tr -d "\n"
	@echo $(OK2)

re: fclean all

.PHONY: clean fclean all re
