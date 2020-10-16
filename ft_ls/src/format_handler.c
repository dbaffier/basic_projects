/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 22:28:02 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 20:49:10 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void		initialize_format(t_format *format)
{
	format->link = 0;
	format->owner = 0;
	format->group = 0;
	format->file_size = 0;
	format->user_id = 0;
	format->group_id = 0;
	format->major = 0;
	format->minor = 0;
}

void					format_handler(t_format *format,
		t_files *file, int format_opt)
{
	if (format_opt == IDLE_FORMAT)
		return ;
	if (format_opt == INIT_FORMAT)
		initialize_format(format);
	if (format->link < ft_intlen(file->f.st_nlink))
		format->link = ft_intlen(file->f.st_nlink);
	if (file->owner && format->owner < (int)ft_strlen(file->owner))
		format->owner = (int)ft_strlen(file->owner);
	if (format->group < (int)ft_strlen(file->group))
		format->group = (int)ft_strlen(file->group);
	if (format->file_size < ft_intlen(file->f.st_size))
		format->file_size = ft_intlen(file->f.st_size);
	if (format->user_id < ft_intlen((int)file->f.st_uid))
		format->user_id = ft_intlen((int)file->f.st_uid);
	if (format->group_id < ft_intlen((int)file->f.st_gid))
		format->group_id = ft_intlen((int)file->f.st_gid);
	if (format->major < ft_intlen((long)major(file->f.st_rdev)))
		format->major = ft_intlen((long)major(file->f.st_rdev));
	if (format->minor < ft_intlen((long)minor(file->f.st_rdev)))
		format->minor = ft_intlen((long)minor(file->f.st_rdev));
}

char					*cut_n(char *name, int len)
{
	char		*new;
	int			i;
	char		c;

	if (!(new = ft_strnew(ft_strlen(name))))
		exit(2);
	i = -1;
	while (i < len && name[i])
	{
		c = name[i];
		if (is_nonprintable(name[i]))
		{
			if (name[i] == '\r')
				c = '?';
			else
				c = ' ';
		}
		new[i] = c;
	}
	return (new);
}
