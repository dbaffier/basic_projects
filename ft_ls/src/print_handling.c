/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:26:57 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 22:59:48 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int				is_last_dir(t_dirs *dirs)
{
	t_dirs		*tmp;

	tmp = dirs->next;
	while (tmp)
	{
		if (tmp->status == IS_DIR)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int				dir_unreadable(t_dirs *head, t_dirs *dirs, t_fg *g_fg)
{
	char	*str;

	if (head->next)
	{
		ft_putstr(dirs->path);
		write(1, ":\n", 2);
	}
	if (dirs->is_unreadable)
	{
		if (!(str = ft_strdup(dirs->display_name)))
			exit(2);
		err_h(FILE_ACCESS_ERR, str);
		free(str);
		return (1);
	}
	if ((*g_fg & LONG_LISTING_FLAG) && dirs->files && dirs->has_valid_files)
	{
		str = ft_itoa(dirs->total_blocks);
		write(1, "total ", 6);
		ft_putendl(str);
		free(str);
	}
	return (0);
}

void					dir_display(t_dirs *head, t_dirs *dirs, t_fg *g_fg)
{
	t_files		*next;

	if (dir_unreadable(head, dirs, g_fg))
		return ;
	while (dirs->files)
	{
		next = dirs->files->next;
		dir_p(dirs, g_fg);
		free_files_bis(&(dirs->files));
		dirs->files = next;
	}
}

void					display_handler(t_dirs *head, t_dirs *dir,
		int target, t_fg *g_fg)
{
	t_dirs		*tmp;
	char		*name;

	if (target == IS_NONEXISTENT)
	{
		tmp = dir;
		while (tmp)
		{
			if (tmp->status == IS_NONEXISTENT)
			{
				if (!(name = ft_strdup(tmp->path)))
					exit(2);
				err_h(NONEXISTENT_ERR, name);
				free(name);
			}
			tmp = tmp->next;
		}
	}
	else if (target == IS_NOTDIR)
		nondir_display(dir, has_dirs(dir), g_fg);
	else
		dir_display(head, dir, g_fg);
}

void					print_handling(t_dirs *dirs, t_fg *g_fg)
{
	t_dirs		*tmp;

	display_handler(NULL, dirs, IS_NONEXISTENT, g_fg);
	if (*g_fg & REVERSE_FLAG)
		reverse_dirs(&dirs);
	display_handler(NULL, dirs, IS_NOTDIR, g_fg);
	tmp = dirs;
	while (tmp)
	{
		if (tmp->status == IS_DIR)
		{
			tmp->files = file_handler(tmp, g_fg);
			if (*g_fg & REVERSE_FLAG)
				reverse_files(&tmp->files);
			display_handler(dirs, tmp, IS_DIR, g_fg);
			tmp->next = subdir_handler(tmp->next, &(tmp->sub_dirs), g_fg);
			if (!is_last_dir(tmp))
				write(1, "\n", 1);
		}
		tmp = tmp->next;
	}
}
