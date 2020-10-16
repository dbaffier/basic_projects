/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:58:47 by dbaffier          #+#    #+#             */
/*   Updated: 2018/07/01 11:23:41 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_binary(t_flags *flags, va_list *c)
{
	uintmax_t	n;

	n = va_arg(*c, unsigned int);
	n = get_ulen(flags, n);
	return (ft_putunsign(flags, n, "01", "0b"));
}
