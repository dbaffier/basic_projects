/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:34:20 by dbaffier          #+#    #+#             */
/*   Updated: 2019/02/19 14:47:20 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*get_var(char *key, char **env)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!key || !env)
		return (NULL);
	while (env[i])
	{
		tmp = ft_strjoinch(key, '=');
		if (!ft_strncmp(env[i], tmp, ft_strlen(tmp)))
		{
			free(tmp);
			return (ft_strchr(env[i], '=') + 1);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}
