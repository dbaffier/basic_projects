/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_modulo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:47:38 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 14:01:05 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_modulo(t_flags *flags, va_list *c)
{
	(void)c;
	if (!F->LA && F->CW)
		print_padding(1, F->W, F->F0 ? '0' : ' ');
	ft_putchar_fd('%', 1);
	if (F->CW && F->LA)
		print_padding(1, F->W, ' ');
	return (F->CW ? ft_max(F->W, 1) : 1);
}
