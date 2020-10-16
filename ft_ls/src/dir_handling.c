/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:55:58 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/19 00:46:40 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			ini_dir(t_dirs **dir,
		t_lol *lol, char *path, char *subdir_name)
{
	struct stat		f;

	if (lol->status != IS_NONEXISTENT)
	{
		lstat((*dir)->path, &f);
		if (!(((*dir)->self->display_name = ft_strdup(path))))
			exit(2);
		(*dir)->self->is_dir_info = 1;
		if (subdir_name)
		{
			if (!((*dir)->display_name = ft_strdup(subdir_name)))
				exit(2);
		}
		(*dir)->cmptime = get_date(&f, lol->g_fg);
	}
	(*dir)->status = lol->status;
	(*dir)->is_unreadable = 0;
	(*dir)->total_blocks = 0;
	(*dir)->file_count = 0;
	(*dir)->has_valid_files = 0;
	(*dir)->next = NULL;
	(*dir)->prev = NULL;
}

static t_dirs		*new_dir(char *path,
		t_lol *lol, int is_default, char *subdir_name)
{
	t_dirs		*dir;
	DIR			*dr;

	if (!(dir = (t_dirs *)ft_memalloc(sizeof(t_dirs))))
		exit(2);
	if (!(dir->path = ft_strdup(path)))
		exit(2);
	if (!(dir->self = (t_files *)ft_memalloc(sizeof(t_files))))
		exit(2);
	if (!(dir->self->name = ft_strdup(path)))
		exit(2);
	if (lol->status == IS_LINK)
	{
		if (!(dr = opendir(dir->path)))
			lol->status = IS_NOTDIR;
		else
			lol->status = IS_DIR;
		if (dr)
			closedir(dr);
	}
	dir->is_default = is_default;
	ini_dir(&dir, lol, path, subdir_name);
	return (dir);
}

static void			add_dir(t_dirs **head, t_dirs *new)
{
	t_dirs		*curr;
	t_dirs		*tmp;

	curr = *head;
	tmp = curr;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
	new->prev = curr;
	*head = tmp;
}

void				set_dir(char *path, t_dirs **dirs,
		char *subdir_name, t_fg *g_fg)
{
	t_dirs			*new;
	t_lol			lol;
	struct stat		f;

	lol.status = IS_DIR;
	lol.g_fg = g_fg;
	if (lstat(path, &f) == -1)
	{
		if (ENOENT == errno)
			lol.status = IS_NONEXISTENT;
	}
	else if (!S_ISDIR(f.st_mode))
		lol.status = IS_NOTDIR;
	else if (S_ISLNK(f.st_mode))
		lol.status = IS_LINK;
	new = new_dir(path, &lol, 0, subdir_name);
	if (!*dirs || (*dirs)->is_default)
	{
		free_dirs_bis(*dirs);
		*dirs = new;
	}
	else
		add_dir(dirs, new);
}

t_dirs				*dir_handler(char **av, t_fg *g_fg)
{
	int			i;
	char		*str;
	t_dirs		*dir;
	t_lol		lol;

	i = 0;
	lol.status = IS_DIR;
	lol.g_fg = g_fg;
	dir = new_dir(".", &lol, 1, 0);
	if (!av[i])
		set_dir(".", &dir, NULL, g_fg);
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			if (!(str = ft_strdup("fts_open")))
				exit(2);
			err_h(NONEXISTENT_ERR, str);
			exit(1);
		}
		set_dir(av[i], &dir, NULL, g_fg);
		i++;
	}
	dir = dirs_sort(dir, g_fg);
	return (dir);
}
