/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 15:21:26 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 22:49:48 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				has_dirs(t_dirs *dirs)
{
	t_dirs	*tmp;

	tmp = dirs;
	while (tmp)
	{
		if (tmp->status == IS_DIR)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_dirs			*subdir_handler(t_dirs *next, t_dirs **sub_dirs, t_fg *g_fg)
{
	t_dirs		*tmp;

	if (!*sub_dirs)
		return (next);
	*sub_dirs = dirs_sort(*sub_dirs, g_fg);
	if (*g_fg & REVERSE_FLAG)
		reverse_dirs(sub_dirs);
	tmp = *sub_dirs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = next;
	return (*sub_dirs);
}

char			*ft_cpath(char *path)
{
	char		*str;
	char		*tmp;

	str = ft_strrchr(path, '/');
	if (!str)
		return (ft_strdup(path));
	if (!(tmp = ft_strdup(str)))
		exit(2);
	return (tmp);
}

int				is_last_nondir(t_dirs *dirs)
{
	t_dirs		*tmp;

	tmp = dirs->next;
	while (tmp)
	{
		if (tmp->status == IS_NOTDIR)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_format		get_nondir_format(t_dirs **dirs, t_fg *g_fg)
{
	t_format	format;
	t_dirs		*tmp;
	int			format_opt;

	tmp = *dirs;
	format_opt = INIT_FORMAT;
	while (tmp)
	{
		if (tmp->status == IS_NOTDIR)
		{
			add_file(&tmp->self, &tmp, INIT_FORMAT, g_fg);
			if (*g_fg & LONG_LISTING_FLAG)
				format_handler(&format, tmp->self, format_opt);
			format_opt = UPDATE_FORMAT;
		}
		tmp = tmp->next;
	}
	return (format);
}
