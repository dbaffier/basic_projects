/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:40:26 by dbaffier          #+#    #+#             */
/*   Updated: 2019/01/16 23:07:44 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				**get_env(char *path, char **envp)
{
	int		i;
	int		j;
	char	**p;
	char	*tmp;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], path, ft_strlen(path)))
		{
			p = ft_strsplit(envp[i] + 5, ':');
			j = -1;
			while (p[++j])
			{
				tmp = p[j];
				p[j] = ft_strjoinch(tmp, '/');
				free(tmp);
			}
			return (p);
		}
	}
	return (NULL);
}
