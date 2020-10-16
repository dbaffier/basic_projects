/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:18:09 by dbaffier          #+#    #+#             */
/*   Updated: 2018/09/16 23:15:48 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char *str, int len)
{
	int		i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}
