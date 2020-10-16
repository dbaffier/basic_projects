/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:12:50 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/22 09:42:01 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "execute.h"
#include "ft_printf.h"
#include "utils.h"

static int			is_exec(char *path, struct stat f)
{
	if (f.st_mode & S_IFREG)
	{
		if (f.st_mode & S_IXUSR)
			return (1);
		else
			ft_printf("21sh: permission denied: %s\n", path);
		return (PERM_DENIED);
	}
	return (0);
}

static int			is_dir(char *binary, int f)
{
	struct stat		buf;

	if (f && (stat(binary, &buf) == -1 || S_ISDIR(buf.st_mode)))
	{
		free(binary);
		return (0);
	}
	else if (f == 0 && (stat(binary, &buf) == -1 || S_ISDIR(buf.st_mode)))
		return (0);
	return (1);
}

static int			is_stattable(t_shell *sh)
{
	struct stat		buf;

	if (ft_strchr(sh->argv[0], '/'))
	{
		if (access(sh->argv[0], F_OK) == -1)
		{
			p_err("21sh: ", sh->argv[0], " :no such file or directory", 2);
			return (NO_FILE_DIR);
		}
		if (is_dir(sh->argv[0], 0) == 0)
		{
			p_err("21sh: ", sh->argv[0], " :is a directory", 2);
			return (IS_DIR);
		}
		if (access(sh->argv[0], X_OK) == -1)
		{
			p_err("21sh: ", sh->argv[0], " :permission denied", 2);
			return (PERM_DENIED);
		}
		if (stat(sh->argv[0], &buf) == 0)
			return (is_exec(sh->initial, buf));
	}
	return (0);
}

static int			check_exec(t_shell *sh, char **path)
{
	char			*binary;
	int				i;

	i = -1;
	while (sh->argv[0] && path[++i])
	{
		if (!(binary = ft_strjoin(path[i], sh->argv[0])))
			return (0);
		if (access(binary, F_OK) == 0)
		{
			if (is_dir(binary, 1) == 0)
				return (0);
			if (access(binary, X_OK) == 0)
			{
				free(sh->argv[0]);
				sh->argv[0] = binary;
				return (1);
			}
			p_err("21sh: ", binary, " :permission denied", 2);
			free(binary);
			return (PERM_DENIED);
		}
		free(binary);
	}
	return (IS_NO);
}

int					cmd_exec(t_shell *sh)
{
	char			**path;
	int				ret;

	if (sh->argv == NULL || sh->argc == 0)
		return (1);
	ret = is_stattable(sh);
	if (ret == 1)
		return (ret);
	else if (ret != 0)
		return (ret);
	path = get_env("PATH=", *(sh->env));
	if (path == NULL)
		ret = -1;
	else if (sh->argv[0][0] != '/' && ((ret = check_exec(sh, path))) == 1)
	{
		ft_freetab(&path);
		return (1);
	}
	if (ret == 0)
		;
	else if (ret == -1)
		p_err("21sh: ", sh->initial, " command not found", 2);
	ft_freetab(&path);
	return (NO_FILE_DIR);
}
