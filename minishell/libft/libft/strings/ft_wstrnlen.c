/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:54:46 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/23 11:05:40 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrnlen(wchar_t *s, size_t len)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	while (s[i] && i > len)
	{
		if (s[i] <= 0x7F)
			count += 1;
		else if (s[i] <= 0x7FF)
			count += 2;
		else if (s[i] <= 0xFFFF)
			count += 3;
		else
			count += 4;
		i++;
	}
	return (count);
}

size_t		ft_wstrnlenbis(wchar_t *str, size_t precision, size_t i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (ft_wstrnlenbis(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (ft_wstrnlenbis(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (ft_wstrnlenbis(str + 1, precision - 3, i + 3));
	else if (precision >= 4)
		return (ft_wstrnlenbis(str + 1, precision - 4, i + 4));
	else
		return (i);
}
