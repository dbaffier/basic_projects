/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:24:52 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/15 20:32:17 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			add_files(t_dirs *head, t_files *new)
{
	t_dirs		*current;
	t_files		*curr;

	current = head;
	curr = current->files;
	if (curr)
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new;
		new->prev = curr;
	}
	else
	{
		new->prev = NULL;
		current->files = new;
	}
}

static t_files		*new_file(struct stat *f_data, char *path)
{
	t_files		*file;

	if (!(file = (t_files *)malloc(sizeof(t_files))))
		return (NULL);
	file->name = ft_strdup(path);
	file->next = NULL;
	(void)f_data;
	return (file);
}

void				read_dir(t_dirs *dir)
{
	DIR				*dr;
	struct dirent	*d_data;
	struct stat		*f_data;

	f_data = NULL;
	if (!(dr = opendir(dir->path)))
		return ;
	while ((d_data = readdir(dr)) != NULL)
	{
		if (!(stat(dir->path, f_data)))
			return ;
		add_files(dir, new_file(f_data, d_data->d_name));
	}
	closedir(dr);
}

void				get_link_file(t_files **curr_file, char *file_path)
{
	static char		buff[256];
	int				link_len;

	(*curr_file)->is_link = 1;
	if ((link_len = readlink(file_path, buff, 256)) == -1)
		exit(2);
	if (has_nonprintable_chars(buff, link_len))
	{
		if (!((*curr_file)->linked_to = cut_n(buff, link_len)))
			exit(2);
	}
	else
	{
		if (!((*curr_file)->linked_to = ft_strndup(buff, link_len)))
			exit(2);
	}
}
