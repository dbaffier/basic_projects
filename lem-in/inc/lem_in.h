/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 18:12:03 by dbaffier          #+#    #+#             */
/*   Updated: 2019/07/20 00:59:33 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <fcntl.h>
# include <unistd.h>
# include "ft_printf.h"
# include <stdio.h>

# define STR_MAX		"2147483647"
# define END			{"##end", RULES_END}
# define START			{"##start", RULES_START}

# define STARTING_ROOM	(1 << 0)

# define RULES_END		1
# define RULES_START	2


typedef struct s_link	t_link;

typedef struct			s_road
{
	int					*rd;
	int					size;
	int					dup;
	struct s_road		*next;
}						t_road;

typedef	struct			s_ant
{
	t_road				*road;
	int					delay;
	int					name;
	int					i;
	struct s_ant		*next;
}						t_ant;

typedef struct			s_room
{
	int					x;
	int					y;
	int					idx;
	int					rules;
	int					set;
	int					link_n;
	char				*name;
	t_link				*link;
	int					*seg;
	struct s_room		*next;
}						t_room;

typedef struct			s_path
{
	int					ant_n;
	int					p_room;
	int					p;
	int					test;
	int					path_n;
	int					curr_path_n;
	int					size;
	int					index;
	int					n_wanted;
	int					tail;
	int					buff_tail;
	int					*buff;
	int					wtd;
	int					min_road;
	int					last_road;
	int					cum;
	int					tmp_last;
	int					**mat;
	int					**mat_save;
	t_road				*road;
	t_road				*road_save;
	t_ant				*ant;
	t_room				*lst_room;
	t_room				*start;
	t_room				*end;
}						t_path;

struct					s_link
{
	int					idx;
	t_room				*lkd_room;
	struct s_link		*next;
};


typedef struct			s_rule
{
	char				*rule;
	int					mask;
}						t_rule;

void					print_free(t_path *path, char *line);
void					add_room(t_path *pf, t_room *new, int mask);
void					mat(t_path *pf, t_room *room);
int						handle_dup(t_path *pf);
void					move_ant(t_path *pf, t_road *road);
void					print_ant(t_path *pf, t_ant *ant);
void					creat_road(t_path *pf, int *search);
char					*fill_name(char *line, char c);
int						exit_error_main(void);
int						get_input(t_path *pf);
int						parse_rule(t_path *pf, char *line);
int						parse_room(t_path *pf, char *line, char *name, int mask);
int						parse_link(t_path *pf, char *line);
int						check_ant(t_path *pf);
int						init_parsing(t_path *pf, char *line);
int						is_treatable(t_path *pf, t_room *room, t_link *link);
int						grep_path(t_path *pf, int **mat, int var);
int						evaluate_path(t_path *pf);
int						direct_path(t_path *pf);

# endif
