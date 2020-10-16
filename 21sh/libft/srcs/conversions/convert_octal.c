/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 09:22:25 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 14:04:50 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_octal(t_flags *flags, va_list *c)
{
	uintmax_t		n;

	n = va_arg(*c, uintmax_t);
	n = get_ulen(flags, n);
	if (n == 0 && F->CP && !F->PR && (F->P == 1 || F->P == 0))
	{
		if (!F->CW)
			return (F->P = 0);
		else
		{
			print_padding(0, F->W, ' ');
			return (F->W);
		}
	}
	if (F->CP == 1 && !F->PR)
		return (ft_putunsign(flags, n, "01234567", NULL));
	else
	{
		if (F->CW && F->F0 && n == 0)
			print_padding(1, F->W, '0');
		return (ft_putunsign(flags, n, "01234567", "0"));
	}
}
