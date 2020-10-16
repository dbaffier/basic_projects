/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:52:33 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 13:56:26 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding(int start, int end, char c)
{
	if (end - start == 0)
		return ;
	else
		while (start < end)
		{
			ft_putchar_fd(c, 1);
			start++;
		}
}
