/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 09:48:24 by dbaffier          #+#    #+#             */
/*   Updated: 2018/11/04 22:12:16 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_putwnstrbis(wchar_t *str, size_t len)
{
	size_t		i;

	i = 0;
	while (*str && i < len)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else
			i += 4;
		if (i <= len)
			ft_putwchar(*str++);
	}
}

int					print_wstring(t_flags *flags, wchar_t *str)
{
	size_t	len;

	len = F->CP ? ft_wstrnlenbis(str, F->P, 0) : ft_wstrlen(str);
	if (F->CW && !F->LA)
		print_padding(len, F->W, F->F0 ? '0' : ' ');
	if (F->F0 && F->CP)
		print_padding(0, 1, '0');
	if ((F->W > F->P || F->P == 0) && F->CP != 2)
		ft_putwnstrbis(str, len);
	else if (!F->CW)
		ft_putwnstrbis(str, len);
	else if (F->CW < F->P)
		ft_putwnstrbis(str, len);
	if (F->CW && F->LA)
		print_padding(len, F->W, ' ');
	return (F->W ? ft_max(F->W, len) : len);
}

int					convert_wstring(t_flags *flags, va_list *str)
{
	wchar_t		*to_p;

	to_p = (wchar_t *)va_arg(*str, wint_t *);
	if (to_p != NULL)
		return (print_wstring(flags, to_p));
	else if (F->W == 2)
	{
		print_padding(0, F->W, '0');
		return (F->W);
	}
	else
	{
		ft_putstr(NULL);
		return (6);
	}
}
