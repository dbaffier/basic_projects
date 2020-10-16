/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:28:26 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/22 17:02:30 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "prompt.h"
#include "execute.h"

char	**is_heredoc(char **line)
{
	char	**h_tab;
	int		i;
	int		count;

	i = 0;
	if ((count = count_hdoc_ws(line[0])) > 0)
		line[0] = split_hdoc(line[0], count, 0, 0);
	if ((h_tab = ft_split_whitespaces(line[0], 0)))
	{
		while (h_tab[i] && i != 4095)
		{
			if (!ft_strcmp(h_tab[i], "<<") && h_tab[i + 1])
			{
				ft_freetab(&line);
				return (here_doc(h_tab, 0));
			}
			i++;
		}
		ft_freetab(&h_tab);
	}
	return (line);
}

char	**here_doc(char **h_tab, int d)
{
	char		**delim;
	int			i;
	char		*here_tab_z;

	i = 0;
	delim = NULL;
	if (!(delim = ft_memalloc(sizeof(char **) * (4096))))
		return (0);
	here_tab_z = ft_strnew(1);
	while (h_tab[i])
	{
		if (i && h_tab[i - 1] && !ft_strcmp(h_tab[i - 1], "<<"))
		{
			delim[d + 1] = NULL;
			delim[d] = ft_strdup(h_tab[i]);
			d++;
		}
		if (ft_strlen(here_tab_z))
			here_tab_z = ft_strjoinfree(here_tab_z, " ", 1);
		here_tab_z = ft_strjoinfree(here_tab_z, h_tab[i], 1);
		i++;
	}
	delim[d] = NULL;
	ft_freetab(&h_tab);
	return (get_here_tab(here_tab_z, delim, 0, 1));
}

int		check_ret_conditions(char s, char **here_tab, char *delim[4096])
{
	if (s == '\x3')
	{
		ft_putstr("\n");
		ft_freetab(&here_tab);
		ft_freetab(&delim);
		return (1);
	}
	if (s == '\x4')
		return (2);
	return (0);
}

void	get_hdoc_line(char *delim, char **here_tab_i, char *next_line)
{
	if (ft_strcmp(next_line, delim) && ft_strcmp(next_line, "<<"))
	{
		if (ft_strlen(*here_tab_i))
		{
			*here_tab_i = ft_strjoinfree(*here_tab_i, "\n", 1);
			*here_tab_i = ft_strjoinfree(*here_tab_i, next_line, 1);
		}
		else
			*here_tab_i = ft_strdup(next_line);
	}
}

char	**get_here_tab(char *here_tab_z, char *delim[4096], int d, int i)
{
	char		*next_line;
	char		**here_tab;
	int			ret;

	here_tab = alloc_here_tab(here_tab_z);
	while (delim[d])
	{
		h_prompt();
		next_line = get_line_hq(3, 3, 0);
		if ((ret = check_ret_conditions(next_line[0], here_tab, delim)) == 1)
			return (NULL);
		else if (ret == 2)
			break ;
		get_hdoc_line(delim[d], &(here_tab[i]), next_line);
		if (next_line[0] && !ft_strcmp(next_line, delim[d]))
		{
			here_tab[i] = ft_strjoinfree(here_tab[i], "\n", 1);
			i++;
			d++;
		}
		ft_strdel(&next_line);
	}
	here_tab[i] = ft_strjoinfree(here_tab[i], "\n", 1);
	ft_freetab(&delim);
	return (here_tab);
}
