/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:08:16 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/22 15:32:11 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include <unistd.h>
# include "ft_printf.h"
# include "utils.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <signal.h>
# include <fcntl.h>
# include <limits.h>
# include <prompt.h>

# define WHITESPACE(x) x == '\t' || x == '\n' || x == ' '
# define LEFT (b[0] == 27 && b[1] == 91 && b[2] == 68)
# define RIGHT (b[0] == 27 && b[1] == 91 && b[2] == 67)
# define UP (b[0] == 27 && b[1] == 91 && b[2] == 65)
# define DOWN (b[0] == 27 && b[1] == 91 && b[2] == 66)
# define DELRIGHT (b[0] == 27 && b[1] == 91 && b[2] == 51 && b[3] == 126)
# define DELLEFT (b[0] == 127)
# define HOME (b[0] == 27 && b[1] == 91 && b[2] == 72)
# define END (b[0] == 27 && b[1] == 91 && b[2] == 70)
# define ALTUP (b[0] == 27 && b[1] == 27 && b[2] == 91 && b[3] == 65)
# define ALTDOWN (b[0] == 27 && b[1] == 27 && b[2] == 91 && b[3] == 66)
# define ALTLEFT (b[0] == 27 && b[1] == 27 && b[2] == 91 && b[3] == 68)
# define ALTRIGHT (b[0] == 27 && b[1] == 27 && b[2] == 91 && b[3] == 67)
# define TAB (b[0] == '\t')
# define EXIT (b[0] == 4)
# define SHIFT (b[0] == 27 && b[1] == 91 && b[2] == 49)
# define KEYS1 (LEFT || RIGHT || ALTDOWN || ALTUP)
# define KEYS2 (ALTLEFT || ALTRIGHT || HOME || END)
# define TKEYS_1 (KEYS1 || KEYS2)

struct				s_hlist
{
	char			*line;
	struct s_hlist	*prev;
	struct s_hlist	*next;
};

struct s_hlist		*head;

/*
**    ENV STUFF
*/

char				**get_environ(char **envp, char **dst, int size);
char				*get_env2(char *name, char **envp);
int					count_env(char **envp);

/*
**    READ STUFF
*/

char				*get_line(int cursor, int plen, int len);
char				*get_line_hq(int cursor, int plen, int len);
void				sig_handler(int sig);
void				print_buff(char *b, int *cursor, char **line);
void				insert_buff(char *b, int *cursor, char **line,
					int prom_len);

/*
**		HISTORY STUFF
*/

int					save_history(char *line, char *home);
char				*access_history(int index);
void				new_node(char *new_line);
void				create_hlist(char *home, int i);
char				*browse_up(struct s_hlist ***temp);
char				*browse_down(struct s_hlist ***temp);

/*
**  	TERMCAPS TOOLS
*/

int					putch(int c);
void				remove_chars(char ***line, int i);
void				remove_lines_after(int curline, int clines);
char				*add_chars(char *line, char ch, int i);
void				pos_cursor(int curline, int clines);
void				add_line(int curline, int clines);
int					find_prev_word(char *line, int index);
int					find_next_word(char *line, int index);
int					c_lines(int len, int co, int prom_len);
int					cur_line(int cursor, int co);
void				pos_cursor_for_prompt(int curline, int clines);

/*
**		STARTING POINT
*/

int					init_term(struct termios *save, char **envp);

/*
**		TERMCAPS KEYS
*/

void				t_keys(char *b, int *cursor, int prom_len, char *line);
void				t_keys_2(char *b, int *cursor, int prom_len, char **line);
void				tleft(int *cursor, int prom_len);
void				tright(int *cursor, int len, int prom_len);
void				alt_down(int *cursor, int len, int prom_len);
void				alt_up(int *cursor, int len, int prom_len);
void				alt_left(int *cursor, char *line, int prom_len);
void				alt_right(int *cursor, char *line, int prom_len);
void				thome(int *cursor, int prom_len);
void				tend(int *cursor, int clines, int len);

char				*tup(struct s_hlist **temp, int prom_len, char *line);
char				*tdown(struct s_hlist **temp, int prom_len, char *line);
void				clean_last_command(int cc_lines);

void				del_left(int *cursor, char **line, int prom_len);
void				del_right(int cursor, char **line, int prom_len);

/*
**		QUOTE STUFF
*/

char				is_quote(char *line, int i, int count);
char				get_qquote(char *line, int i, int s);
int					check_quote(char **line);

/*
**		HEREDOC STUFF
*/

char				**is_heredoc(char **line);
char				**here_doc(char **h_tab, int d);
char				**get_here_tab(char *here_tab_z, char *delim[4096],
					int d, int i);
int					check_ret_conditions(char s, char **here_tab,
					char *delim[4096]);
char				**alloc_here_tab(char *here_tab_z);
int					count_hdoc_ws(char *line);
void				get_split_line(char *tmp, char **line);
int					put_ws_before(char *line, char **tmp, int i, int *j);
void				copy_ex_ws(char *line, char **tmp, int *i, int *j);
char				*split_hdoc(char *line, int count, int i, int j);

/*
**		SPLIT WHITESPACE
*/

int					ft_wordlen_ws(char *str);
int					ft_countwords_ws(char *str);
char				**ft_split_whitespaces(char *str, int i);

void				print_hlist(void);

#endif
