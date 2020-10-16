/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:14:28 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/23 10:07:47 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		handle_null(t_flags *flags)
{
	static char	tab[6] = "(null)";
	int			i;

	i = 0;
	if (F->CW && !F->LA && F->W > 6)
		print_padding(6, F->W, ' ');
	if (F->CP && F->P < 6)
		while (i < F->P)
			ft_putchar_fd(tab[i++], 1);
	else
		write(1, "(null)", 6);
	if (F->LA && F->CW && F->W > 6)
		print_padding(6, F->W, ' ');
}

int				print_string(t_flags *flags, char *str)
{
	int		len;

	len = F->CP ? ft_strnlen(str, F->P) : ft_strlen(str);
	if (F->CW && !F->LA)
		print_padding(len, F->W, F->F0 ? '0' : ' ');
	ft_putnstr(str, len);
	if (F->CW && F->LA)
		print_padding(len, F->W, ' ');
	return (F->CW ? ft_max(F->W, len) : len);
}

int				convert_string(t_flags *flags, va_list *str)
{
	char	*to_p;

	if (F->LEN == 3)
		return (convert_wstring(flags, str));
	to_p = va_arg(*str, char *);
	if (to_p != NULL)
		return (print_string(flags, to_p));
	else if (F->CP == 2)
	{
		if (!F->LA)
			print_padding(0, F->W, '0');
		else if (F->LA)
			print_padding(0, F->W, ' ');
		return (F->W);
	}
	else
	{
		handle_null(flags);
		if (F->CP && F->P)
			return (F->P);
		if (F->CW)
			return (ft_max(6, F->W));
		return (6);
	}
}
