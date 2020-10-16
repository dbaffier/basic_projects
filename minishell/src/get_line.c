/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 23:56:13 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/04 20:55:35 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		r_line(char **content)
{
	char	buff[BUFF_SIZE + 1];
	int		n;

	while ((n = read(0, buff, BUFF_SIZE)) >= 0)
	{
		buff[n] = '\0';
		*content = (!*content) ? ft_strdup(buff)
			: ft_strjoinfree(*content, buff, 1);
		if (!*content)
			return (-1);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (1);
}

static int		check_bn(char **tmp, char **line)
{
	char	*tm;
	char	*tm2;

	if (*tmp == NULL)
		return (0);
	tm = ft_strchr(*tmp, '\n');
	if (tm)
	{
		*tm++ = '\0';
		*line = ft_strdup(*tmp);
		tm2 = (*tm) ? ft_strdup(tm) : NULL;
		free(*tmp);
		*tmp = tm2;
		return (1);
	}
	return (0);
}

static int		g_line(char **tmp, char **line)
{
	char	*tm;
	char	*tm2;

	tm = NULL;
	if (tmp)
		tm = ft_strchr(*tmp, '\n');
	if (tm)
	{
		*tm++ = '\0';
		*line = ft_strdup(*tmp);
		tm2 = (*tm) ? ft_strdup(tm) : NULL;
		free(*tmp);
		*tmp = tm2;
		return (1);
	}
	return (0);
}

int				get_line(char **line)
{
	static char		*tmp = NULL;

	if (line == NULL)
		return (-1);
	if (check_bn(&tmp, line))
		return (1);
	if (r_line(&tmp) == -1)
		return (-1);
	g_line(&tmp, line);
	return (1);
}
