/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 11:00:52 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 13:59:17 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_char(t_flags *flags, char c)
{
	if (!F->LA && !F->F0 && F->CW)
		print_padding(1, F->W, ' ');
	else if (F->CW && F->F0)
		print_padding(1, F->W, '0');
	ft_putchar_fd(c, 1);
	if (F->CW && F->LA)
		print_padding(1, F->W, ' ');
}

int			convert_char(t_flags *flags, va_list *c)
{
	char	to_print;

	if (F->LEN == 3)
		return (convert_wchar(flags, c));
	to_print = va_arg(*c, int);
	print_char(flags, to_print);
	if (F->W)
		return (F->W);
	return (1);
}
