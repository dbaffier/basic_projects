/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 09:28:27 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/23 08:33:14 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int		ft_getsize(intmax_t n)
{
	if (n < 10 && n > -10)
	{
		if (n < 10 && n >= 0)
			return (1);
		return (2);
	}
	return (ft_getsize(n / 10) + 1);
}

int						handle_prefix(t_flags *flags, intmax_t n, char *prefix)
{
	if (n < 0)
	{
		n = -n;
		prefix = "-";
	}
	else if (F->SG)
		prefix = "+";
	else if (F->SP)
		prefix = " ";
	else
		prefix = "";
	if (n >= -2147483647)
		return (print_prefix(n, flags, prefix, "0123456789"));
	else
		return (print_prefix_max(n, flags, prefix, "0123456789"));
}

int						print_int(intmax_t n, t_flags *flags, int c)
{
	char			*prefix;
	unsigned int	n_len;
	unsigned int	n_strlen;

	prefix = NULL;
	n_len = ft_nbase_len(n, "0123456789");
	n_strlen = ft_nstrlen(flags, n, "0123456789");
	if ((n < 0 || F->SG || F->SP) && (c += 1))
		n_strlen = handle_prefix(flags, n, prefix);
	else if (F->CW && !F->LA && (!F->F0 || F->P))
		print_padding(n_strlen, F->W, ' ');
	if (F->CW && !F->LA && F->CP == 2 && F->P)
		print_padding(n_strlen, F->W + F->P, ' ');
	n = (n < 0 ? -n : n);
	if (F->CW && F->F0 && !F->P)
		print_padding(n_strlen - c, F->W, '0');
	else if (F->CP)
		print_padding(ft_getsize(n), F->P, '0');
	ft_putnbr_max(n);
	if (F->CW && F->LA)
		print_padding(n_strlen - c, F->W, ' ');
	if (F->CW)
		return (ft_max(F->W + c, n_strlen));
	return (n_strlen);
}

static int				ft_hd(t_flags *flags)
{
	if (!F->CW)
	{
		if (F->SG)
		{
			ft_putstr_fd("+", 1);
			return (1);
		}
		else if (!F->SG && F->SP)
		{
			ft_putstr_fd(" ", 1);
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

int						convert_int(t_flags *flags, va_list *c)
{
	intmax_t		n;
	int				len;
	int				a;

	a = 0;
	n = va_arg(*c, intmax_t);
	n = get_len(flags, n);
	len = 0;
	if (n == 0 && F->CP && (F->P == 0 || F->P == 1))
		return (ft_hd(flags));
	len = print_int(n, flags, a);
	return (len);
}
