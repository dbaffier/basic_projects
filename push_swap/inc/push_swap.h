/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 05:25:47 by mmonier           #+#    #+#             */
/*   Updated: 2019/06/28 11:30:41 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STR_MAX "2147483647"
# define STR_MIN "-2147483648"
# define PS "./push_swap"
# define CK "./checker"

# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define OPT_V			(1 << 0)
# define OPT_C			(1 << 1)
# define OPT_R			(1 << 2)
# define OPT_F			(1 << 3)
# define OPT_Q			(1 << 4)
# define OPT_S			(1 << 5)
# define OPT_N			(1 << 6)
# define OPT_PS			(1 << 7)

# define FLG_V			{'v', OPT_V}
# define FLG_C			{'c', OPT_C}
# define FLG_R			{'r', OPT_R}
# define FLG_F			{'f', OPT_F}
# define FLG_Q			{'q', OPT_Q}
# define FLG_S			{'s', OPT_S}
# define FLG_N			{'n', OPT_N}

# define SA				{"sa", &sa}
# define SB				{"sb", &sb}
# define SS				{"ss", &ss}
# define PA				{"pa", &pa}
# define PB				{"pb", &pb}
# define RA				{"ra", &ra}
# define RB				{"rb", &rb}
# define RR				{"rr", &rr}
# define RRA			{"rra", &rra}
# define RRB			{"rrb", &rrb}
# define RRR			{"rrr", &rrr}

# define N_RRA			(1 << 0)
# define N_RRB			(1 << 1)
# define N_RA			(1 << 2)
# define N_RB			(1 << 3)
# define N_RRR			(1 << 4)
# define N_RR			(1 << 5)

typedef struct s_print	t_print;

typedef struct			s_pile
{
	int					n;
	int					id;
	int					range;
	struct s_pile		*next;
	struct s_pile		*prev;
}						t_pile;

typedef struct			s_flags
{
	int					flag;
	size_t				msk;
}						t_flags;

typedef struct			s_stack
{
	int					pos_a;
	int					pos_b;
	int					dupp;
	int					path;
	int					possibility;
	int					start_reading;
	int					opts;
	int					median;
	int					len_a;
	int					len_b;
	t_print				*print;
	t_pile				*a;
	t_pile				*b;
}						t_stack;

typedef struct			s_apply
{
	char				*instruction;
	void				(*func)(t_stack *stack, t_pile *a, t_pile *b);
}						t_apply;

struct					s_print
{
	int					pa;
	int					pb;
	int					sa;
	int					sb;
	int					ss;
	int					ra;
	int					rb;
	int					rr;
	int					rra;
	int					rrb;
	int					rrr;
};

/*
** ------------------ [GLOBAL_FLAG] --------------------
*/

int						check_global_flags(t_stack *stack, char **av, int ac);
void					usage_flag_f(t_stack *stak, char *str);

/*
** ------------------ [PRINT_ERROR] --------------------
*/

void					free_pile(t_pile *head, int len);
void					print_error(t_stack *stack);
void					print_flag_err(t_stack *stack, char c);
void					print_usage(char *str);
void					print_free_line(t_stack *stack, char *line);

/*
** ------------------ [CHECK_INPUT] --------------------
*/

int						check_input(t_stack *stack, char **av, int ac);

/*
** ------------------ [READ_FILE] --------------------
*/

int						read_file(t_stack *stack, char **av, int ac);

/*
** ------------------ [CHECK_DIGITS_FD] --------------------
*/

void					check_line(t_stack *stack, char *line);

/*
** ------------------ [ATOIN] ----------------------
*/

void					stock_in(t_stack *stack, char *str);

/*
** ------------------ [LNK_LST] ----------------------
*/

void					lst_insert(t_pile **a, int n);

/*
** ------------------ [DUPLICATE_ENTRY] ----------------------
*/

int						duplicate_entry(t_pile *head, t_stack *stack);
int						check_instructions(t_stack *stack, char *line);

/*
** ------------------ [PARSE_OPTS] ---------------------------
*/

void					flag_get(t_stack *stack, char *s);

/*
** ------------------ [HANDLE_INSTRUCTIONS] ----------------------
*/

void					handle_instructions(t_stack *stack);

/*
** ------------------ [INSTRUCTIONS - S] ----------------------
*/
void					sa(t_stack *stack, t_pile *a, t_pile *b);
void					sb(t_stack *stack, t_pile *a, t_pile *b);
void					ss(t_stack *stack, t_pile *a, t_pile *b);

/*
** ------------------ [INSTRUCTIONS - P] ----------------------
*/

void					pa(t_stack *stack, t_pile *a, t_pile *b);
void					pb(t_stack *stack, t_pile *a, t_pile *b);

/*
** ------------------ [INSTRUCTIONS - R] ----------------------
*/

void					ra(t_stack *stack, t_pile *a, t_pile *b);
void					rb(t_stack *stack, t_pile *a, t_pile *b);
void					rr(t_stack *stack, t_pile *a, t_pile *b);

/*
** ------------------ [INSTRUCTIONS - RR] ----------------------
*/

void					rra(t_stack *stack, t_pile *a, t_pile *b);
void					rrb(t_stack *stack, t_pile *a, t_pile *b);
void					rrr(t_stack *stack, t_pile *a, t_pile *b);

/*
** ------------------ [LST_SORT] ---------------------------
*/

void					lst_sort_three(t_stack *stack, t_pile *a);
void					lst_sort_five(t_stack *stack);
void					lst_sort_reverse(t_stack *stack);
void					set_min_nmin(t_stack *stack, t_pile *a, int tab[2]);
void					pre_sort_five(t_stack *stack, t_pile *a,
								t_pile *b, int tab[2]);

/*
** ------------------ [LST SORTED] ---------------------------
*/

int						lst_sorted(t_stack *stack);
int						lst_sorted_give(t_stack *stack, t_pile *give, int len);
int						lst_sorted_reverse(t_stack *stack);

/*
** ------------------ [PRINT_STACK] ---------------------------
*/

void					print_stack(t_stack *stack, char *instruc);
void					print_instruction_counter(t_stack *stack,
								useconds_t speed);
void					speed_mode(t_stack *stack);
void					executing_color(t_stack *stack, char *instruc);
void					count_instruction(t_stack *stack, char *str);

/*
** ------------------ [PRINT_STACK] ---------------------------
*/

int						identify_instruc(char *instruc, int mod);
void					get_action(char *instruc);
void					show_action(t_stack *stack, char *instruc);

/*
** ------------------ [EXEC_INSTRUCTION] ---------------------------
*/

void					exec_instruction(t_stack *stack, char *str);
void					exec_multiple(t_stack *stack, char *s1, char *s2);

/*
** ------------------ [HELP] ---------------------------
*/

int						help(char *str);

/*
** ------------------ [LST_SORT] ---------------------------
*/
void					lst_sort(t_stack *stack);

/*
** ------------------ [LST_SORT_BIS] ---------------------------
*/
void					lst_sort_test(t_stack *stack, t_pile *a, t_pile *b);
void					try_sort(t_stack *stack, t_pile *a, t_pile *b);

/*
** ------------------ [MOVES] ---------------------------
*/
int						find_b_moves(t_stack *stack, int len, t_pile *element);
int						find_a_places(t_stack *stack, int len, t_pile *element);
int						eval_moves(t_stack *stack, int len, int index, int key);
int						eval_dupplicate(t_stack *stack, int *tab);

/*
** ------------------ [MIN_MAX] ---------------------------
*/
int						current_b_index(t_pile *b, int len);
int						current_b_min_index(t_pile *b, int len);
int						current_b_min(t_pile *b, int len);
int						current_b_max(t_pile *b, int len);

/*
** ------------------ [MIN_MAX] ---------------------------
*/
int						evaluate(t_stack *stack, t_pile *a);
void					apply_path(t_stack *stack);

#endif
