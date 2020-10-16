/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:30:27 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/14 09:20:17 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char *str, char *term, char *replace_by)
{
	int		i;
	char	*new_path;
	int		done;

	if (!ft_strstr(str, term))
		return (NULL);
	new_path = ft_strnew(1);
	i = -1;
	done = 0;
	while (str[++i])
	{
		if (ft_startstr(str + i, term) && !done)
		{
			new_path = ft_strjoinfree(new_path, replace_by, 1);
			i += ft_strlen(term);
			if (!str[i])
				break ;
			new_path = ft_strjoinchcl(new_path, str[i]);
			done = 1;
		}
		else
			new_path = ft_strjoinchcl(new_path, str[i]);
	}
	free(str);
	return (new_path);
}
