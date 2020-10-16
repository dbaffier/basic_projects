/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 18:44:36 by dbaffier          #+#    #+#             */
/*   Updated: 2018/04/05 12:49:31 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		result;

	result = 0;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (result * sign);
		result = (result * 10) + *str - '0';
		str++;
	}
	return (result * sign);
}
