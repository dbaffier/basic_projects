/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 00:13:41 by mmonier           #+#    #+#             */
/*   Updated: 2019/08/13 01:37:18 by mmonier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_link	*link;
	struct s_room	*next;
}					t_room;

typedef struct		s_link
{
	t_room			*lkd_room;
	struct s_link	*next;
}					t_link;

typedef struct		s_move
{
	t_room			*moves;
}					t_move;

typedef struct		s_ant
{
	char			*ant_name;
	t_move			*move;
}					t_ant;

typedef struct		s_id
{
	int				ant_n;
	int				room_n;
	t_room			*room;
	t_link			*link;
	t_ant			*ant;
	t_move			*move;
}					t_id;

int					parse_input(t_id *id);
int					parse_link(t_id *id, char *line);
size_t				ft_strclen(char c, char *line);
char				*ft_strcdup(char *line, char c);
void				print_square(int x, int y);
void				print_lemin(void);
void				print_loading(void);
# endif
