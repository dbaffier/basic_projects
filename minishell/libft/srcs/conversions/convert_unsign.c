/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:32:46 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 14:04:57 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_unsign(t_flags *flags, va_list *c)
{
	uintmax_t	n;
	int			len;

	len = 0;
	n = va_arg(*c, uintmax_t);
	n = get_ulen(flags, n);
	if (n == 0 && F->CP && (F->P == 1 || F->P == 0))
		return (F->P = 0);
	if (F->CW && !F->LA && n == 0 && F->SPC == 'U')
		print_padding(1, F->W, '0');
	len += ft_putunsign(flags, n, "0123456789", NULL);
	return (len);
}
