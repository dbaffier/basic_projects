# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonier <mmonier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 13:10:03 by mmonier           #+#    #+#              #
#    Updated: 2019/06/14 03:47:57 by dbaffier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

NAME	= libftprintf.a

SRC		=	src/ft_printf.c						\
			src/ft_dprintf.c					\
			src/ft_parse.c						\
			src/converter/get_converter.c		\
			src/converter/convert_c.c			\
			src/converter/convert_s.c			\
			src/converter/convert_o.c			\
			src/converter/convert_p.c			\
			src/converter/convert_x.c			\
			src/converter/convert_gx.c			\
			src/converter/convert_u.c			\
			src/converter/convert_f.c			\
			src/converter/convert_d.c			\
			src/converter/convert_b.c			\
			src/converter/convert_r.c			\
			src/converter/convert_gc.c			\
			src/converter/convert_gs.c			\
			src/converter/convert_gr.c			\
			src/converter/convert_k.c			\
			src/converter/convert_color.c		\
			src/converter/convert_star.c		\
			src/tools/float_to_string.c			\
			src/tools/ft_utoa.c					\
			src/tools/len_func.c				\
			src/tools/get_date.c				\
			src/tools/get_flags.c				\
			src/tools/write_wchar.c				\
			src/tools/get_valist.c				\
			src/tools/get_args.c				\
			src/tools/get_arg_int.c				\
			src/tools/convert_base.c			\
			src/tools/write_char.c				\
			src/tools/get_char_conv.c			\
			src/tools/apostrophe_flag.c			\
			src/tools/convert_ubase.c			\
			src/tools/ft_intmax_toa.c			\
			src/tools/check_mask.c				\
			src/tools/get_specifier.c			\
			src/tools/infinite.c				\

OBJ		= $(SRC:.c=.o)

FLAG	= -std=c99 -Wall -Werror -Wextra -pedantic -pedantic-errors

LIB		= libft/libft.a

INC		= inc/

all: $(NAME)

%.o:%.c	
	$(CC) -o $@ $(FLAG) -I $(INC) -c $<

$(NAME):	$(OBJ)
	@make -C libft/
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJ)

clean :
	make -C libft/ clean
	rm -rf $(OBJ)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
