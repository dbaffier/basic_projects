/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:31:23 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/21 16:01:51 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			convert_hexabis(t_flags *flags)
{
	if (!F->CW)
	{
		if (F->CP == 1 && F->P)
		{
			ft_putchar_fd('0', 1);
			return (1);
		}
		return (F->P = 0);
	}
	else
	{
		print_padding(0, F->W, ' ');
		return (F->W);
	}
}

int					convert_hexa(t_flags *flags, va_list *c)
{
	uintmax_t		n;
	int				len;

	n = va_arg(*c, uintmax_t);
	n = get_ulen(flags, n);
	if (n == 0 && F->CP && (F->P == 1 || F->P == 0))
		return (convert_hexabis(flags));
	if (F->CW && F->F0 && n == 0)
		print_padding(1, F->W, '0');
	if (F->SPC == 'x')
		len = ft_putunsign(flags, n, "0123456789abcdef", F->PR ? "0x" : NULL);
	else
		len = ft_putunsign(flags, n, "0123456789ABCDEF", F->PR ? "0X" : NULL);
	return (len);
}
