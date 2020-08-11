# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/12 05:26:06 by dbaffier          #+#    #+#              #
#    Updated: 2019/06/25 10:44:39 by dbaffier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER		= checker
PUSH_SWAP	= push_swap

CC			= gcc 
CFLAGS		=  -Wall -Werror -Wextra
CFLAGS		+= -std=c11 -Wmissing-prototypes -pedantic -pedantic-errors

LIBFT_PATH	= libft
LIBFT_LIB	= $(LIBFT_PATH)/libft.a
LIBFT_LINK	= -L$(LIBFT_PATH) -lft

INC_DIR		= inc
INCS		= -I$(LIBFT_PATH)/ -I$(INC_DIR)

OBJS_DIR	= objs/

OBJS_PS		+= $(addprefix $(OBJS_DIR), $(SRCS_PS:.c=.o))
OBJS_CK		+= $(addprefix $(OBJS_DIR), $(SRCS_CK:.c=.o))

RM			= /bin/rm -rf

SRCS_DIR	= src/

CK_DIR		= $(SRCS_DIR)
SRCS_CK		+=	checker.c				\
				handle_instructions.c	\
			   	print_stack.c			\
			   	print_stack_color.c		\

PS_DIR		= $(SRCS_DIR)
SRCS_PS		+= push_swap.c				\
			   lst_sort_three.c			\
			   lst_sort_five.c			\
			   lst_sort_reverse.c		\
			   lst_sort.c				\
			   print_stack.c			\
			   moves.c					\
			   min_max.c				\
			   evaluate.c				\
			   print_stack_color.c		\


TOOLS_DIR	= $(SRCS_DIR)tools/
SRCS_PS		+= atoin.c					\
			   lnk_lst.c				\
			   lst_sorted.c				\
			   lst_sorted_reverse.c		\
			   exec_instruction.c		\
			   help.c					\
			   global_flags.c			\
			   check_digits_fd.c		\
			   print_color_tools.c		\

SRCS_CK		+= atoin.c					\
			   lnk_lst.c				\
			   lst_sorted.c				\
			   lst_sorted_reverse.c		\
			   help.c					\
			   global_flags.c			\
			   exec_instruction.c		\
			   check_digits_fd.c		\
			   print_color_tools.c		\

PRS_DIR		= $(SRCS_DIR)parsing/
SRCS_PS		+= check_input.c			\
			   duplicate_entry.c		\
			   print_error.c			\
			   parse_opts.c				\
			   read_parse_file.c		\

SRCS_CK		+= check_input.c			\
			   duplicate_entry.c		\
			   print_error.c			\
			   parse_opts.c				\
			   read_parse_file.c		\

INS_DIR		= $(SRCS_DIR)instructions/
SRCS_CK		+= pa.c						\
			   pb.c						\
			   sa.c						\
			   sb.c						\
			   ss.c						\
			   ra.c						\
			   rb.c						\
			   rr.c						\
			   rra.c					\
			   rrb.c					\
			   rrr.c					\

SRCS_PS		+= pa.c						\
			   pb.c						\
			   sa.c						\
			   sb.c						\
			   ss.c						\
			   ra.c						\
			   rb.c						\
			   rr.c						\
			   rra.c					\
			   rrb.c					\
			   rrr.c					\

YELLOW 		= \x1b[1;33m
RED			= \x1b[1;31m
GREEN		= \x1b[1;32m
RESET		= \x1b[0m

all: $(OBJS_DIR) $(LIBFT_LIB) $(PUSH_SWAP) $(CHECKER)

$(OBJS_DIR):
	@mkdir -p $@

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(PUSH_SWAP): $(OBJS_PS)
	@echo "$(GREEN)push_swap created$(RESET)"
	@$(CC) $^ -o $@ $(LIBFT_LINK)

$(CHECKER): $(OBJS_CK)
	@echo "$(GREEN)checker created $(RESET)"
	@$(CC) $^ -o $@ $(LIBFT_LINK)

$(OBJS_DIR)%.o: $(INS_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCS) -I $(INC_DIR) -I $(LIBFT_PATH)/$(INC_DIR)

$(OBJS_DIR)%.o: $(PRS_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCS) -I $(INC_DIR) -I $(LIBFT_PATH)/$(INC_DIR)

$(OBJS_DIR)%.o: $(TOOLS_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCS) -I $(INC_DIR) -I $(LIBFT_PATH)/$(INC_DIR)

$(OBJS_DIR)%.o: $(PS_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCS) -I $(INC_DIR) -I $(LIBFT_PATH)/$(INC_DIR)

$(OBJS_DIR)%.o: $(CK_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INCS) -I $(INC_DIR) -I $(LIBFT_PATH)/$(INC_DIR)

clean:
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@echo "$(RED)checker deleted $(RESET)"
	@echo "$(RED)push_swap deleted $(RESET)"
	@$(RM) $(CHECKER)
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(PUSH_SWAP)

re: fclean all

.PHONY: clean fclean all re
