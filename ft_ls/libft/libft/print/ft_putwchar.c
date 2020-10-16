/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:56:24 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/23 10:07:38 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar(wchar_t c)
{
	if (c <= 127)
		ft_putchar_fd(c, 1);
	else if (c <= 2047)
	{
		ft_putchar_fd((c >> 6) | 0xC0, 1);
		ft_putchar_fd((c & 0x3F) | 0x80, 1);
	}
	else if (c <= 65535)
	{
		ft_putchar_fd((c >> 12) | 0xE0, 1);
		ft_putchar_fd(((c >> 6) & 0x3F) | 0x80, 1);
		ft_putchar_fd((c & 0x3F) | 0x80, 1);
	}
	else
	{
		ft_putchar_fd((c >> 18) | 0xF0, 1);
		ft_putchar_fd(((c >> 12) & 0x3F) | 0x80, 1);
		ft_putchar_fd(((c >> 6) & 0x3F) | 0x80, 1);
		ft_putchar_fd((c & 0x3F) | 0x80, 1);
	}
}
