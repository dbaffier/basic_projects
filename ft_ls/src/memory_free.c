/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 23:09:03 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 20:52:48 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				free_files_bis(t_files **files)
{
	free((*files)->name);
	free((*files)->owner);
	free((*files)->group);
	free((*files)->modes);
	free((*files)->linked_to);
	if ((*files)->has_nonprintable_chars)
		free((*files)->display_name);
	ft_memdel((void *)files);
}

static void			free_files(t_files *files)
{
	t_files *next;

	while (files)
	{
		next = (files)->next;
		free(files->name);
		free((files)->owner);
		free((files)->group);
		free((files)->modes);
		if ((files)->has_nonprintable_chars)
			free((files)->display_name);
		ft_memdel((void **)&files);
		files = next;
	}
}

void				free_dirs_bis(t_dirs *dirs)
{
	if (dirs)
	{
		free(dirs->path);
		free(dirs->display_name);
		free(dirs->self->display_name);
		free_files(dirs->files);
		free_files(dirs->self);
		ft_memdel((void **)&dirs->sub_dirs);
		ft_memdel((void **)&dirs);
	}
}

static void			free_dirs(t_dirs *dirs, t_fg *g_fg)
{
	t_dirs *next;

	while (dirs)
	{
		next = dirs->next;
		free((dirs)->path);
		if (dirs->display_name)
			free((dirs)->display_name);
		free((dirs)->self->display_name);
		if (dirs->files)
			free_files(dirs->files);
		if (!(*g_fg & RECURSIVE_FLAG))
			ft_memdel((void **)&dirs->sub_dirs);
		if (dirs->self)
			free_files(dirs->self);
		ft_memdel((void **)&dirs);
		dirs = next;
	}
}

void				memory_handler(void *mem_target, int target, t_fg *g_fg)
{
	if (target == DIRS_MEM)
		free_dirs((t_dirs *)mem_target, g_fg);
	else if (target == ERROR_MEM)
		free(mem_target);
}
