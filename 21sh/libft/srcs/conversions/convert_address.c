/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:25:14 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/04 22:10:30 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		handle_zero(t_flags *flags, char *prefix)
{
	int len;

	len = ft_strlen(prefix);
	if (F->CW && !F->CP && !F->F0 && !F->LA)
		print_padding(3, F->W, ' ');
	ft_putstr_fd(prefix, 1);
	if (!F->CP && !F->CW && (len += 1))
		ft_putstr_fd("0", 1);
	if (F->CP && F->P > 2)
		print_padding(0, F->P, '0');
	if (F->CW && F->F0 && (len = len + 1))
	{
		ft_putstr_fd("0", 1);
		print_padding(0, F->W - len, '0');
	}
	else if (F->CW && F->W > len)
		ft_putstr_fd("0", 1);
	if (F->LA && F->CW)
		print_padding(3, F->W, ' ');
	if (F->CW)
		return (ft_max(F->W, len));
	else if (F->CP && F->P > len)
		return (F->P + len);
	else
		return (len);
}

int				convert_address(t_flags *flags, va_list *c)
{
	uintmax_t		n;
	char			*base;

	base = "0123456789abcdef";
	n = va_arg(*c, uintmax_t);
	flags->length = 6;
	n = get_ulen(flags, n);
	if (n == 0)
		return (handle_zero(flags, "0x"));
	if (n || F->CP)
	{
		F->F0 = 0;
		return (ft_putunsign(flags, n, base, "0x"));
	}
	else
	{
		if (F->W && !F->LA)
			print_padding(3, F->W, ' ');
		ft_putstr_fd("0x0", 1);
		if (F->W && F->LA)
			print_padding(3, F->W, ' ');
		F->W = (F->W ? F->W : 3);
		return (F->W);
	}
}
