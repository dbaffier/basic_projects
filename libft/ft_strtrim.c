/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:09:03 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/06 18:14:16 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;

	start = 0;
	if (!s)
		return (NULL);
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (s[start] == '\0')
		return (ft_strdup(s + start));
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t') && end > 0)
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
