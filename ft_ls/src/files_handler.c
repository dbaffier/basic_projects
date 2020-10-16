/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 20:41:29 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/18 22:51:25 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		add_file_p(t_dirs **dirs, t_files **curr_file,
		char *dir_name, t_fg *g_fg)
{
	char	*str;

	if ((*g_fg & LONG_LISTING_FLAG) && !(*curr_file)->is_dir_info)
	{
		if ((*dirs)->status == IS_DIR)
			(*dirs)->total_blocks += (*curr_file)->f.st_blocks;
	}
	if (S_ISDIR((*curr_file)->f.st_mode) && (*g_fg & RECURSIVE_FLAG) &&
			!ft_strequ((*curr_file)->name, "..") &&
			!ft_strequ((*curr_file)->name, "."))
	{
		str = ft_pathjoin(dir_name, (*curr_file)->name);
		set_dir(str, &((*dirs)->sub_dirs), (*curr_file)->name, g_fg);
		free(str);
	}
}

static void		file_handler_bis(t_files **files,
		DIR *dir, t_dirs *dirs, struct dirent *sd)
{
	int			format_opt;

	format_opt = INIT_FORMAT;
	while ((sd = readdir(dir)))
	{
		if (*(dirs->g_fg) & HIDE_CURR_AND_PREV_DIRS
				&& !(*(dirs->g_fg) & ALL_FLAG) &&
				(ft_strequ(sd->d_name, ".") || ft_strequ(sd->d_name, "..")))
			continue ;
		if (!(*(dirs->g_fg) & ALL_FLAG) && !(*(dirs->g_fg)
					& HIDE_CURR_AND_PREV_DIRS) && sd->d_name[0] == '.')
			continue ;
		if (!((*files = (t_files *)ft_memalloc(sizeof(t_files)))))
			exit(2);
		if (has_nonprintable_chars(sd->d_name, ft_strlen(sd->d_name)))
		{
			(*files)->display_name = cut_n(sd->d_name, ft_strlen(sd->d_name));
			(*files)->has_nonprintable_chars = 1;
		}
		(*files)->name = ft_strdup(sd->d_name);
		add_file(files, &dirs, format_opt, dirs->g_fg);
		format_opt = UPDATE_FORMAT;
		(*files)->g_fg = (dirs->g_fg);
		files = &((*files)->next);
	}
}

static void		get_file_info(t_files **curr_file,
		t_dirs **dirs, char *file_path, int format_opt)
{
	struct stat		f;

	f = (*curr_file)->f;
	(*curr_file)->cmptime = get_date(&f, (*curr_file)->g_fg);
	file_permission_handler(curr_file, file_path, f);
	(*curr_file)->owner = getpwuid(f.st_uid) ?
		ft_strdup(getpwuid(f.st_uid)->pw_name) :
		ft_strdup("root");
	(*curr_file)->group = getgrgid(f.st_gid) ?
		ft_strdup(getgrgid(f.st_gid)->gr_name) :
		ft_strdup("wheel");
	if (S_ISCHR(f.st_mode) || S_ISBLK(f.st_mode))
	{
		(*curr_file)->is_chr_or_blk = 1;
		(*dirs)->has_chr_or_blk = 1;
	}
	if (S_ISLNK(f.st_mode))
		get_link_file(curr_file, file_path);
	format_handler(&(*dirs)->format, *curr_file, format_opt);
}

void			add_file(t_files **curr_file, t_dirs **dirs,
		int format_opt, t_fg *g_fg)
{
	char	*dir_name;
	char	*file_path;

	dir_name = (*dirs)->path;
	file_path = (*curr_file)->is_dir_info ?
		ft_strdup((*curr_file)->name) :
		ft_pathjoin(dir_name, (*curr_file)->name);
	if (lstat(file_path, &(*curr_file)->f) < 0)
	{
		if (errno == ENOENT)
			(*curr_file)->status = IS_NONEXISTENT;
		else if (errno == EACCES)
			(*curr_file)->status = IS_UNREADABLE;
		return ;
	}
	(*dirs)->has_valid_files = 1;
	if (!((*curr_file)->modes = ft_strnew(11)))
		exit(2);
	(*curr_file)->g_fg = g_fg;
	get_file_info(curr_file, dirs, file_path, format_opt);
	add_file_p(dirs, curr_file, dir_name, g_fg);
	free(file_path);
}

t_files			*file_handler(t_dirs *dirs, t_fg *g_fg)
{
	DIR				*dir;
	t_files			*files;
	struct dirent	*sd;

	if (!(dir = opendir(dirs->path)) || ft_strcmp(dirs->path, "/sgoinfre") == 0)
	{
		dirs->is_unreadable = 1;
		free(dirs->display_name);
		if (!(dirs->display_name = ft_cpath(dirs->path)))
			exit(2);
		return (NULL);
	}
	files = NULL;
	sd = NULL;
	dirs->g_fg = g_fg;
	file_handler_bis(&files, dir, dirs, sd);
	if (dir)
		closedir(dir);
	insert_sort(&files, g_fg);
	return (files);
}
