/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 17:06:07 by dbaffier          #+#    #+#             */
/*   Updated: 2018/10/29 10:37:22 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				is_quote(int c)
{
	return (c == '"' || c == '\'');
}

char			*get_var(char *key, char **env)
{
	char	*tmp;
	int		i;

	i = 0;
	while (env[i])
	{
		tmp = ft_strjoinch(key, '=');
		if (!ft_strncmp(env[i], tmp, ft_strlen(tmp) - 1))
		{
			free(tmp);
			return (ft_strchr(env[i], '=') + 1);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

char			**clone(char **envp)
{
	char	**clone;
	int		i;

	i = 0;
	while (envp[i])
		i++;
	clone = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		clone[i] = ft_strdup(envp[i]);
		i++;
	}
	clone[i] = NULL;
	return (clone);
}

char			**check_line(void)
{
	char	*line;
	char	**parsed_line;

	if ((get_line(&line) == -1))
		return (NULL);
	if (!(parsed_line = ft_strsplit(line, ';')))
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (parsed_line);
}
