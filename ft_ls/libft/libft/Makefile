# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 13:53:00 by dbaffier          #+#    #+#              #
#    Updated: 2018/09/11 18:14:45 by dbaffier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LDFLAGS = -L

LDLIBS = -lft

SRCS =		strings/ft_isdigit.c		\
			strings/ft_isalpha.c		\
			print/ft_putsl.c			\
			strings/ft_isalnum.c		\
			strings/ft_isascii.c		\
			strings/ft_isprint.c		\
			strings/ft_toupper.c		\
			strings/ft_tolower.c		\
			strings/get_next_line.c		\
			strings/ft_isnonprintable.c	\
			memory/ft_memccpy.c			\
			memory/ft_memcpy.c			\
			memory/ft_memchr.c			\
			memory/ft_memcmp.c			\
			memory/ft_memmove.c			\
			memory/ft_memset.c			\
			memory/ft_memalloc.c		\
			memory/ft_memdel.c			\
			memory/ft_realloc.c			\
			strings/ft_bzero.c			\
			strings/ft_strcat.c			\
			strings/ft_strchr.c			\
			strings/ft_strcmp.c			\
			strings/ft_strcpy.c			\
			strings/ft_strdup.c			\
			strings/ft_strlen.c			\
			strings/ft_strndup.c		\
			strings/ft_strncmp.c		\
			strings/ft_strncpy.c		\
			strings/ft_strlcat.c		\
			strings/ft_strnstr.c		\
			strings/ft_strrchr.c		\
			strings/ft_strstr.c			\
			strings/ft_strnew.c			\
			strings/ft_strdel.c			\
			strings/ft_strclr.c			\
			strings/ft_striter.c		\
			strings/ft_striteri.c		\
			strings/ft_strmap.c			\
			strings/ft_strmapi.c		\
			strings/ft_strequ.c			\
			strings/ft_strnequ.c		\
			strings/ft_strsub.c			\
			strings/ft_strjoin.c		\
			strings/ft_strtrim.c		\
			strings/ft_strsplit.c		\
			strings/ft_strncat.c		\
			strings/ft_strjoinch.c		\
			strings/ft_copyuntil.c		\
			strings/ft_countwords.c		\
			strings/ft_islower.c		\
			strings/ft_isupper.c		\
			strings/ft_strrev.c			\
			strings/ft_strnlen.c		\
			strings/ft_wstrnlen.c		\
			strings/ft_strendswith.c	\
			strings/ft_pathjoin.c		\
			strings/ft_wstrlen.c		\
			print/ft_putchar.c			\
			print/ft_putstr.c			\
			print/ft_putendl.c			\
			print/ft_putnbr.c			\
			print/ft_putchar_fd.c		\
			print/ft_putendl_fd.c		\
			print/ft_putnbr_fd.c		\
			print/ft_putstr_fd.c		\
			print/ft_putwchar.c			\
			print/ft_putnstr.c			\
			print/ft_putnwstr.c			\
			print/ft_putwstr.c			\
			print/ft_putnbr_max.c			\
			print/ft_putnbr_max_fd.c	\
			lists/ft_lstnew.c			\
			lists/ft_lstcount.c			\
			lists/ft_lstpushback.c		\
			lists/ft_lstdelone.c		\
			lists/ft_lstdel.c			\
			lists/ft_lstadd.c			\
			lists/ft_lstiter.c			\
			lists/ft_lstmap.c			\
			maths/ft_itoa.c				\
			maths/ft_pow.c				\
			maths/ft_atoi.c				\
			maths/intlen.c			\
			maths/ft_max.c				\
			maths/ft_putnbr_base.c		\
			maths/ft_nbase_len.c

OK = "\033[1;37m→$(RESET)\x1b[35m"
OK2 = "  \033[1;32m⏎  $(RESET)"

OBJS = $(SRCS:.c=.o)
	INC = ./inc/

$(NAME): $(OBJS)
	@echo "\n"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo " " $(OK) "  Create" $(NAME) " "$(OK2)

%.o: %.c
	@echo $(OK) | tr -d "\n"
	@$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
