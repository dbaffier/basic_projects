/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:29:41 by dbaffier          #+#    #+#             */
/*   Updated: 2018/06/18 14:00:56 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_long(t_flags *flags, va_list *c)
{
	F->LEN = 3;
	if (F->SPC == 'D')
		return (convert_int(flags, c));
	else if (F->SPC == 'O')
		return (convert_octal(flags, c));
	else if (F->SPC == 'U')
		return (convert_unsign(flags, c));
	else
		return (-1);
}
