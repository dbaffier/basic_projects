/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 15:39:44 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 22:59:38 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void			dir_single_print(t_dirs *dirs, t_fg *g_fg)
{
	if (*g_fg & LONG_LISTING_FLAG)
		long_listing_display(dirs->format, dirs->files,
				dirs->has_chr_or_blk, g_fg);
	else
	{
		if (dirs->files->has_nonprintable_chars)
			ft_putstr(dirs->files->display_name);
		else
			ft_putstr(dirs->files->name);
		write(1, "\n", 1);
	}
}

static inline void			nondir_display_2(t_dirs *tmp,
		int should_separate, t_fg *g_fg)
{
	if (*g_fg & LONG_LISTING_FLAG)
		long_listing_display(tmp->format, tmp->self, tmp->has_chr_or_blk, g_fg);
	else
	{
		if (tmp->self->has_nonprintable_chars)
			ft_putstr(tmp->self->display_name);
		else
			ft_putstr(tmp->self->name);
		write(1, "\n", 1);
	}
	if (is_last_nondir(tmp) && should_separate)
		write(1, "\n", 1);
}

void						nondir_display(t_dirs *dirs,
		int should_separate, t_fg *g_fg)
{
	t_dirs		*tmp;
	t_format	non_dirformat;

	tmp = dirs;
	non_dirformat = get_nondir_format(&dirs, g_fg);
	while (tmp)
	{
		if (tmp->status == IS_NOTDIR)
			nondir_display_2(tmp, should_separate, g_fg);
		tmp = tmp->next;
	}
}

void						dir_access_err(t_dirs *dirs)
{
	char		*str;

	if (dirs->files->has_nonprintable_chars)
	{
		if (!(str = ft_strdup(dirs->files->display_name)))
			exit(2);
	}
	else
	{
		if (!(str = ft_strdup(dirs->files->name)))
			exit(2);
	}
	err_h(FILE_ACCESS_ERR, str);
	free(str);
}

void						dir_p(t_dirs *dirs, t_fg *g_fg)
{
	char		*str;

	if (dirs->files->status == IS_NONEXISTENT)
	{
		if (dirs->files->has_nonprintable_chars)
		{
			if (!(str = ft_strdup(dirs->files->display_name)))
				exit(2);
		}
		else
		{
			if (!(str = ft_strdup(dirs->files->name)))
				exit(2);
			err_h(NONEXISTENT_ERR, str);
			free(str);
		}
	}
	else if (dirs->files->status == IS_UNREADABLE)
		dir_access_err(dirs);
	else
		dir_single_print(dirs, g_fg);
}
