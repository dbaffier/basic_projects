# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 13:53:00 by dbaffier          #+#    #+#              #
#    Updated: 2018/04/09 11:48:17 by dbaffier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LDFLAGS = -L

LDLIBS = -lft

SRCS =		ft_isdigit.c		\
			ft_isalpha.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_atoi.c			\
			ft_bzero.c			\
			ft_memccpy.c		\
			ft_memcpy.c			\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memmove.c		\
			ft_memset.c			\
			ft_strcat.c			\
			ft_strchr.c			\
			ft_strcmp.c			\
			ft_strcpy.c			\
			ft_strdup.c			\
			ft_strlen.c			\
			ft_strncmp.c		\
			ft_strncpy.c		\
			ft_strlcat.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_strstr.c			\
			ft_memalloc.c		\
			ft_memdel.c			\
			ft_strnew.c			\
			ft_strdel.c			\
			ft_strclr.c			\
			ft_striter.c		\
			ft_striteri.c		\
			ft_strmap.c			\
			ft_strmapi.c		\
			ft_strequ.c			\
			ft_strnequ.c		\
			ft_strsub.c			\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_strsplit.c		\
			ft_itoa.c			\
			ft_putchar.c		\
			ft_putstr.c			\
			ft_putendl.c		\
			ft_putnbr.c			\
			ft_putchar_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_putstr_fd.c		\
			ft_strncat.c		\
			ft_lstnew.c			\
			ft_lstdelone.c		\
			ft_lstdel.c			\
			ft_lstadd.c			\
			ft_lstiter.c		\
			ft_lstmap.c			\
			ft_copyuntil.c		\
			ft_countwords.c		\
			ft_islower.c		\
			ft_isupper.c		\
			ft_lstcount.c		\
			ft_lstpushback.c	\
			ft_strjoinch.c		

OBJS = $(SRCS:.c=.o)
	INC = ./inc/

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re


