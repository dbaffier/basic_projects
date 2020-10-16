/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 12:46:21 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 20:17:55 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void		unset(int clear, t_fg *g_fg)
{
	if (*g_fg & clear)
		*g_fg &= ~clear;
}

static inline void		display_f_handler(char c, t_fg *g_fg)
{
	if (c == '1')
	{
		unset(COLUMN_DISPLAY, g_fg);
		unset(LONG_LISTING_FLAG, g_fg);
		*g_fg |= ONE_ENTRY_PER_LINE;
	}
	else if (c == 'l' || c == 'g')
	{
		if (c == 'g')
			*g_fg |= SUPRESS_OWNER;
		unset(COLUMN_DISPLAY, g_fg);
		unset(ONE_ENTRY_PER_LINE, g_fg);
		*g_fg |= LONG_LISTING_FLAG;
	}
	else
	{
		unset(ONE_ENTRY_PER_LINE, g_fg);
		unset(LONG_LISTING_FLAG, g_fg);
		*g_fg |= COLUMN_DISPLAY;
	}
}

static inline void		sort_f_handler(char c, t_fg *g_fg)
{
	if (c == 't')
		*g_fg |= MODIFICATION_DATE_SORT;
	else if (c == 'U')
	{
		unset(LAST_ACCESS_DATE_SORT, g_fg);
		unset(LAST_STATUS_CHANGE_SORT, g_fg);
		*g_fg |= CREATION_DATE_SORT;
	}
	else if (c == 'u')
	{
		unset(CREATION_DATE_SORT, g_fg);
		unset(LAST_STATUS_CHANGE_SORT, g_fg);
		*g_fg |= LAST_ACCESS_DATE_SORT;
	}
	else if (c == 'c')
	{
		unset(CREATION_DATE_SORT, g_fg);
		unset(LAST_ACCESS_DATE_SORT, g_fg);
		*g_fg |= LAST_STATUS_CHANGE_SORT;
	}
}

static void				set_flag(char *av, t_fg *g_fg)
{
	int				i;

	if (ft_strstart(av, "--") && av[2])
		return (error_handling(av + 1));
	i = 0;
	while (av[++i])
	{
		if (av[i] == 'R')
			*g_fg |= RECURSIVE_FLAG;
		else if (av[i] == 'a')
			*g_fg |= ALL_FLAG;
		else if (av[i] == 'r')
			*g_fg |= REVERSE_FLAG;
		else if (av[i] == 'n')
			*g_fg |= DISPLAY_UID_AND_GID;
		else if (av[i] == 'A')
			*g_fg |= HIDE_CURR_AND_PREV_DIRS;
		else if (av[i] == 'U' || av[i] == 't'
				|| av[i] == 'u' || av[i] == 'c')
			sort_f_handler(av[i], g_fg);
		else if (av[i] == '1' || av[i] == 'l' || av[i] == 'C' || av[i] == 'g')
			display_f_handler(av[i], g_fg);
		else
			error_handling(av + i);
	}
}

int						flag_handler(char **argv, t_fg *g_fg)
{
	int		i;

	i = -1;
	*g_fg |= COLUMN_DISPLAY;
	while (argv[++i])
	{
		if (argv[i][0] != '-')
			break ;
		if (ft_strequ(argv[i], "--"))
		{
			i++;
			break ;
		}
		if (argv[i][0] == '-' && argv[i][1])
			set_flag(argv[i], g_fg);
		else
			break ;
	}
	return (i > 0 ? i + 1 : 1);
}
