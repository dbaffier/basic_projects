/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nondir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 17:38:28 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 20:58:55 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void			print_c(char c, int start, int end)
{
	while (start++ < end)
		write(1, &c, 1);
}

static inline void			gr_f(char *str, int len, int format, char *after)
{
	print_c(' ', len, format);
	write(1, str, len);
	write(1, after, ft_strlen(after));
}

static inline void			l_f(t_format format,
		t_files *file, int has_chr_or_blk)
{
	if (file->is_chr_or_blk)
	{
		print_c(' ', ft_intlen(major((long)file->f.st_rdev)), format.major);
		ft_printf(" %lu, ", major((long)file->f.st_rdev));
		print_c(' ', ft_intlen(minor((long)file->f.st_rdev)), format.minor);
		ft_printf("%lu ", minor((long)file->f.st_rdev));
	}
	else
	{
		print_c(' ', ft_intlen(file->f.st_size), has_chr_or_blk
				? format.major + format.minor + format.file_size + 2
				: format.file_size);
		ft_printf("%d ", file->f.st_size);
	}
	ls_lm_time(file, file->g_fg);
	(file->has_nonprintable_chars) ? ft_putstr(file->display_name)
		: ft_putstr(file->name);
	if (file->is_link)
		ft_printf(" -> %s", file->linked_to);
	write(1, "\n", 1);
}

void						long_listing_display(t_format format,
		t_files *file, int has_chr_or_blk, t_fg *g_fg)
{
	ft_putsl(file->modes, ' ');
	print_c(' ', ft_intlen(file->f.st_nlink), format.link);
	ft_putnbr(file->f.st_nlink);
	write(1, " ", 1);
	if (!(*g_fg & SUPRESS_OWNER))
	{
		if (file->owner)
			gr_f(file->owner, ft_strlen(file->owner), format.owner, "  ");
		else
		{
			ft_printf("%d", file->f.st_uid);
			print_c(' ', ft_intlen(file->f.st_uid), format.user_id);
		}
	}
	if (file->group && !(*g_fg & DISPLAY_UID_AND_GID))
		gr_f(file->group, ft_strlen(file->group), format.group, "  ");
	else
	{
		ft_printf("%d", (int)file->f.st_gid);
		print_c(' ', ft_intlen(file->f.st_gid), format.group_id);
	}
	l_f(format, file, has_chr_or_blk);
}
