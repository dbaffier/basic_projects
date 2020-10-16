/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 08:59:03 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/23 10:39:02 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		wchar_len(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 1114111)
		return (4);
	else
		return (-1);
}

void			print_wchar(t_flags *flags, wchar_t c)
{
	if (!F->LA && !F->F0 && F->CW)
		print_padding(1, F->W, ' ');
	else if (F->CW && F->F0)
		print_padding(1, F->W, '0');
	ft_putwchar(c);
	if (F->CW && F->LA)
		print_padding(1, F->W, ' ');
}

int				convert_wchar(t_flags *flags, va_list *c)
{
	wchar_t		to_print;

	to_print = (wchar_t)va_arg(*c, wint_t);
	print_wchar(flags, to_print);
	if (wchar_len(to_print) == -1)
		return (-1);
	if (F->W >= wchar_len(to_print))
		return (F->W);
	else
		return (wchar_len(to_print));
}
