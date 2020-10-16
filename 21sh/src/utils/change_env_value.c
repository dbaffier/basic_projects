/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:43:40 by tsisadag          #+#    #+#             */
/*   Updated: 2019/02/21 19:11:29 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find_char(char *s, char c)
{
	int i;

	i = 0;
	if (!s[0])
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int		ft_find_last_char(char *s, char c)
{
	int len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == c)
			return (len);
		len--;
	}
	return (-1);
}
