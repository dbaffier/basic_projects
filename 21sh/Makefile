# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/19 18:44:25 by dbaffier          #+#    #+#              #
#    Updated: 2019/02/22 16:24:53 by tsisadag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

APP     	= 21sh
CC      	= gcc
RM      	= rm -rf
SRCEXT  	= c

SRC_DIR		=	src/
SRCS		:=	main.c					\
				set_tsh.c				\

BUILTIN_DIR	=	builtins/
SRCS		+=	builtins.c				\
				cd.c					\
				cd_2.c					\
				echo.c					\
				env.c					\
				env_1.c					\
				exit.c					\
				setenv.c				\
				setenv_1.c				\
				tools.c					\
				more_tools.c			\
				unsetenv.c				\

LEXER_DIR	=	lexer/
SRCS		+=	lex_settok.c			\
				lex_tok.c				\
				lexer.c					\
				lexer_utils.c			\

PARSE_DIR	=	parse/
SRCS		+=	astree.c				\
				exaust_command.c		\
				exaust_io_number.c		\
				exaust_operator.c		\
				parse.c					\
				parse_lexer.c			\

EXEC_DIR	=	execute/
SRCS		+=	dup.c					\
				execute.c				\
				execute_pipeline.c		\
				execute_rd_pipe.c		\
				execute_redir.c			\
				execute_set.c			\
				execute_single.c		\
				exit_status.c			\
				file_agregation.c		\
				herecdoc.c				\
				open_fd.c				\
				permissions.c			\
				redirections.c			\
				execute_first_pipe.c	\
				init_piped.c			\

PROMPT_DIR	=	prompt/
SRCS		+=	prompt.c				\

UTILS_DIR	=	utils/
SRCS		+=	change_env_value.c		\
				clone.c					\
				error.c					\
				free_tab.c				\
				ft_isnum.c				\
				ft_stringdigits.c		\
				get_env.c				\
				get_var.c				\

TERM_DIR	=	terminal/
SRCS		+=	alts.c					\
				dels.c					\
				env_tools.c				\
				get_line_tools.c		\
				heredoc.c				\
				heredoc_tools.c			\
				history.c				\
				history_term.c			\
				init.c					\
				quote.c					\
				read.c					\
				read_tools.c			\
				split_white.c			\
				term.c					\
				term_tools.c			\

SIGNAL_DIR	=	signal/
SRCS		+=	signal.c				\

EXPAND_DIR	=	expansions/
SRCS		+=	dollar_expand.c			\
				expansions.c			\
				remove_quotes.c			\
				tilde_expand.c			\
				tilde_expand2.c			\
				dollar_expand2.c		\

FREE_DIR	=	free/
SRCS		+=	free_astree.c			\
				free_shell.c			\

OBJS_DIR  	= obj/
OBJS		:= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

LIB_LINK 	= -Llibft/ -lft

INCLUDE 	= -I./inc

DEPS_DIR = .deps/
DEPS = $(addprefix $(DEPS_DIR), $(SRCS:.c=.d))

INC_LIB 	= -I libft/includes			\
				-I src/parse			\
				-I src/lexer			\
				-I src/execute			\
				-I src/prompt			\
				-I src/utils			\
				-I src/builtins			\
				-I src/expansions		\
				-I src/free				\
				-I src/terminal			\
				-I src/expansions		\

FLAGS  	= -Wall -Werror -Wextra $(INCLUDE)

all: $(OBJS_DIR) $(DEPS_DIR) $(APP)

$(OBJS_DIR):
	@mkdir -p $@

$(DEPS_DIR):
	@mkdir -p $@

$(APP): $(OBJS) 
	@echo $(OBJS)
	@make -C libft/
	$(CC) -lncurses $(OBJS) -o $@ $(LIB_LINK) 

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
$(OBJS_DIR)%.o: $(SRC_DIR)%.c $(DEPS_DIR)%.d
	$(CC) -MT $@ -MMD -MP -MF $(DEPS_DIR)$*.Td $(FLAGS) $(INC_LIB) -o $@ -c $<
	@mv -f $(DEPS_DIR)$*.Td $(DEPS_DIR)$*.d && touch $@

$(OBJS_DIR)%.o: $(SRC_DIR)$(BUILTIN_DIR)%.c
$(OBJS_DIR)%.o: $(SRC_DIR)$(BUILTIN_DIR)%.c $(DEPS_DIR)%.d
	$(CC) -MT $@ -MMD -MP -MF $(DEPS_DIR)$*.Td $(FLAGS) $(INC_LIB) -o $@ -c $<
	@mv -f $(DEPS_DIR)$*.Td $(DEPS_DIR)$*.d && touch $@

$(OBJS_DIR)%.o: $(SRC_DIR)$(PARSE_DIR)%.c
$(OBJS_DIR)%.o: $(SRC_DIR)$(PARSE_DIR)%.c $(DEPS_DIR)%.d
	$(CC) -MT $@ -MMD -MP -MF $(DEPS_DIR)$*.Td $(FLAGS) $(INC_LIB) -o $@ -c $<
	@mv -f $(DEPS_DIR)$*.Td $(DEPS_DIR)$*.d && touch $@

$(OBJS_DIR)%.o: $(SRC_DIR)$(LEXER_DIR)%.c
$(OBJS_DIR)%.o: $(SRC_DIR)$(LEXER_DIR)%.c $(DEPS_DIR)%.d
	$(CC) -MT $@ -MMD -MP -MF $(DEPS_DIR)$*.Td $(FLAGS) $(INC_LIB) -o $@ -c $<
	@mv -f $(DEPS_DIR)$*.Td $(DEPS_DIR)$*.d && touch $@

$(OBJS_DIR)%.o: $(SRC_DIR)$(EXEC_DIR)%.c
$(OBJS_DIR)%.o: $(SRC_DIR)$(EXEC_DIR)%.c $(DEPS_DIR)%.d
	$(CC) -MT $@ -MMD -MP -MF $(DEPS_DIR)$*.Td $(FLAGS) $(INC_LIB) -o $@ -c $<
	@mv -f $(DEPS_DIR)$*.Td $(DEPS_DIR)$*.d && touch $@

$(OBJS_DIR)%.o: $(SRC_DIR)$(PROMPT_DIR)%.c
$(OBJS_DIR)%.o: $(SRC_DIR)$(PROMPT_DIR)%.c $(DEPS_DIR)%.d
	$(CC) -MT $@ -MMD -MP -MF $(DEPS_DIR)$*.Td $(FLAGS) $(INC_LIB) -o $@ -c $<
	@mv -f $(DEPS_DIR)$*.Td $(DEPS_DIR)$*.d && touch $@

$(OBJS_DIR)%.o: $(SRC_DIR)$(UTILS_DIR)%.c
$(OBJS_DIR)%.o: $(SRC_DIR)$(UTILS_DIR)%.c $(DEPS_DIR)%.d
	$(CC) -MT $@ -MMD -MP -MF $(DEPS_DIR)$*.Td $(FLAGS) $(INC_LIB) -o $@ -c $<
	@mv -f $(DEPS_DIR)$*.Td $(DEPS_DIR)$*.d && touch $@

$(OBJS_DIR)%.o: $(SRC_DIR)$(TERM_DIR)%.c
$(OBJS_DIR)%.o: $(SRC_DIR)$(TERM_DIR)%.c $(DEPS_DIR)%.d
	$(CC) -MT $@ -MMD -MP -MF $(DEPS_DIR)$*.Td $(FLAGS) $(INC_LIB) -o $@ -c $<
	@mv -f $(DEPS_DIR)$*.Td $(DEPS_DIR)$*.d && touch $@

$(OBJS_DIR)%.o: $(SRC_DIR)$(SIGNAL_DIR)%.c
$(OBJS_DIR)%.o: $(SRC_DIR)$(SIGNAL_DIR)%.c $(DEPS_DIR)%.d
	$(CC) -MT $@ -MMD -MP -MF $(DEPS_DIR)$*.Td $(FLAGS) $(INC_LIB) -o $@ -c $<
	@mv -f $(DEPS_DIR)$*.Td $(DEPS_DIR)$*.d && touch $@

$(OBJS_DIR)%.o: $(SRC_DIR)$(EXPAND_DIR)%.c
$(OBJS_DIR)%.o: $(SRC_DIR)$(EXPAND_DIR)%.c $(DEPS_DIR)%.d
	$(CC) -MT $@ -MMD -MP -MF $(DEPS_DIR)$*.Td $(FLAGS) $(INC_LIB) -o $@ -c $<
	@mv -f $(DEPS_DIR)$*.Td $(DEPS_DIR)$*.d && touch $@

$(OBJS_DIR)%.o:	$(SRC_DIR)$(FREE_DIR)%.c
$(OBJS_DIR)%.o: $(SRC_DIR)$(FREE_DIR)%.c $(DEPS_DIR)%.d
	$(CC) -MT $@ -MMD -MP -MF $(DEPS_DIR)$*.Td $(FLAGS) $(INC_LIB) -o $@ -c $<
	@mv -f $(DEPS_DIR)$*.Td $(DEPS_DIR)$*.d && touch $@

$(DEPS_DIR)%.d: ;
.PRECIOUS: $@

-include $(DEPS)

clean:
	make clean -C libft/
	$(RM) -r $(OBJS_DIR)

fclean:
	make fclean -C libft/
	$(RM) -rf $(OBJS_DIR)
	$(RM) -rf $(APP)

re: fclean all

buildrepo:
	$(call make-repo)

define make-repo
for dir in $(SRCDIRS); \
	do \
	mkdir -p $(OBJDIR)/$$dir; \
	mkdir -p $(DEPS_DIR)/$$dir;	\
	done
endef
